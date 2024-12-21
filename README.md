# Lin C++ OpenCV Project

## Overview
This project is a C++ application that utilizes OpenCV and Qt for real-time object detection. It provides functionalities to detect faces, eyes, and bodies using Haar cascades and LBPC cascades. The application features a user interface built with Qt, allowing users to interact with video feeds and images.

## Features
- **Real-time face detection**
  - Code Snippet:
    ```cpp
    void detect(cv::Mat& frame); // Declaration of the detect function
    ```

- **Eye detection (left, right, both)**
  - Code Snippet:
    ```cpp
    void performDetection(cv::Mat& frame, cv::CascadeClassifier& cascade, const cv::Scalar& color);
    ```

- **Body detection**
  - Code Snippet:
    ```cpp
    std::string bodyDetectorPath = "/path/to/haarcascade_fullbody.xml";
    cv::CascadeClassifier bodyCascade;
    ```

- **Support for video and image inputs**
  - Code Snippet:
    ```cpp
    void on_videoOpenButton_clicked();
    void on_photoOpenButton_clicked();
    ```

- **Camera integration**
  - Code Snippet:
    ```cpp
    void on_startCameraButton_clicked();
    ```
=======
- **Real-time face detection**
-   - Code Snippet:
-     ```cpp
-     void detect(cv::Mat& frame); // Declaration of the detect function
-     ```
-
- - **Eye detection (left, right, both)**
-   - Code Snippet:
-     ```cpp
-     void performDetection(cv::Mat& frame, cv::CascadeClassifier& cascade, const cv::Scalar& color);
-     ```
-
- - **Body detection**
-   - Code Snippet:
-     ```cpp
-     std::string bodyDetectorPath = "/path/to/haarcascade_fullbody.xml";
-     cv::CascadeClassifier bodyCascade;
-     ```
-
- - **Support for video and image inputs**
-   - Code Snippet:
-     ```cpp
-     void on_videoOpenButton_clicked();
-     void on_photoOpenButton_clicked();
-     ```
-
- - **Camera integration**
-   - Code Snippet:
-     ```cpp
-     void on_startCameraButton_clicked();
-     ```
-     void on_startCameraButton_clicked();
-   - Code Snippet:
-     void on_photoOpenButton_clicked();
-   - Code Snippet:
-     cv::CascadeClassifier bodyCascade;
-   - Code Snippet:
-     void performDetection(cv::Mat& frame, cv::CascadeClassifier& cascade, const cv::Scalar& color);
-   - Code Snippet:
-     void detect(cv::Mat& frame); // Declaration of the detect function
-   - Code Snippet:

## Requirements
- C++11 or later
- Qt 5 or later
- OpenCV 4.x
- CMake (for building the project)

## Setup
1. Clone the repository:
   ```bash
   git clone <repository-url>
   cd Lin_Cpp_OpenCV
   ```

2. Install the required dependencies:
   - Ensure you have Qt and OpenCV installed on your system.

3. Build the project:
   ```bash
   qmake
   make
   ```

4. Run the application:
   ```bash
   ./Lin_Cpp_OpenCV
   ```

## Usage
- Open a video file or start the camera to begin detection.
- Use the interface buttons to control video playback and detection options.
- Select detection types (face, eyes, body) using the provided checkboxes.

## File Structure
- `main.cpp`: Entry point of the application.
- `cv_01.h`: Main window class definition.
- `objectdetector.h`: Class for handling object detection logic.
- `frameconvertor.h`: Utility for converting between QImage and OpenCV Mat.
- `detectionsettings.h`: Class for managing detection settings.
- `cascadeloader.h`: Utility for loading Haar and LBP cascades.

## License
This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.
