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

    // Create edge-detected images using different methods
    cv::Mat sobelEdges, laplacianEdges, cannyEdges;
    cv::Sobel(image, sobelEdges, CV_64F, 1, 1); // Sobel edge detection
    cv::Laplacian(image, laplacianEdges, CV_64F); // Laplacian edge detection
    cv::Canny(image, cannyEdges, 50, 150); // Canny edge detection

    // Convert floating point images to 8-bit images
    cv::convertScaleAbs(sobelEdges, sobelEdges);
    cv::convertScaleAbs(laplacianEdges, laplacianEdges);

    // Create a window to display results
    cv::namedWindow("Edge Detection Techniques", cv::WINDOW_AUTOSIZE);

    // Grid display 2x2
    int grid_size = 2;
    int rows = image.rows;
    int cols = image.cols;
    cv::Mat displayImage(2 * rows, 2 * cols, image.type());

    // Place images in their respective quadrants
    image.copyTo(displayImage(cv::Rect(0, 0, cols, rows)));
    sobelEdges.copyTo(displayImage(cv::Rect(cols, 0, cols, rows)));
    laplacianEdges.copyTo(displayImage(cv::Rect(0, rows, cols, rows)));
    cannyEdges.copyTo(displayImage(cv::Rect(cols, rows, cols, rows)));

    // Show the result in the window
    cv::imshow("Edge Detection Techniques", displayImage);

    // Wait for a key press indefinitely
    cv::waitKey(0);

    return 0;
}