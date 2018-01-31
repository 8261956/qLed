#include "ctrlled.h"
#include <QDebug>
#include <QLibrary>
#include "Windows.h"

#include <iostream>
#include <string>
#include <sstream>

#include "windows.h"
#include <stdio.h>


CtrlLED::CtrlLED(QObject *parent) :
    QObject(parent)
{

}

char * String2Char(QString str)
{
	char * strMem = (char *)malloc(str.size() + 10);
	QByteArray dome2 = str.toLocal8Bit();
	strcpy(strMem, dome2.data());
	return strMem;
}

void CtrlLED::dllInit()
{
	// DLL显式加载，只需要DLL文件即可，不需要.H和.LIB文件
	// 需要将DLL放到可执行目录中

	//QString s = "./dll";
	//LPCWSTR path = s.toStdWString().c_str();
	//SetDllDirectory(L".\\dll\\");

	mLib = new QLibrary("BX_IV.dll");
	if (mLib->load()) {
		qDebug() << "load ok!";

		Initialize = (pInitialize)mLib->resolve("Initialize");
		Uninitialize = (pUninitialize)mLib->resolve("Uninitialize");
		AddScreen = (pAddScreen)mLib->resolve("AddScreen");
		SendScreenInfo = (pSendScreenInfo)mLib->resolve("SendScreenInfo");
		AddScreenProgram = (pAddScreenProgram)mLib->resolve("AddScreenProgram");
		DeleteScreenProgram = (pDeleteScreenProgram)mLib->resolve("DeleteScreenProgram");
		AddScreenProgramBmpTextArea = (pAddScreenProgramBmpTextArea)mLib->resolve("AddScreenProgramBmpTextArea");
		AddScreenProgramAreaBmpTextText = (pAddScreenProgramAreaBmpTextText)mLib->resolve("AddScreenProgramAreaBmpTextText");
	}
	else{
		qDebug() << "load error!";
		qDebug() << mLib->errorString();
	}
}

void CtrlLED::SetCardPara(QString cardIP,int width,int height,QString cardName,int screenColorType)
{
	mCardIP = cardIP;
	mWidth = width;
	mHeight = height;
	mCardName = cardName;
	mScreenColorType = screenColorType;

	if (Initialize) {
		qDebug() << "Initialize hello ok!";
		int nResult = Initialize(NULL, NULL);//初始化
		qDebug() << "Initialize Result : " << nResult;

		char * ipStr = (char *)String2Char(cardIP);
		qDebug() << "ipStr : " << ipStr;
		qDebug() << "cardIp : " << cardIP;

		//添加屏幕，参数值和ＴＷ软件设置的参数一致，这里是５Ｅ３，网络通讯，固定ＩＰ１９２.２６８.１０.１２３，１２８×３２，双基色，Ｒ＋Ｇ，低有效，负极性，其它默认的参数
		nResult = AddScreen(0x0166, 1, 2, width, height, screenColorType, 1, 0, 0, 0, 0, 0, "COM1", 57600, ipStr, 5005, 0, 0, "", "",
			"", 0, "", "", "172.168.0.1", 5005, "", 5005, "", "ScreenStatus.ini");

		qDebug() << "AddScreen Result " << nResult;

		//设置屏参，可省略
		nResult = SendScreenInfo(1, 41471, 0);
		qDebug() << "SendScreenInfo Result " << nResult;

		//添加节目0，可添加多个节目，动态库自动为节目添加序号，从0开始，添加删除会自动自增和递进
		//屏幕号设置成1
		nResult = AddScreenProgram(1, 0, 0, 65535, 11, 26, 2011, 11, 26, 1, 1, 1, 1, 1, 1, 1, 0, 0, 23, 59);
		qDebug() << "AddScreenProgram Result " << nResult;


	}
}

void CtrlLED::Disp(int id,T_AREA area, T_FONT font, QString text, int nStunt)
{
	char * fontName = String2Char(font.name);
	char * cText = String2Char(text);

	//添加图文区区域0，区域序号同节目序号
	int nResult = AddScreenProgramBmpTextArea(1, 0, area.x,area.y,area.width,area.height);
	qDebug() << "AddScreenProgramBmpTextArea Result " << nResult;

	//检验没有做

	//添加文本0，同节目序号
	nResult = AddScreenProgramAreaBmpTextText(1,0,id, cText, 1, 0, 0, fontName, font.size,font.bold, 0, 0, font.color, nStunt, 10, 10, 0, 0);
	qDebug() << "AddScreenProgramAreaBmpTextText1 Result " << nResult;

}

void CtrlLED::Send()
{
	//发送所有节目信息
	int nResult = SendScreenInfo(1, 41456, 0);
	qDebug() << "SendScreenInfo  41456 Result " << nResult;

	//释放动态库
	nResult = Uninitialize();
	qDebug() << "Uninitialize  Result " << nResult;


}


void CtrlLED::TestFunc()
{
    if (Initialize) {
        qDebug() << "Initialize hello ok!";
        int nResult = Initialize(NULL,NULL);//初始化
        qDebug() <<"Initialize Result : " << nResult;

        //添加屏幕，参数值和ＴＷ软件设置的参数一致，这里是５Ｅ３，网络通讯，固定ＩＰ１９２.２６８.１０.１２３，１２８×３２，双基色，Ｒ＋Ｇ，低有效，负极性，其它默认的参数
        nResult = AddScreen(0x0166, 1,2,64, 16, 4, 1, 0,0, 0, 0, 0,"COM1", 57600,"192.168.17.199", 5005,0, 0, "", "",
            "", 0, "", "","172.168.0.1", 5005, "", 5005, "", "ScreenStatus.ini");

        qDebug() << "AddScreen Result "<< nResult;

        //设置屏参，可省略
        nResult = SendScreenInfo(1, 41471, 0);
        qDebug() << "SendScreenInfo Result "<< nResult;

        //添加节目0，可添加多个节目，动态库自动为节目添加序号，从0开始，添加删除会自动自增和递进
        nResult = AddScreenProgram(1, 0, 0, 65535, 11, 26, 2011, 11, 26, 1, 1, 1, 1, 1, 1, 1, 0, 0, 23, 59);
        qDebug() << "AddScreenProgram Result "<< nResult;

        nResult = AddScreenProgram(1, 0, 0, 65535, 11, 26, 2011, 11, 26, 1, 1, 1, 1, 1, 1, 1, 0, 0, 23, 59);
        qDebug() << "AddScreenProgram Result "<< nResult;

        //添加图文区区域0，区域序号同节目序号
        nResult = AddScreenProgramBmpTextArea(1, 0, 0, 0, 32, 16);
        qDebug() << "AddScreenProgramBmpTextArea Result "<< nResult;

        //添加文本0，同节目序号
        nResult = AddScreenProgramAreaBmpTextText(1, 0, 0, "123456789", 1, 0,0, "宋体", 10, 0,0,0, 65535, 3, 10, 10,0,0);
        qDebug()<< "AddScreenProgramAreaBmpTextText1 Result " << nResult;

        nResult = AddScreenProgramBmpTextArea(1,0,32,0,32,16);
        qDebug() <<"AddScreenProgramBmpTextArea2 Resul t"<<nResult;

        nResult = AddScreenProgramAreaBmpTextText(1, 0, 1, "987654321", 1, 0,0, "宋体", 10, 0,0,0, 65280, 0x025, 10, 10,0,0);
        qDebug()<<"AddScreenProgramAreaBmpTextText2 Result "<<nResult;

        //发送所有节目信息
        nResult = SendScreenInfo(1, 41456, 0);
        qDebug()<<"SendScreenInfo  41456 Result "<<nResult;

        //释放动态库
        nResult = Uninitialize();
        qDebug()<<"Uninitialize  Result "<<nResult;
    }
}

