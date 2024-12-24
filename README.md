Qt-Cascade-App

✨ Project Overview

The Qt-Cascade-App is a powerful desktop application developed using the Qt framework and OpenCV library. It is designed to perform object detection tasks utilizing Haar cascade classifiers. With an intuitive graphical user interface (GUI), users can load images or video streams, apply trained classifiers, and visualize detection results seamlessly.

🔧 Key Features

🔍 Object DetectionDetect objects such as faces, eyes, or custom-trained objects within images or video streams using Haar cascade classifiers.

⏳ Real-time ProcessingSupports real-time object detection for live video feeds.

🔐 User-Friendly GUIIntuitive interface built with Qt Designer, enabling effortless loading of media, selecting classifiers, and viewing results.

🚀 How to Use

Launch the Application: Run the executable after building the project.

Load Media: Use the GUI to load an image or select a video source.

Select Cascade Classifier: Choose a pre-trained Haar cascade XML file for the object you wish to detect.

Start Detection: Initiate detection to process the media and visualize results in the display area.

🛠️ Installation

Follow these steps to set up the Qt-Cascade-App on your local machine:

Clone the repository:

git clone https://github.com/ZiadMD/Qt-Cascade-App.git

Navigate to the project directory:

cd Qt-Cascade-App

Install dependencies:

Qt Framework: Download and install Qt from the official website.

OpenCV Library: Install OpenCV suitable for your development environment. Refer to the OpenCV installation guide.

Build the project:

Open the project file (Lin_Cpp_OpenCV.pro) in Qt Creator.

Configure the project with the necessary kits.

Build and run the project within Qt Creator.

🕁 File Overview

main.cpp: Entry point of the application.

cv_01.ui: User interface layout designed with Qt Designer.

cascadeloader.cpp & cascadeloader.h: Handles loading of Haar cascade classifier files.

objectdetector.cpp & objectdetector.h: Contains logic for applying cascade classifiers to detect objects.

frameconvertor.cpp & frameconvertor.h: Manages conversion between image formats required by OpenCV and Qt.

🙏 Contribution

Contributions are welcome! Feel free to fork the repository and submit a pull request with your proposed changes. Please ensure your code adheres to the project's coding standards and includes proper documentation.

