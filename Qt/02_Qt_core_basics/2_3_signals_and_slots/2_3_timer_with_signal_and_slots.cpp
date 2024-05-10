#include QTimer>
#include <QCoreApplication>
#include <QDebug>

class Timer : public QObject {
Q_OBJECT
public slots:
    void handleTimeout() { qDebug() << "Timeout occurred"; }
};

int main(int argc, char *argv[]) {
    QCoreApplication app(argc, argv);
    QTimer timer;
    Timer t;
    QObject::connect(&timer, &QTimer::timeout, &t, &Timer::handleTimeout);
    timer.start(1000);  // 1000 milliseconds
    return app.exec();
}
