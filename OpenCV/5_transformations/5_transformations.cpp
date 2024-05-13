#include "5_transformations.h"
#include <QApplication>
#include <QVBoxLayout>
#include <opencv2/imgproc.hpp>

#ifndef RESOURCES_PATH
#define RESOURCES_PATH "Undefined"
#endif


MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), currentState(0) {
    // Adjust the path to the image according to your setup
    std::string resources_path = RESOURCES_PATH;
    std::string imagePath = resources_path + std::string("OpenCV/lenna.jpg");

    originalImage = cv::imread(imagePath);  // Ensure path is correct
    if (originalImage.empty()) {
        // Handle error
    }

    imageLabel = new QLabel(this);
    QPixmap pixmap = QPixmap::fromImage(QImage(originalImage.data, originalImage.cols, originalImage.rows, QImage::Format_RGB888).rgbSwapped());
    imageLabel->setPixmap(pixmap);

    actionButton = new QPushButton("Upscale", this);
    connect(actionButton, &QPushButton::clicked, this, &MainWindow::processImage);

    timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &MainWindow::revertImage);

    QVBoxLayout *layout = new QVBoxLayout();
    layout->addWidget(imageLabel);
    layout->addWidget(actionButton);

    QWidget *widget = new QWidget();
    widget->setLayout(layout);
    setCentralWidget(widget);
}

MainWindow::~MainWindow() {}

void MainWindow::setButtonText(const char* text)
{
    actionButton->setText(text);
}

void MainWindow::processImage() {
    switch (currentState) {
        case 0:
            upscaleImage();
            break;
        case 1:
            translateImage();
            break;
        case 2:
            rotateImage();
            break;
        case 3:
            affineTransform();
            break;
        case 4:
            perspectiveTransform();
            break;
        case 5:
            close();
            break;
    }
    currentState = (currentState + 1) % 6;
}

void MainWindow::revertImage() {
    QPixmap pixmap = QPixmap::fromImage(QImage(originalImage.data, originalImage.cols, originalImage.rows, QImage::Format_RGB888).rgbSwapped());
    imageLabel->setPixmap(pixmap);
    timer->stop();
}

void MainWindow::upscaleImage() {
    // Upscale the image by a factor of 2.0
    cv::Mat tempImage;
    cv::resize(originalImage, tempImage, cv::Size(), 2.0, 2.0, cv::INTER_LINEAR);

    // Crop the upscaled image to the original image size from the top-left corner
    cv::Rect roi(0, 0, originalImage.cols, originalImage.rows);  // ROI in the original size
    transformedImage = tempImage(roi).clone();  // Crop and clone the ROI to get the cropped image

    displayTransformedImage();
    setButtonText("Translate");
}


void MainWindow::translateImage() {
    cv::Mat translationMat = (cv::Mat_<double>(2,3) << 1, 0, 100, 0, 1, 50);
    cv::warpAffine(originalImage, transformedImage, translationMat, originalImage.size());
    displayTransformedImage();
    setButtonText("Rotate");
}

void MainWindow::rotateImage() {
    cv::Point2f center(originalImage.cols/2.0, originalImage.rows/2.0);
    cv::Mat rotationMat = cv::getRotationMatrix2D(center, 45, 1);
    cv::warpAffine(originalImage, transformedImage, rotationMat, originalImage.size());
    displayTransformedImage();
    setButtonText("Affine transform");
}

void MainWindow::affineTransform() {
    // Points in the original image
    std::vector<cv::Point2f> srcTri;
    srcTri.push_back(cv::Point2f(0, 0));
    srcTri.push_back(cv::Point2f(originalImage.cols - 1, 0));
    srcTri.push_back(cv::Point2f(0, originalImage.rows - 1));

    // Corresponding points in the transformed image
    std::vector<cv::Point2f> dstTri;
    dstTri.push_back(cv::Point2f(originalImage.cols*0.0, originalImage.rows*0.33));
    dstTri.push_back(cv::Point2f(originalImage.cols*0.85, originalImage.rows*0.25));
    dstTri.push_back(cv::Point2f(originalImage.cols*0.15, originalImage.rows*0.7));

    // Get the Affine Transform Matrix
    cv::Mat warp_mat = cv::getAffineTransform(srcTri, dstTri);

    // Apply the Affine Transform just found to the src image
    cv::warpAffine(originalImage, transformedImage, warp_mat, originalImage.size());
    displayTransformedImage();
    setButtonText("Perspective transform");
}

void MainWindow::perspectiveTransform() {
    // Points in the original image
    std::vector<cv::Point2f> srcQuad;
    srcQuad.push_back(cv::Point2f(0, 0));
    srcQuad.push_back(cv::Point2f(originalImage.cols - 1, 0));
    srcQuad.push_back(cv::Point2f(originalImage.cols - 1, originalImage.rows - 1));
    srcQuad.push_back(cv::Point2f(0, originalImage.rows - 1));

    // Corresponding points in the transformed image
    std::vector<cv::Point2f> dstQuad;
    dstQuad.push_back(cv::Point2f(originalImage.cols*0.05, originalImage.rows*0.33));
    dstQuad.push_back(cv::Point2f(originalImage.cols*0.9, originalImage.rows*0.25));
    dstQuad.push_back(cv::Point2f(originalImage.cols*0.8, originalImage.rows*0.9));
    dstQuad.push_back(cv::Point2f(originalImage.cols*0.2, originalImage.rows*0.7));

    // Get the Perspective Transform Matrix
    cv::Mat warpMatrix = cv::getPerspectiveTransform(srcQuad, dstQuad);

    // Apply the Perspective Transformation to the image
    cv::warpPerspective(originalImage, transformedImage, warpMatrix, originalImage.size());
    displayTransformedImage();
    setButtonText("Exit");
}

void MainWindow::displayTransformedImage() {
    QImage qimg(transformedImage.data, transformedImage.cols, transformedImage.rows, transformedImage.step, QImage::Format_RGB888);
    QPixmap pixmap = QPixmap::fromImage(qimg.rgbSwapped());

    // Resize pixmap to fit in the label if it is larger than label
    if (imageLabel->size().width() < pixmap.width() || imageLabel->size().height() < pixmap.height()) {
        pixmap = pixmap.scaled(imageLabel->size(), Qt::KeepAspectRatio, Qt::SmoothTransformation);
    }

    imageLabel->setPixmap(pixmap);
    timer->start(10000); // Start or restart the timer for 10 seconds
}

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);
    MainWindow w;
    w.show();
    return app.exec();
}
