#include <QApplication>
#include <QMainWindow>
#include <QMenuBar>
#include <QMessageBox>

class MainWindow : public QMainWindow {
public:
    MainWindow() {
        QMenu *fileMenu = menuBar()->addMenu("File");
        QAction *exitAction = fileMenu->addAction("Exit");
        connect(exitAction, &QAction::triggered, this, &MainWindow::close);

        QAction *aboutAction = fileMenu->addAction("About");
        connect(aboutAction, &QAction::triggered, this, &MainWindow::showAboutDialog);
    }

    void showAboutDialog() {
        QMessageBox::about(this, "About", "Qt MainWindow Example");
    }
};

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);
    MainWindow mainWindow;
    mainWindow.show();
    return app.exec();
} 