#include <QCoreApplication>
#include <QObject>
#include <QDebug>

class Application : public QObject {
public:
    Application(QObject *parent = nullptr) : QObject(parent) {
        setProperty("Version", "1.0");
    }
    void printVersion() {
        qDebug() << "Application version:" << property("Version").toString();
    }
};

int main(int argc, char *argv[]) {
    QCoreApplication app(argc, argv);
    Application myApp;
    myApp.printVersion();
    return app.exec();
}