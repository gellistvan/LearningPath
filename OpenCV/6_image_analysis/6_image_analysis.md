# 6. Image analysis tools
Image analysis in OpenCV is a vast topic, encompassing a wide range of functions that allow for the extraction of meaningful information from images.
These functions can be broadly categorized into feature detection, image segmentation, image statistics, and geometric transformations that support
higher-level tasks such as object recognition, tracking, and machine learning. Here, we'll dive into some key image analysis functions, providing a detailed
look at their parameters, usages, and typical application contexts.

## 6.1. Feature Detection and Description
Feature detection is crucial for many computer vision tasks such as image matching, object detection, and motion tracking. OpenCV provides several algorithms for this purpose.

### a. Harris Corner Detection
Identifies corners in the image, which are points with significant variation in intensity in all directions.
**Parameters:**
* **src**`: Input single-channel 8-bit or floating-point image.
* **dst**`: Image to store the Harris detector responses.
* **blockSize**: Neighborhood size (see the actual size is `blockSize x blockSize`).
* **ksize**`: Aperture parameter for the Sobel operator.
* **k**`: Harris detector free parameter.
* **borderType**: Pixel extrapolation method.

**Example:**
```cpp
cv::Mat src_gray; // Assuming src_gray is your input image converted to grayscale
cv::Mat dst;
cv::cornerHarris(src_gray, dst, 2, 3, 0.04, cv::BORDER_DEFAULT);
```

### b. SIFT (Scale-Invariant Feature Transform)
Detects and computes unique features in images that are invariant to scaling, rotation, and partially invariant to change in illumination and 3D camera
viewpoint. Create a SIFT object and use it to detect keypoints and compute descriptors.
Example:
std::vector<cv::KeyPoint> keypoints;
cv::Mat descriptors;
cv::Ptr<cv::SIFT> detector = cv::SIFT::create();
detector->detectAndCompute(src_gray, cv::noArray(), keypoints, descriptors);

## 6.2. Image Segmentation
Segmentation divides an image into parts that have a stronger correlation with objects or areas of real-world.

### a. Watershed Algorithm
A popular algorithm for image segmentation used to separate objects in the image.

**Parameters:**
* **image:** Input 8-bit 3-channel image.
* **markers:** Input/output 32-bit single-channel image (map of markers).

**Example:**
```cpp
cv::Mat markers; // Assume initialized properly
cv::watershed(src, markers);
```

#### b. Contour Detection
Finds contours in a binary image.

**Parameters:**
* **image:** Input image (binary). 
* **contours:** Detected contours stored as vectors of points. 
* **mode:** Contour retrieval mode. 
* **method:** Contour approximation method. 

**Example:**
```cpp
std::vector<std::vector<cv::Point>> contours;
cv::findContours(binaryImage, contours, cv::RETR_TREE, cv::CHAIN_APPROX_SIMPLE);
```

## 6.3. Image Statistics
OpenCV provides functions to extract statistical information from images.

### Histogram Calculation
Computes the frequency of pixel values.

**Parameters:**
* **images:** Source images.
* **channels:** List of the dims channels used to compute the histogram.
* **mask:** Optional mask.
* **hist:** Output histogram.
* **dims:** Histogram dimensionality.
* **histSize:** Array of histogram sizes in each dimension.
* **ranges:** Array of the dims channels' value range.

**Example:**
```cpp
cv::Mat hist;
int histSize[] = {256};
float range[] = {0, 256};
const float* ranges[] = { range };
cv::calcHist(&src_gray, 1, 0, cv::Mat(), hist, 1, histSize, ranges, true, false);
```

## 6.4. Geometric Measurements
OpenCV offers tools to analyze the geometry of shapes found in an image.

### Bounding Box, Minimum Enclosing Circle, and Fitting an Ellipse
Calculates various geometric descriptors.

**Functions:** `cv::boundingRect`, `cv::minEnclosingCircle`, `cv::fitEllipse`

**Usage:**
```cpp
cv::Rect box = cv::boundingRect(contours[0]);
cv::RotatedRect ellipse = cv::fitEllipse(contours[0]);

cv::Point2f center;
float radius;
cv::minEnclosingCircle(contours[0], center, &radius);
```
These functions and their application to image analysis are integral to extracting useful information from visual data, which can be applied in scenarios ranging from simple tasks like counting objects in an image to complex operations such as autonomous driving systems and medical image analysis.

## 6.5. Optical Flow
Optical flow is a crucial concept in video processing, used to track the movement of objects or camera motion between two consecutive frames.

### a. Lucas-Kanade Method

**Para meters:**
* `prevImg`, `nextImg`: Previous and next frame in a video sequence.
* `prevPts`, `nextPts`: Points to track (input in   and output in  ). `prevImg` `nextImg`
* `status`: Output status vector (found/not found for each point).
* `err`: Output vector of errors.

**Example:**
```cpp
std::vector<cv::Point2f> prevPts, nextPts;
std::vector<uchar> status;
std::vector<float> err;
cv::calcOpticalFlowPyrLK(prevImg, nextImg, prevPts, nextPts, status, err);
```

### b. Farneback's Method
**Parameters:**
* `prev`, `next`: Input frames.
* `flow`: Computed flow image.
* `pyr_scale`, `levels`, `winsize`, `iterations`, `poly_n`, `poly_sigma`, `flags`: Algorithm-specific parameters.

**Example:**
```cpp
cv::Mat flow;
cv::calcOpticalFlowFarneback(prev, next, flow, 0.5, 3, 15, 3, 5, 1.2, 0);
```

## 6.6. Structural Analysis and Shape Descriptors
OpenCV provides tools to analyze the structure and shape of objects in images, which can be essential for object identification and classification.

### Hu Moments
Gives a set of numbers that represent the shape of an object, which is invariant to scale, rotation, and translation.

**Parameters:** 
* **moments:** The moments of an image or contour, calculated using `cv::moments`. 

**Example:**
```cpp
cv::Moments m = cv::moments(contour, true);
double huMoments[7];
cv::HuMoments(m, huMoments);
```

## 6.7. Machine Learning in OpenCV
OpenCV integrates well with machine learning algorithms, providing tools to handle tasks like face recognition and object detection.

### a. Support Vector Machines (SVM)
Training and predicting categories based on visual data.
Example:
```cpp
Ptr<cv::ml::SVM> svm = cv::ml::SVM::create();
svm->train(data, cv::ml::ROW_SAMPLE, labels);
```

### b. K-Nearest Neighbors (K-NN)
Classifying objects based on the k-nearest training examples in feature space.
Example:
```cpp
cv::Ptr<cv::ml::KNearest> knn = cv::ml::KNearest::create();
knn->train(trainData, cv::ml::ROW_SAMPLE, responses);
```

## 6.8. Object Detection Using Pre-trained Models
With the integration of the DNN (Deep Neural Network) module, OpenCV supports running pre-trained models for tasks like object detection and
segmentation.
### a. Using Pre-trained Deep Learning Models
**Function:** `cv::dnn::readNetFromCaffe`,  `cv::dnn::readNetFromTensorflow`, `cv::dnn::readNetFromTorch`, etc.   
**Parameters:** Various depending on the framework the model was trained with.
**Example:**
```cpp
auto net = cv::dnn::readNetFromCaffe("model.prototxt", "weights.caffemodel");
```
These functionalities cover a broad spectrum of tasks, from low-level pixel manipulations to high-level algorithms capable of interpreting complex scenes.
OpenCV's expansive suite of tools allows developers to tackle a wide range of computer vision challenges efficiently.
