#include "2_3_signals_and_slots_with_events.h"

#include <QCoreApplication>
#include <QTimer>

int main(int argc, char *argv[]) {
    QCoreApplication app(argc, argv);
    QTimer timer;
    Worker worker;
    QObject::connect(&timer, &QTimer::timeout, &worker, &Worker::process);
    QObject::connect(&worker, &Worker::finished, &app, &QCoreApplication::quit);
    timer.start(1000);
    return app.exec();
} 