#include <opencv2/opencv.hpp>
#include <iostream>

int main() {
    // Open the default camera
    cv::VideoCapture capture(0); // 0 is the id of the default camera
    if (!capture.isOpened()) {
        std::cerr << "Error opening video stream or file" << std::endl;
        return -1;
    }

    // Get the frame size
    int frame_width = static_cast<int>(capture.get(cv::CAP_PROP_FRAME_WIDTH));
    int frame_height = static_cast<int>(capture.get(cv::CAP_PROP_FRAME_HEIGHT));

    // Define the codec and create VideoWriter object
    cv::VideoWriter videoWriter;
    videoWriter.open("/tmp/output.avi", cv::VideoWriter::fourcc('M', 'J', 'P', 'G'),
                     10, cv::Size(frame_width, frame_height), true);

    if (!videoWriter.isOpened()) {
        std::cerr << "Could not open the output video file for write" << std::endl;
        return -1;
    }

    // Create a window for display.
    cv::namedWindow("Camera Output", cv::WINDOW_AUTOSIZE);

    while (true) {
        cv::Mat frame;
        // Capture frame-by-frame
        capture >> frame;

        // If the frame is empty, break immediately
        if (frame.empty())
            break;

        // Write the frame into the file
        videoWriter.write(frame);

        // Display the resulting frame
        cv::imshow("Camera Output", frame);

        // Press ESC on keyboard to exit
        char c = (char)cv::waitKey(25);
        if (c == 27) // ASCII value for ESC
            break;
    }

    // When everything done, release the video capture and write object
    capture.release();
    videoWriter.release();

    // Closes all the frames
    cv::destroyAllWindows();

    return 0;
}
