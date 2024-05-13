#pragma once
#include <QMainWindow>
#include <QPushButton>
#include <QLabel>
#include <QTimer>
#include <opencv2/opencv.hpp>

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void displayTransformedImage();
    void setButtonText(const char* text);

private slots:
    void processImage();
    void revertImage();

private:
    void upscaleImage();
    void translateImage();
    void rotateImage();
    void affineTransform();
    void perspectiveTransform();

    cv::Mat originalImage;
    cv::Mat transformedImage;
    QLabel *imageLabel;
    QPushButton *actionButton;
    QTimer *timer;
    int currentState;
};
