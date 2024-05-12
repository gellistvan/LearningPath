## 1. Core data structures
### 1.1. cv::Mat
cv::Mat is the primary data structure in OpenCV, designed to represent matrices, including images. It's versatile, supporting operations on both grayscale and color images.
Supports various data types (e.g., `CV_8U`, `CV_32F`). Channels: Can handle multiple channels (e.g., `RGB`, `RGBA`).
#### Constructors and Construction Methods
```cpp
cv::Mat image;
cv::Mat image(480, 640, CV_8UC3); // 640x480 with 3 channels, 8-bit unsigned integer
cv::Mat image = cv::imread("path/to/image.jpg", cv::IMREAD_COLOR); // Read in color
```
#### Constructor Wrapping Existing Data
The `cv::Mat` constructor can also wrap around existing data without copying it. This is useful when you have data stored in other formats or containers
and you want to perform operations on this data using OpenCV functions without the overhead of copying it.
Syntax:
```cpp
cv::Mat(int rows, int cols, int type, void* data, size_t step=AUTO_STEP);
```

**Parameters:**
* `rows`: Number of rows in the matrix.
* `cols`: Number of columns in the matrix.
* `type`: Matrix type (e.g., `CV_8UC3` for an 8-bit unsigned integer matrix with 3 channels).
* `data`: Pointer to the user data.
* `step`: Number of bytes each matrix row occupies. The default is `AUTO_STEP`, which indicates that the step is computed as `cols*elemSize()`.

Example:
Suppose you have a buffer with image data you want to process with OpenCV without copying:
```cpp
uchar buffer[100 * 100 * 3]; // Example buffer for a 100x100 image with 3 channels
cv::Mat image(100, 100, CV_8UC3, buffer);
```
This constructor is particularly important when dealing with real-time image processing where data may be continuously streamed from a camera or a
network source. It allows for efficient manipulation of this data directly without the need for intermediate copies.

#### Key Properties and Methods Related to Data Management
* `data`: A pointer to the underlying data, which allows direct access to the pixel values. This is useful for interfacing with other libraries or for low-level optimizations.
* `step`: Represents the size of one row in bytes. It can be larger than 
* `cols * typeSize` due to padding for alignment purposes.
* `isContinuous()`: This method checks if the matrix elements are stored continuously without gaps at the end of each row. If true, it guarantees that the matrix elements can be treated as a single array for processing (i.e., you can apply functions expecting a continuous memory layout).
* `clone()` and `copyTo()`: These are critical when you need to create a copy of the matrix. 
* `clone()` creates a full copy of the matrix and the data, while 
* `copyTo()` provides options to copy to another matrix, possibly with some conditions (like a mask)

#### Efficiency Considerations
Using the `cv::Mat` class efficiently often involves understanding the memory layout and how data is accessed and manipulated. Wrapping an existing
buffer can save significant time and memory, especially in high-throughput applications like video processing or high-speed photography. By using these
more detailed aspects of `cv::Mat`, developers can better optimize their applications and leverage OpenCV's capabilities more effectively.

#### Key Usages
Image Storage: Every image is stored as a `cv::Mat`. You can access pixels, perform slicing, and more.
Image Processing: Used in nearly all image processing functions like `cv::blur`, `cv::cvtColor`.

#### Pixel Access:
For a single channel: ` <uchar>(y, x)` image.at
For multiple channels: ` <cv::Vec3b>(y, x)[channel]` image.at

### 1.2. cv::Scalar
This is used primarily for pixel value specification and operations in multiple channels. It can hold up to four values, generally used for specifying pixel
values in different channels. Can be constructed using up to four values.
```cpp
cv::Scalar color(255, 0, 0); // Red in BGR format
```
Used to specify color for shapes or texts.
```cpp
cv::circle(image, cv::Point(100, 100), 10, cv::Scalar(0, 0, 255), -1);
```
### 1.3. cv::Size
This class is used for specifying the size of an image or matrix in OpenCV. Represents size as width and height. Key usage is resizing Images:
```cpp
cv::Size size(640, 480);
cv::resize(src, dst, size);
```
### 1.4. cv::Point
Represents a point in 2D space. Defined by its `x` and `y` coordinates. Used in drawing functions like `cv::line`, `cv::circle`.
```cpp
cv::Point pt(10, 20);
cv::line(image, cv::Point(0,0), cv::Point(100,100), cv::Scalar(255,0,0));
```
### 1.5. cv::Vec
Used to represent small matrices, especially useful for pixel manipulation when dealing with multi-channel images. Specialized for small sizes like `Vec3b` for 3-channel byte images. Directly used to read or write pixel values in multi-channel images.
```cpp
cv::Vec3b color(255, 0, 0); // Red in BGR
cv::Vec3b color = image.at<cv::Vec3b>(y, x);
color[2] = 255; // Set red channel
```

These structures are central to performing most tasks in OpenCV, whether it’s reading and writing images, handling transformations, or performing complex image analysis and vision tasks. Each structure is designed to provide a robust and efficient way to handle the data and operations typical in computer vision applications.