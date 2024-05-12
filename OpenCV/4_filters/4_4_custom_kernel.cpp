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
    cv::Mat image = cv::imread(imagePath);
    if (image.empty()) {
        std::cerr << "Could not read the image: " << imagePath << std::endl;
        return 1;
    }

    // Create a custom kernel (e.g., a sharpening filter)
    cv::Mat kernel = (cv::Mat_<float>(3,3) <<
            0, -1,  0,
            -1,  5, -1,
            0, -1,  0);

    // Create an image for the filter output
    cv::Mat filteredImage;

    // Apply the custom kernel filter
    cv::filter2D(image, filteredImage, -1, kernel);

    // Create a window to display results
    cv::namedWindow("Custom Kernel Effect", cv::WINDOW_AUTOSIZE);

    // Display images side by side
    int rows = image.rows;
    int cols = image.cols;
    cv::Mat displayImage(rows, 2 * cols, image.type());

    // Place images next to each other
    image.copyTo(displayImage(cv::Rect(0, 0, cols, rows)));
    filteredImage.copyTo(displayImage(cv::Rect(cols, 0, cols, rows)));

    // Show the result in the window
    cv::imshow("Custom Kernel Effect", displayImage);

    // Wait for a key press indefinitely
    cv::waitKey(0);

    return 0;
}