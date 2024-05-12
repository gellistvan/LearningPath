# 5. Transformations
In OpenCV, transformations are operations that change the geometry of the image, such as translating, rotating, resizing, and warping. These transformations are crucial for tasks like image registration, object tracking, and camera calibration. Let’s delve into some common image transformations provided by OpenCV, their parameters, and usage scenarios.

## 5.1. Scaling (Resizing)
Scaling is used to change the size of an image. It can be performed using the `cv::resize` function. 
```cpp
void resize(const cv::Mat& src, cv::Mat& dst, cv::Size size, double fx = 0, double fy = 0, int interpolation = cv::INTER_LINEAR);
```

**Parameters**
* **src:** Input image.
* **dst:** Output image.
* **size:** Desired size for the output image.
* **fx, fy:** Scale factors along the horizontal and vertical axes. If they're specified, `size` is ignored.
* **interpolation:** Interpolation method. Options include
  * `cv::INTER_LINEAR`,: Good for zooming.
  * `cv::INTER_NEAREST`,
  * `cv::INTER_AREA`,: Recommended for image decimation.
  * `cv::INTER_CUBIC`,
  * `cv::INTER_LANCZOS4`.

**Example:**
```cpp
cv::Mat src, dst;
src = cv::imread("path/to/image.jpg");
cv::resize(src, dst, cv::Size(), 0.5, 0.5, cv::INTER_LINEAR);
```

## 5.2. Translation

Translation shifts the position of an image within its frame. 
**Methodology:** define a translation matrix and use `cv::warpAffine` to apply it. Translation matrix is a matrix 

$T = \begin{bmatrix} 1 & 0 & T_x\\ 0 & 1 & T_y \end{bmatrix}$

**Example:**
```cpp
int tx = 100; // Shift 100 pixels to the right
int ty = 50; // Shift 50 pixels down
cv::Mat trans_mat = (cv::Mat_<double>(2,3) << 1, 0, tx, 0, 1, ty);
cv::warpAffine(src, dst, trans_mat, src.size());
```

## 5.3. Rotation
Rotation transforms the image for a specified angle.
**Methodology:** `cv::getRotationMatrix2D` is used to create a rotation matrix, then `cv::warpAffine` applies the rotation.  
```cpp
cv::Mat getRotationMatrix2D(cv::Point2f center, double angle, double scale);
```

***Parameters**
**center:** Center of the rotation in the source image.
**angle:** Rotation angle in degrees. Positive values mean counter-clockwise rotation.
**scale:** Isotropic scale factor.

**Example:**
```cpp
cv::Mat rot_mat = cv::getRotationMatrix2D(cv::Point2f(src.cols/2.0, src.rows/2.0), 45, 1);
cv::warpAffine(src, dst, rot_mat, src.size());
```

## 5.4. Image Flipping
Flipping is a simple transformation that reverses the order of pixels along the horizontal or vertical axis, or both.
```cpp
void flip(const cv::Mat& src, cv::Mat& dst, int flipCode);
```

**Parameters**
* **src:** Input image.
* **dst:** Output image (flipped image). The output (dst) and the input (src) cannot be the same objects
* **flipCode:**
  * `0`: Flip vertically (around the x-axis).
  * `>0`: Flip horizontally (around the y-axis).
  * `<0`: Flip both vertically and horizontally.

## 5.5. Affine Transformation
Affine transformations let you perform operations like rotation, translation, and scaling all at once by specifying the coordinates of three points before and after the transformation.
**Methodology:** define three points in the source image and their corresponding locations in the output image.  `cv::getAffineTransform` computes the transformation matrix.
**Example:**
```cpp
cv::Point2f srcTri[3];
cv::Point2f dstTri[3];
srcTri[0] = cv::Point2f(0, 0);
srcTri[1] = cv::Point2f(src.cols - 1, 0);
srcTri[2] = cv::Point2f(0, src.rows - 1);
dstTri[0] = cv::Point2f(src.cols*0.0, src.rows*0.33);
dstTri[1] = cv::Point2f(src.cols*0.85, src.rows*0.25);
dstTri[2] = cv::Point2f(src.cols*0.15, src.rows*0.7);
cv::Mat warp_mat = cv::getAffineTransform(srcTri, dstTri);
cv::warpAffine(src, dst, warp_mat, src.size());
```

## 5.6. Perspective Transformation
Perspective transformation, or homography, allows you to perform complex transformations that alter the perspective from which an image is viewed. It's often used for tasks like image rectification, panorama stitching, and 3D reconstruction.

**Methodology:** define four pairs of points: points in the source image and their corresponding points in the destination image. You need at least four point pairs to calculate a perspective transformation matrix. Use `cv::getPerspectiveTransform` to compute a transformation matrix. 
```cpp
cv::Mat getPerspectiveTransform(const Point2f src[], const Point2f dst[]);
```

**Parameters**
* **src:** Array of four points in the source image.
* **dst:** Array of four points in the destination image where the source points are supposed to map.

**Example:**
```cpp
cv::Point2f srcVertices[4];
cv::Point2f dstVertices[4];

// Assume these points are predefined in both src and dst images
srcVertices[0] = cv::Point2f(10, 10);
srcVertices[1] = cv::Point2f(100, 10);
srcVertices[2] = cv::Point2f(100, 100);
srcVertices[3] = cv::Point2f(10, 100);
dstVertices[0] = cv::Point2f(15, 20);
dstVertices[1] = cv::Point2f(85, 30);
dstVertices[2] = cv::Point2f(95, 95);
dstVertices[3] = cv::Point2f(20, 80);

// Calculate the perspective transform matrix
cv::Mat perspectiveMatrix = cv::getPerspectiveTransform(srcVertices, dstVertices);

// Apply the perspective transformation to the image
cv::Mat dstImage;
cv::warpPerspective(src, dstImage, perspectiveMatrix, src.size());
```

**Key Usage Scenarios for Perspective Transform**
* **Image Rectification:** Correcting the perspective in images taken at an angle.
* **Panorama Stitching:** Aligning multiple photographs into a single panoramic image.
* **Augmented Reality:** Overlaying graphics on images in correct perspective.
* **3D Visualizations:** Simulating different viewpoints of a 3D scene from 2D images.

## Additional Tips
* **Accurate point selection is crucial.** Errors in point correspondences can lead to incorrect transformations. For real-world applications, often
these point correspondences are found automatically using feature matching algorithms like SIFT, SURF, or ORB.
* **Performance considerations:** `cv::warpPerspective` can be computationally intensive, especially at higher resolutions. Optimization techniques
such as using region of interest (ROI) to limit the processing to pertinent areas can enhance performance.
* **The use of these transformations** in OpenCV allows for the manipulation of images in ways that can significantly adjust or enhance their
geometric attributes, adapting images for various analytical needs and visual effects.

## Example Integration
Here's how you can modify the previous object tracking example to include flipping and a rotation, which can be useful for adapting the video feed orientation:

```cpp
#include <opencv2/opencv.hpp>
#include <iostream>
using namespace cv;
using namespace std;
int main() {
    VideoCapture cap(0); // Open the default camera
    if (!cap.isOpened()) {
        cerr << "Error opening video stream" << endl;
        return -1;
    }
    
    Mat frame, hsv, mask, morphed;
    vector<vector<Point>> contours;
    vector<Vec4i> hierarchy;

    Scalar lower_red(0, 120, 70);
    Scalar upper_red(10, 255, 255);
    while (true) {
        cap >> frame;
        if (frame.empty())
                break;
        
        // Flip and Rotate the frame
        flip(frame, frame, 1); // Flip horizontally
        Mat rot_mat = getRotationMatrix2D(Point2f(frame.cols/2.0, frame.rows/2.0), 90, 1);
        warpAffine(frame, frame, rot_mat, frame.size()); // Rotate 90 degrees
       
        cvtColor(frame, hsv, COLOR_BGR2HSV);
        inRange(hsv, lower_red, upper_red, mask);
        
        erode(mask, morphed, Mat(), Point(-1, -1), 2);
        dilate(morphed, morphed, Mat(), Point(-1, -1), 2);
        
        findContours(morphed, contours, hierarchy, RETR_TREE, CHAIN_APPROX_SIMPLE);
        for (size_t i = 0; i < contours.size(); i++) {
            Rect rect = boundingRect(contours[i]);
            rectangle(frame, rect, Scalar(0, 255, 0), 2);
            
            Point center = Point(rect.x + rect.width / 2, rect.y + rect.height / 2);
            circle(frame, center, 5, Scalar(255, 0, 0), -1);
        }
        
        imshow("Object Tracking", frame);
        if (waitKey(10) == 27)
                break;
    }
    cap.release();
    destroyAllWindows()

    return 0;
}
```
This example shows how to integrate flipping and rotating transformations within a video processing loop, effectively preparing the video frames for object detection and tracking regardless of the camera orientation.