#include <QApplication>
#include <QWidget>
#include <QLabel>
#include <QImage>
#include <QPixmap>
#include <opencv2/opencv.hpp>

int main(int argc, char** argv) {
    QApplication app(argc, argv);

    cv::Mat image = cv::imread("/mnt/c/Data/images/440465443_411021305017410_1160088114663718974_n.jpg"); // Kép betöltése
    cv::cvtColor(image, image, cv::COLOR_BGR2RGB);  // Convert color to RGB

    QImage img((const uchar*) image.data, image.cols, image.rows, image.step, QImage::Format_RGB888);
    QPixmap pixmap = QPixmap::fromImage(img);

    QLabel label;
    label.setPixmap(pixmap);
    label.setFixedSize(pixmap.size());
    label.show();

    return app.exec();
}
