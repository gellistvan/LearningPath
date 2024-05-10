#include <QApplication>
#include <QWidget>
#include <QKeyEvent>
#include <QDebug>

class EventWidget : public QWidget {
protected:
    void keyPressEvent(QKeyEvent *event) override {
        if (event->key() == Qt::Key_Space) {
            qDebug() << "Space key pressed!";
        }
    }

    void mousePressEvent(QMouseEvent *event) override {
        if (event->button() == Qt::LeftButton) {
            qDebug() << "Left mouse button pressed at position" << event->pos();
        }
        QWidget::mousePressEvent(event);  // Pass the event to the parent class
    }
};

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);
    EventWidget widget;
    widget.show();
    return app.exec();
} 