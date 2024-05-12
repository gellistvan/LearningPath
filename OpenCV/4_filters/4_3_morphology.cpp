#include <opencv2/opencv.hpp>
#include <iostream>

#ifndef RESOURCES_PATH
#define RESOURCES_PATH "Undefined"
#endif

int main() {
    // Adjust the path to the image according to your setup
    std::string resources_path = RESOURCES_PATH;
    std::string imagePath = resources_path + std::string("OpenCV/lenna.jpg");

    // Read the image
    cv::Mat image = cv::imread(imagePath, cv::IMREAD_GRAYSCALE);
    if (image.empty()) {
        std::cerr << "Could not read the image: " << imagePath << std::endl;
        return 1;
    }

    // Create morphologically transformed images
    cv::Mat dilatedImage, erodedImage, openedImage;
    cv::Mat element = cv::getStructuringElement(cv::MORPH_RECT, cv::Size(5, 5));

    // Apply dilation
    cv::dilate(image, dilatedImage, element);

    // Apply erosion
    cv::erode(image, erodedImage, element);

    // Apply opening
    cv::morphologyEx(image, openedImage, cv::MORPH_OPEN, element);

    // Create a window to display results
    cv::namedWindow("Morphological Transformations", cv::WINDOW_AUTOSIZE);

    // Grid display 2x2
    int grid_size = 2;
    int rows = image.rows;
    int cols = image.cols;
    cv::Mat displayImage(2 * rows, 2 * cols, image.type());

    // Place images in their respective quadrants
    image.copyTo(displayImage(cv::Rect(0, 0, cols, rows)));
    dilatedImage.copyTo(displayImage(cv::Rect(cols, 0, cols, rows)));
    erodedImage.copyTo(displayImage(cv::Rect(0, rows, cols, rows)));
    openedImage.copyTo(displayImage(cv::Rect(cols, rows, cols, rows)));

    // Show the result in the window
    cv::imshow("Morphological Transformations", displayImage);

    // Wait for a key press indefinitely
    cv::waitKey(0);

    return 0;
}