#include "simulator.h"
#include <QtWidgets/QApplication>
#include "ctrl/ctrlled.h"
#include "ctrl/moduleprase.h"


int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
#if 0
	CtrlLED led;
	led.dllInit();
    //led.TestFunc();
	led.SetCardPara("192.168.17.199",64,16,"BX6Q1",4);
	T_AREA area = { 0, 0, 32, 15 };
	T_FONT font = { "ËÎÌו", 10, 0, 65535 };
	led.Disp(0, area, font,"12345512",1);
	led.Send();
#endif
	//
	ModulePrase mod;
	mod.checkFloder("./module");

	Simulator w;
	w.show();
	return a.exec();
}
