#pragma once
//#include <QtWidgets/QApplication>
#include <QWaitCondition>
#include <QMutex>

//these are only declarations,these are defined in global.cpp
extern QWaitCondition plotGraph_waiting;
extern QMutex mutex;
extern QWaitCondition resumeThread;

//8-10-2022
extern QWaitCondition updateTable_waiting;
