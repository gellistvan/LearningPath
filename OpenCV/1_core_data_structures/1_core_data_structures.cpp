#include <opencv2/opencv.hpp>
#include <iostream>

int main() {
    // Define matrix size and type
    cv::Size size(5, 5);
    cv::Mat matrix(size, CV_8UC3, cv::Scalar(0, 0, 255));  // Initialize matrix with red color

    // Access and modify matrix elements using cv::Point and cv::Vec
    cv::Point point(2, 2);  // A point at row 2, column 2
    matrix.at<cv::Vec3b>(point) = cv::Vec3b(255, 255, 255);  // Change color to white at (2,2)

    // Access and print specific element using cv::Vec
    cv::Vec3b pixel = matrix.at<cv::Vec3b>(2, 2);
    std::cout << "Pixel at (2,2): (" << (int)pixel[0] << ", " << (int)pixel[1] << ", " << (int)pixel[2] << ")" << std::endl;

    // Displaying the size of the matrix
    std::cout << "Matrix size: " << matrix.size().width << "x" << matrix.size().height << std::endl;

    // Iterating over the matrix elements to show a few more modifications
    for(int i = 0; i < matrix.rows; i++) {
        for(int j = 0; j < matrix.cols; j++) {
            // Set the blue channel to 100 at all points
            matrix.at<cv::Vec3b>(i, j)[0] = 100;
        }
    }

    // Print the modified matrix values for a few pixels
    for (int i = 0; i < std::min(3, matrix.rows); ++i) {
        for (int j = 0; j < std::min(3, matrix.cols); ++j) {
            cv::Vec3b pixel = matrix.at<cv::Vec3b>(i, j);
            std::cout << "Pixel at (" << i << "," << j << "): ("
                      << (int)pixel[0] << ", " << (int)pixel[1] << ", " << (int)pixel[2] << ")" << std::endl;
        }
    }

    return 0;
}
