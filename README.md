# Qt-Cascade-App

## ✨ Project Overview

The **Qt-Cascade-App** is a powerful desktop application developed using the **Qt framework** and **OpenCV library**. It is designed to perform object detection tasks utilizing **Haar cascade classifiers**. With an intuitive graphical user interface (GUI), users can load images or video streams, apply trained classifiers, and visualize detection results seamlessly.

---

## 🔧 Key Features

- **🔍 Object Detection**  
  Detect objects such as faces, eyes, or custom-trained objects within images or video streams using Haar cascade classifiers.

- **⏳ Real-time Processing**  
  Supports real-time object detection for live video feeds.

- **🔐 User-Friendly GUI**  
  Intuitive interface built with **Qt Designer**, enabling effortless loading of media, selecting classifiers, and viewing results.

---

## 🚀 How to Use

1. **Launch the Application**: Run the executable after building the project.
2. **Load Media**: Use the GUI to load an image or select a video source.
3. **Select Cascade Classifier**: Choose a pre-trained Haar cascade XML file for the object you wish to detect.
4. **Start Detection**: Initiate detection to process the media and visualize results in the display area.

---

## 🛠️ Installation

Follow these steps to set up the Qt-Cascade-App on your local machine:

1. Clone the repository:
   ```bash
   git clone https://github.com/ZiadMD/Qt-Cascade-App.git
   ```

2. Navigate to the project directory:
   ```bash
   cd Qt-Cascade-App
   ```

3. Install dependencies:
   - **Qt Framework**: Download and install Qt from the [official website](https://www.qt.io/download).
   - **OpenCV Library**: Install OpenCV suitable for your development environment. Refer to the [OpenCV installation guide](https://docs.opencv.org/master/df/d65/tutorial_table_of_content_introduction.html).

4. Build the project:
   - Open the project file (`Lin_Cpp_OpenCV.pro`) in **Qt Creator**.
   - Configure the project with the necessary kits.
   - Build and run the project within Qt Creator.

---

## 🔍 File Overview

- **`main.cpp`**: Entry point of the application.
- **`cv_01.ui`**: User interface layout designed with Qt Designer.
- **`cascadeloader.cpp` & `cascadeloader.h`**: Handles loading of Haar cascade classifier files.
- **`objectdetector.cpp` & `objectdetector.h`**: Contains logic for applying cascade classifiers to detect objects.
- **`frameconvertor.cpp` & `frameconvertor.h`**: Manages conversion between image formats required by OpenCV and Qt.

---

## ⚡ Performance Optimizations

The application has been optimized for efficient real-time object detection:

- **Grayscale Conversion Optimization**: Frames are converted to grayscale once per cycle and reused for all detection types, eliminating redundant conversions.

- **Optimized Detection Parameters**: Cascade classifiers use tuned parameters (`scaleFactor: 1.1`, `minNeighbors: 3`, `minSize: 30x30`) to balance speed and accuracy.

- **Early Exit Strategy**: Detection processing is skipped entirely when no detectors are enabled, improving performance during video playback without detection.

- **Fast Frame Scaling**: Uses Qt's `FastTransformation` mode for real-time scaling with maintained aspect ratio.

- **Memory-Safe Conversions**: Frame format conversions use separate output buffers to prevent side effects and ensure thread safety.

---

## 🙏 Contribution

Contributions are welcome! Feel free to fork the repository and submit a pull request with your proposed changes. Please ensure your code adheres to the project's coding standards and includes proper documentation.
