#include <QApplication>
#include <QWidget>
#include <QPushButton>
#include <QVBoxLayout>

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);
    QWidget window;

    QVBoxLayout *layout = new QVBoxLayout(&window);  // Create a vertical layout manager

    QPushButton *button1 = new QPushButton("Button 1");
    QPushButton *button2 = new QPushButton("Button 2");
    layout->addWidget(button1);
    layout->addWidget(button2);

    window.setLayout(layout);  // Set the layout on the main window
    window.show();  // Display the window
    return app.exec();
}