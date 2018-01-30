#include "moduleprase.h"
#include <QMessageBox>
#include <QDebug>

#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>

ModulePrase::ModulePrase(QObject *parent)
	: QObject(parent)
{

}

void ModulePrase::checkFloder(QString flodPath)
{
	int i = 0;
	mFileCnt = 0;
	QDir dir(flodPath);
	if (!dir.exists()){
		QMessageBox(QMessageBox::NoIcon, "Error", "Dir not exist!");
		return;
	}
	dir.setFilter(QDir::Files);//|QDir::Dirs
	dir.setSorting(QDir::Name);
	QFileInfoList list = dir.entryInfoList();
	do{
		QFileInfo fileInfo = list.at(i);
		if (fileInfo.fileName() == "." | fileInfo.fileName() == ".."){
			i++;//当前文件夹和上一层文件夹
			continue;
		}
		if (fileInfo.fileName().endsWith(".json")){
			//found json file
			checkFile(mFileCnt, fileInfo.fileName(), fileInfo.filePath());
			mFileCnt++;
		}
		i++;
	} while (i<list.size());
}

QJsonDocument loadJson(QString fileName, QJsonParseError *error = Q_NULLPTR) {
	QFile jsonFile(fileName);
	jsonFile.open(QFile::ReadOnly);
	QByteArray content = jsonFile.readAll();
	qDebug() << content;
	return QJsonDocument().fromJson(content,error);
}

void saveJson(QJsonDocument document, QString fileName) {
	QFile jsonFile(fileName);
	jsonFile.open(QFile::WriteOnly);
	jsonFile.write(document.toJson());
}

void ModulePrase::checkFile(unsigned int idx, QString fileName, QString filePath)
{
	qDebug() << "find json file idx : " << idx << " name: " << fileName << " path: " << filePath;

	QJsonParseError jsonParseError;
	QJsonDocument document = loadJson(filePath, &jsonParseError);
	if (jsonParseError.error == QJsonParseError::NoError) {
		//isObject()来判断是否包含一个数组或对象
		if (document.isObject()) {
			QJsonObject jsonObj = document.object();
			if (jsonObj.contains("devInfo")) {
				QJsonObject devInfo = jsonObj["devInfo"].toObject();
				QString ip = devInfo["ip"].toString();
				int width = devInfo["width"].toInt();
				int height = devInfo["height"].toInt();
				QString card = devInfo["card"].toString();
				int screenColorType = devInfo["screenColorType"].toInt();
				QJsonArray cList = jsonObj["contentList"].toArray();
				CtrlLED * ctrl;

				qDebug() << "Find devConfig : " << ip;


				if (!manager.contains(ip)){
					qDebug() << "new dev: " << devInfo["ip"].toString();

					ctrl = new CtrlLED;
					ctrl->dllInit();
					ctrl->SetCardPara(ip, width, height, card, screenColorType);
					manager.insert(ip, ctrl);
				}
				else{
					qDebug() << "Exist dev: " << devInfo["ip"].toString();
					ctrl = manager[ip];
				}

				checkContent(ctrl, cList);
			}
		}
	}
	else {
		qDebug() << "parseJsonStr: jsonParseError(" << jsonParseError.error << ")" << jsonParseError.errorString();
	}

}

void ModulePrase::checkContent(CtrlLED * ctrl, QJsonArray cList)
{
	foreach(QJsonValue item, cList){
		QJsonObject content = item.toObject();
		QString depName = content["department"].toString();
		QString id = content["id"].toInt();
		QString type = content["type"].toString();
		
		T_AREA area;
		QJsonObject jArea = content["area"].toObject();
		area.x = jArea["x"].toInt();
		area.y = jArea["y"].toInt();
		area.width = jArea["width"].toInt();
		area.height = jArea["height"].toInt();

		T_FONT font;
		QJsonObject jFont = content["font"].toObject();
		font.name = jFont["name"].toString();
		font.size = jFont["size"].toInt();
		font.bold = jFont["size"].toInt();
		font.color = jFont["color"].toInt();

		QString text = checkText(content["text"].toString(),content["para"].toArray());
		int nStunt = content["nStunt"].toInt();
		
		ctrl->Disp(area, font, text, nStunt);
		qDebug() << "Disp area: " << area.x << " " <<area.y << " " << area.width <<" "<< area.height <<" : "<<text;
	}
}

QString ModulePrase::checkText(QString text,QJsonArray pList)
{
	foreach(QJsonValue item, pList)
	{
		QString para = item.toString();
		QStringList partList = para.split("->");
		QStringList valList;
		QString path = partList.first();
		qDebug() << "para : " << para;
		qDebug() << "para json file : " << path;

		QJsonParseError jsonParseError;
		QJsonDocument document = loadJson(path, &jsonParseError);
		if (jsonParseError.error == QJsonParseError::NoError) {
			//isObject()来判断是否包含一个数组或对象
			if (document.isObject()) {
				qDebug() << "found para json file";

				QJsonObject jsonObj = document.object();
				QJsonValue val;
				
				partList.pop_front();
				foreach(QString part, partList)
				{
					if (jsonObj.contains(part)){
						val = jsonObj[part];
						jsonObj = jsonObj[part].toObject;
					}
					else{
						qWarning() << " part lost! file : " << path << " part: " <<part;
					}
				}
				valList.append(val.toString());
				qDebug() << "found para : " << val.toString();
			}
		}
		else {
			qWarning() << "parseJsonStr: jsonParseError(" << jsonParseError.error << ")" << jsonParseError.errorString();
		}

	}
	text.sprintf(text.toStdString().c_str(), valList);
	return text;
}

ModulePrase::~ModulePrase()
{

}
