#include "simulator.h"
#include <QtWidgets/QApplication>
#include "ctrl/ctrlled.h"
#include "ctrl/moduleprase.h"

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);

	CtrlLED led;
	led.dllInit();
	led.SetCardPara("192.168.17.199",64,16,"BX6Q1",4);
	ModulePrase mod;
	mod.checkFloder("./module");

	Simulator w;
	w.show();
	return a.exec();
}
