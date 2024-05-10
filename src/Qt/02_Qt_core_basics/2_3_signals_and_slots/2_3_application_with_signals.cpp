#include "2_3_application_with_signals.h"
#include <QCoreApplication>

int main(int argc, char *argv[]) {
    QCoreApplication app(argc, argv);
    MyObject obj;
    QObject::connect(&obj, &MyObject::mySignal, &obj, &MyObject::mySlot);
    emit obj.mySignal();
    return app.exec();
}
