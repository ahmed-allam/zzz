#include "global.h"

#include <QWaitCondition>
#include <QMutex>

QWaitCondition updateTable_waiting;
QWaitCondition plotGraph_waiting;
QMutex mutex;
QWaitCondition resumeThread;