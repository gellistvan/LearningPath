#include <QApplication>
#include <QWidget>
#include <QPushButton>
#include <QLabel>
#include <QLineEdit>

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    QWidget window;
    window.setFixedSize(200, 150);

    QLabel *promptLabel = new QLabel("Name:", &window);
    promptLabel->move(10, 10);

    QLineEdit *lineEdit = new QLineEdit(&window);
    lineEdit->move(60, 10);
    lineEdit->resize(130, 20);

    QPushButton *button = new QPushButton("Submit", &window);
    button->move(50, 50);

    QLabel *greetingLabel = new QLabel("", &window);
    greetingLabel->move(10, 80);
    greetingLabel->resize(280, 20);

    QObject::connect(button, &QPushButton::clicked, [&](){
        QString name = lineEdit->text();
        if (not name.isEmpty()) {
            greetingLabel->setText("Hello " + name + "!");
        }
    });

    window.show();
    return app.exec();
}
