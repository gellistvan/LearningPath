#pragma once

#include <QMainWindow>
#include <QPushButton>
#include <QTextEdit>
#include <QFileDialog>
#include <QFile>
#include <QTextStream>
#include <QDebug>

class MainWindow : public QMainWindow
{
Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr)
            : QMainWindow(parent)
    {
        openButton = new QPushButton("Open Text File", this);
        setCentralWidget(openButton);
        connect(openButton, &QPushButton::clicked, this, &MainWindow::openFile);
    }

private slots:
    void openFile()
    {
        QString fileName = QFileDialog::getOpenFileName(this, tr("Open Text File"), "", tr("Text Files (*.txt);;All Files (*)"));

        if (fileName.isEmpty())
            return;

        QFile file(fileName);
        if (!file.open(QIODevice::ReadWrite | QIODevice::Text)) {
            qWarning("Cannot open file for reading");
        } else {
            QTextStream in(&file);
            while (!in.atEnd()) {
                QString line = in.readLine();
                qDebug() << line;
            }
            QTextStream out(&file);
            out << "New line of text\n";
            file.close();
        }
    };

private:
    QPushButton *openButton;
};


