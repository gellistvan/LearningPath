#include <QWidget>
#include <QPushButton>
#include <QApplication>
#include <QDebug>

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    QWidget *window = new QWidget;
    QPushButton *button = new QPushButton("Click me", window);
//     The button now has 'window' as its parent.

    window->show();
    qDebug() << "Children count:" << window->children().count();  // Output: 2
//    delete window;


    return app.exec();
}