#ifndef CTRLLED_H
#define CTRLLED_H

#include <QObject>
#include <QLibrary>
#include "ctrl/ledDll.h"


typedef struct{
	int x;
	int y;
	int width;
	int height;
}T_AREA;

typedef struct{
	QString name;
	int size;
	int bold;
	int color;
}T_FONT;

class CtrlLED : public QObject
{
    Q_OBJECT


public:
    explicit CtrlLED(QObject *parent = 0);

	void dllInit();
	void TestFunc();
	void Disp(T_AREA area, T_FONT font, QString text, int nStunt);
	void SetCardPara(QString cardIP, int width, int height, QString cardName, int screenColorType);
	

signals:

public slots:

protected:
	pInitialize Initialize;
	pUninitialize Uninitialize;
	pAddScreen AddScreen;
	pSendScreenInfo SendScreenInfo;
	pAddScreenProgram AddScreenProgram;
	pDeleteScreenProgram DeleteScreenProgram;
	pAddScreenProgramBmpTextArea AddScreenProgramBmpTextArea;
	pAddScreenProgramAreaBmpTextText AddScreenProgramAreaBmpTextText;

	QLibrary *mLib;
	QString mCardIP;
	int mWidth;
	int mHeight;
	QString mCardName;
	int mScreenColorType;

};


#endif // CTRLLED_H
