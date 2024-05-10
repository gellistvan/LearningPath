#include <QApplication>
#include <QPushButton>
#include <QDebug>

class MyWidget : public QWidget {
public:
    MyWidget() {
        QPushButton *button = new QPushButton("Click me", this);
        connect(button, &QPushButton::clicked, this, &MyWidget::onButtonClicked);
    }

private slots:
    void onButtonClicked() {
        qDebug() << "Button clicked!";
    }
};

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);
    MyWidget widget;
    widget.show();
    return app.exec();
}