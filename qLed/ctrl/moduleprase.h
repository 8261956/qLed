#ifndef MODULEPRASE_H
#define MODULEPRASE_H

#include <QObject>
#include <QFileDialog>
#include <QMap>
#include "ctrlled.h"

class ModulePrase : public QObject
{
	Q_OBJECT

public:
	explicit ModulePrase(QObject *parent = 0);
    ~ModulePrase();
	void checkFloder(QString flodPath);
	void checkFile(unsigned int idx, QString fileName, QString filePath);
	void checkContent(CtrlLED * ctrl, QJsonArray cList);
	QString checkText(QString text, QJsonArray pList);

private:
	int mFileCnt;
	QMap<QString, CtrlLED *> manager;
};

#endif // MODULEPRASE_H
