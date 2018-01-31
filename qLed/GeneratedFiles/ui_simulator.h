/********************************************************************************
** Form generated from reading UI file 'simulator.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SIMULATOR_H
#define UI_SIMULATOR_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SimulatorClass
{
public:
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QWidget *centralWidget;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *SimulatorClass)
    {
        if (SimulatorClass->objectName().isEmpty())
            SimulatorClass->setObjectName(QStringLiteral("SimulatorClass"));
        SimulatorClass->resize(600, 400);
        menuBar = new QMenuBar(SimulatorClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        SimulatorClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(SimulatorClass);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        SimulatorClass->addToolBar(mainToolBar);
        centralWidget = new QWidget(SimulatorClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        SimulatorClass->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(SimulatorClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        SimulatorClass->setStatusBar(statusBar);

        retranslateUi(SimulatorClass);

        QMetaObject::connectSlotsByName(SimulatorClass);
    } // setupUi

    void retranslateUi(QMainWindow *SimulatorClass)
    {
        SimulatorClass->setWindowTitle(QApplication::translate("SimulatorClass", "Simulator", 0));
    } // retranslateUi

};

namespace Ui {
    class SimulatorClass: public Ui_SimulatorClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SIMULATOR_H
