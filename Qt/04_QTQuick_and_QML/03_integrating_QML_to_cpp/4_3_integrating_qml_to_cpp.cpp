#include "4_3_integrating_qml_to_cpp.h"

#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include <QDebug>

int main(int argc, char *argv[]) {
    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;
    MyObject myObject;

    // Expose the MyObject instance to QML
    engine.rootContext()->setContextProperty("myObject", &myObject);

    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));

    return app.exec();
}