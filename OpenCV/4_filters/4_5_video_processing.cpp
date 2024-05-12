#include <opencv2/opencv.hpp>
#include <iostream>

int main() {
    cv::VideoCapture cap("traffic_video.mp4");
    if (!cap.isOpened()) {
        std::cerr << "Error opening video file" << std::endl;
        return -1;
    }

    // Prepare kernels for morphology and custom filtering
    cv::Mat kernel = cv::getStructuringElement(cv::MORPH_RECT, cv::Size(5, 5));
    cv::Mat customKernel = (cv::Mat_<float>(3,3) <<
                                                 0, -1,  0,
            -1,  5, -1,
            0, -1,  0);  // Example of a sharpening kernel

    // Variables to hold intermediate results
    cv::Mat frame, blurred, grad_x, grad_y;
    cv::Mat abs_grad_x, abs_grad_y, edge_detected;
    cv::Mat morphology_output, customFiltered;

    while (true) {
        if (!cap.read(frame)) // If no frame is read or video ends
            break;

        // Apply Gaussian blur
        cv::GaussianBlur(frame, blurred, cv::Size(5, 5), 0);

        // Sobel operators
        cv::Sobel(blurred, grad_x, CV_16S, 1, 0, 3);
        cv::Sobel(blurred, grad_y, CV_16S, 0, 1, 3);

        // Convert gradients to absolute versions
        cv::convertScaleAbs(grad_x, abs_grad_x);
        cv::convertScaleAbs(grad_y, abs_grad_y);

        // Combine gradients
        cv::addWeighted(abs_grad_x, 0.5, abs_grad_y, 0.5, 0, edge_detected);

        // Apply morphological close
        cv::morphologyEx(edge_detected, morphology_output, cv::MORPH_CLOSE, kernel);

        // Apply custom filtering
        cv::filter2D(morphology_output, customFiltered, -1, customKernel);

        // Display the resulting frame
        cv::imshow("Processed Frame", customFiltered);

        // Break loop on key press
        if (cv::waitKey(30) >= 0)
            break;
    }

    // Clean up
    cap.release();
    cv::destroyAllWindows();

    return 0;
}
