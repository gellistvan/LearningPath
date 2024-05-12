#include <opencv2/opencv.hpp>
#include <iostream>

int slider_value = 0;

void on_trackbar(int, void*) {
    std::cout << "Slider value: " << slider_value << std::endl;
}

int main() {
    // 3.1 Reading an Image
    std::string image_path = "path/to/image.jpg"; // Update the path accordingly
    cv::Mat image = cv::imread(image_path, cv::IMREAD_GRAYSCALE);
    if (image.empty()) {
        std::cerr << "Could not read the image" << std::endl;
        return 1;
    }

    // 3.2 Writing an Image
    bool isSaved = cv::imwrite("output.png", image, {cv::IMWRITE_PNG_COMPRESSION, 9});
    if (!isSaved) {
        std::cerr << "Failed to save the image" << std::endl;
    }

    // 3.3 Displaying Images
    cv::namedWindow("Display window", cv::WINDOW_AUTOSIZE);
    cv::imshow("Display window", image);

    // 3.4 Window Management
    cv::namedWindow("Example Window", cv::WINDOW_NORMAL);
    cv::resizeWindow("Example Window", 600, 400);

    // 3.5 Keyboard Handling
    int key = cv::waitKey(0); // Wait indefinitely until a key is pressed
    if (key == 27) { // ESC key
        cv::destroyAllWindows();
    }

    // 3.6 Advanced GUI Features
    cv::createTrackbar("Slider", "Example Window", &slider_value, 100, on_trackbar);

    // Show the window with the trackbar
    while (true) {
        cv::imshow("Example Window", image);
        char c = (char)cv::waitKey(10);
        if (c == 27) break; // ESC to exit
    }
    cv::destroyAllWindows();
    return 0;
}
