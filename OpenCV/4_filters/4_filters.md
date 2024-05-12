# 4. Filters
OpenCV provides a vast array of functions for filtering images, which is a fundamental aspect of image processing and computer vision. These filtering operations range from simple blurring and smoothing to more complex operations like morphological transformations and custom-designed filters. Here’s a detailed overview of some of the primary filtering functions available in OpenCV:
## 4.1. Blurring and Smoothing
Blurring is used to reduce image noise and detail. OpenCV implements several methods for this purpose:

### cv::blur or cv::boxFilter
Applies a simple average convolutional filter. Good for basic smoothing without edge preservation.

**Parameters:**
* `src`: Source image.
* `dst`: Destination image.
* `ksize`: Size of the kernel (the area considered around each pixel).

### cv::GaussianBlur
Applies a Gaussian kernel to smooth the image, which gives more weight to the pixels near the center of the kernel and less to those on the periphery.
Effective for removing Gaussian noise and is widely used in preprocessing steps.

**Parameters:**
* `src`: Source image.
* `dst`: Destination image.
* `ksize`: Kernel size, width and height should be odd and can differ.
* `sigmaX`: Gaussian kernel standard deviation in X direction.
Example:
```cpp
cv::Mat frame; // Assume frame is an input video frame
cv::Mat blurred;
cv::GaussianBlur(frame, blurred, cv::Size(5, 5), 0);
```

### cv::medianBlur
Applies a median filter, where each pixel is replaced with the median of its neighborhood pixels. Highly effective for removing salt-and-pepper noise while
preserving edges.

**Parameters:**
* `src`: Source image.
* `dst`: Destination image.
* `ksize`: Aperture linear size; it must be odd and greater than 1.

### cv::bilateralFilter
Applies a bilateral filter, which can reduce unwanted noise while keeping edges sharp. Excellent for noise reduction without creating edge artifacts; ideal
for photo editing.

**Parameters:**
* `src`: Source image.
* `dst`: Destination image.
* `d`: Diameter of each pixel neighborhood.
* `sigmaColor`: Filter sigma in the color space.
* `sigmaSpace`: Filter sigma in the coordinate space.

### 4.2. Edge Detection Filters
Edge detection is crucial for locating points in an image where the image brightness changes sharply or has discontinuities.

### cv::Sobel
Finds derivatives (gradient, or sharp intensity changes) of an image. Used to detect edges in both X and Y directions.

**Parameters:**
* **src**`: Input image.
* **dst**`: Output image.
* **ddepth**`: Output image depth.
* **dx**`: Order of the derivative x.
* **dy**`: Order of the derivative y.

Example
```cpp
cv::Mat grad_x, grad_y;
cv::Mat abs_grad_x, abs_grad_y;
cv::Mat edge_detected;

// Compute gradients on both directions
cv::Sobel(blurred, grad_x, CV_16S, 1, 0, 3);
cv::Sobel(blurred, grad_y, CV_16S, 0, 1, 3);

// Convert gradients to absolute values
cv::convertScaleAbs(grad_x, abs_grad_x);
cv::convertScaleAbs(grad_y, abs_grad_y);

// Combine the gradients
cv::addWeighted(abs_grad_x, 0.5, abs_grad_y, 0.5, 0, edge_detected);
```

### cv::Laplacian
Calculates the Laplacian of the image. Enhances areas of rapid intensity change and is therefore often used for edge detection.

**Parameters:**
* **src**: Source image.
* **dst**: Destination image.
* **ddepth**: Desired depth of the destination image.

### 4.3. Morphological Transformations
Morphological operations process images based on shapes. They apply a structuring element to an input image and generate an output image.

### cv::dilate, cv::erode
The basic morphological operations. Dilation enlarges bright regions, while erosion shrinks them. Useful for removing small white/black spots and
connecting neighboring objects.

**Parameters:**
* **src**: Input image.
* **dst**: Output image.
* **kernel**: Structuring element used for the operation.

Example
```cpp
cv::Mat morphology_output;
cv::Mat kernel = cv::getStructuringElement(cv::MORPH_RECT, cv::Size(3, 3));
cv::morphologyEx(edge_detected, morphology_output, cv::MORPH_CLOSE, kernel);
```

### cv::morphologyEx
Applies more complex morphological transformations like opening, closing, gradient, etc. Can perform operations such as opening (erosion followed by dilation) and closing (dilation followed by erosion), which are useful in noise reduction and gap bridging.

**Parameters:**
* **src**: Source image.
* **dst**: Destination image.
* **op**: Type of morphological operation.
* **kernel**: Structuring element.

### 4.4. Custom Filters: `cv::filter2D`
Applies a user-defined kernel to an image. Allows the implementation of custom filtering effects, such as embossing, sharpening, and edge detection.

These filtering functions provide powerful tools for manipulating images, enhancing features, and preparing data for higher-level computer vision tasks

**Parameters:**
* **src**: Input image.
* **dst**: Output image.
* **ddepth**: Desired depth of the output image.
* **kernel**: Convolution kernel (or rather a correlation kernel), a single-channel floating point matrix.

For demonstration, let's say we want to enhance specific features using a custom filter. Perhaps we want to highlight horizontal or vertical features that
could be indicative of lane markings.

```cpp
// Define a simple horizontal line enhancer kernel
cv::Mat customKernel = (cv::Mat_<float>(3,3) <<
                        -1, -1, -1,
                         2, 2, 2,
                        -1, -1, -1);
cv::Mat customFiltered;
cv::filter2D(morphology_output, customFiltered, -1, customKernel);
```
### 4.5 Combine Steps in a Video Processing Loop
Putting all the above into a loop that processes each frame of the video:
```cpp
cv::VideoCapture cap("traffic_video.mp4");
if (!cap.isOpened()) {
        std::cerr << "Error opening video file" << std::endl;
        return -1;
}
while (true) {
        cv::Mat frame;
        if (!cap.read(frame)) // If no frame is read or video ends
                break;
        cv::GaussianBlur(frame, blurred, cv::Size(5, 5), 0);
        cv::Sobel(blurred, grad_x, CV_16S, 1, 0, 3);
        cv::Sobel(blurred, grad_y, CV_16S, 0, 1, 3);
        cv::convertScaleAbs(grad_x, abs_grad_x);
        cv::convertScaleAbs(grad_y, abs_grad_y);
        cv::addWeighted(abs_grad_x, 0.5, abs_grad_y, 0.5, 0, edge_detected);
        cv::morphologyEx(edge_detected, morphology_output, cv::MORPH_CLOSE, kernel);
        cv::filter2D(morphology_output, customFiltered, -1, customKernel);
        cv::imshow("Processed Frame", customFiltered);
        if (cv::waitKey(30) >= 0) // Wait for 30ms or until any key is pressed
                break;
}
cap.release();
cv::destroyAllWindows();
```

This example demonstrates how to use a combination of filters to process and enhance video for further analysis. Each step contributes to improving the quality of the input for subsequent processing stages, such as feature extraction or object detection.