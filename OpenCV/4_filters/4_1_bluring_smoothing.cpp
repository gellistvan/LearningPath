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

    // Create blurred images using different methods
    cv::Mat blurImage, gaussianBlurImage, medianBlurImage;
    cv::blur(image, blurImage, cv::Size(9, 9)); // Normal blurring
    cv::GaussianBlur(image, gaussianBlurImage, cv::Size(9, 9), 0); // Gaussian blurring
    cv::medianBlur(image, medianBlurImage, 9); // Median blurring

    // Create a window to display results
    cv::namedWindow("Blurring Techniques", cv::WINDOW_AUTOSIZE);

    // Grid display 2x2
    int grid_size = 2;
    int rows = image.rows;
    int cols = image.cols;
    cv::Mat displayImage(2 * rows, 2 * cols, image.type());

    // Place images in their respective quadrants
    image.copyTo(displayImage(cv::Rect(0, 0, cols, rows)));
    blurImage.copyTo(displayImage(cv::Rect(cols, 0, cols, rows)));
    gaussianBlurImage.copyTo(displayImage(cv::Rect(0, rows, cols, rows)));
    medianBlurImage.copyTo(displayImage(cv::Rect(cols, rows, cols, rows)));

    // Show the result in the window
    cv::imshow("Blurring Techniques", displayImage);

    // Wait for a key press indefinitely
    cv::waitKey(0);

    return 0;
}
