#include <QCoreApplication>
#include <QVariant>
#include <QString>
#include <QDebug>


int main(int argc, char *argv[]) {
    QCoreApplication app(argc, argv);

    QString s = "Hello, world!";
    qDebug() << "Length:" << s.length();
    qDebug() << "Empty?" << s.isEmpty();
    QStringList parts = s.split(',');
    qDebug() << "Split result:" << parts.at(0).trimmed();  // Output: "Hello"

    s = "Temperature";
    double temp = 24.5;
    QString text = s + ": " + QString::number(temp);

    QVariant v(42);  // Stores an integer
    qDebug() << "Is string?" << v.canConvert<QString>();
    qDebug() << "As string:" << v.toString();
    v.setValue(QString("Hello Qt"));
    qDebug() << "Now a string?" << v.canConvert<QString>();
    qDebug() << "As string:" << v.toString();

    return app.exec();
}