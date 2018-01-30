#ifndef SIMULATOR_H
#define SIMULATOR_H

#include <QtWidgets/QMainWindow>
#include "ui_simulator.h"

class Simulator : public QMainWindow
{
	Q_OBJECT

public:
	Simulator(QWidget *parent = 0);
	~Simulator();

private:
	Ui::SimulatorClass ui;
};

#endif // SIMULATOR_H
