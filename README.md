[![Build Status](https://travis-ci.org/dahhmani/Object-Tracking-for-Self-Driving-Cars.svg?branch=master)](https://travis-ci.org/dahhmani/Object-Tracking-for-Self-Driving-Cars)
[![Coverage Status](https://coveralls.io/repos/github/dahhmani/Object-Tracking-for-Self-Driving-Cars/badge.svg?branch=master)](https://coveralls.io/github/dahhmani/Object-Tracking-for-Self-Driving-Cars?branch=master)
[![License: MIT](https://img.shields.io/badge/License-MIT-yellow.svg)](https://opensource.org/licenses/MIT)  
# Real-Time Pedestrian Tracker for Self-Driving Cars

## Overview
This project implements a real-time multiple object tracker which can be utilized as a forward collision warning system or as an autonomous emergency braking (AEB) safety feature for self-driving cars. The implemented tracker performs multiple object localization at 45 frames per second (FPS) on a GEFORCE GTX 1660 Ti NVIDIA GPU; it outputs the 3D positions (x,y,z) of the tracked objects (pedastrian, car, ...) expressed in units of meters with respect to the robot (i.e. vehicle) frame.  
Our approach is split into two stages. First, bounding boxes are drawn around pedastrians (and other objects of interest) and then, their corresponding keypoints are computed. Second, the homography mapping from the road plane to the image plane is derived from the camera projection matrix, whose inverse will project back the object keypoints to 3D world points.  
A demo video of our tracker in action can be found [here](https://drive.google.com/drive/folders/1pjisMWkS4lK52McusZOWmdMX13w2TEu8?usp=sharing).

## Authors
1. [Mahmoud Dahmani](https://www.linkedin.com/in/mahmouddahmani/)
2. [Aditya Khopkar](https://www.linkedin.com/in/akhopkar/)

## Requirements
* Ubuntu 18.04 (Operating System)
* C++17 (Programming Language)
* CMake / Make (Build Framework)

## Build
Run the following commands in a new terminal:
```
git clone --recursive https://github.com/dahhmani/Object-Tracking-for-Self-Driving-Cars
cd <path to repository>/scripts/
sh install_opencv.sh
sh download_pretrained_model.sh
sh build.sh
```

## Run
The system takes 4 inputs, which can be configured from ```include/config.h```
1. video source: path to a video file or index of a camera device
2. types of objects that will be tracked: any subset of the COCO dataset classes
3. camera extrinsic parameters: a 3x4 matrix
4. camera intrinsic parameters: a 3x3 matrix
The demo can be run using the default configuration.

### App
Run the following commands in a new terminal:
```
cd <path to repository>/scripts/
sh run_app.sh
```

### Tests
Run the following commands in a new terminal:
```
cd <path to repository>/scripts/
sh run_tests.sh
```

## Development Process
Agile iterative process (AIP) was followed through this project. The roles are divided into driver (Mahmoud Dahmani) and navigator (Aditya Khopkar).  
All backlogs, Sprint planning and review notes can be found [here](https://drive.google.com/drive/folders/1M25OvjuNuzUbvEtvly1plpnj0qtGmckk?usp=sharing). The presentation video can be found [here](https://drive.google.com/drive/folders/1pjisMWkS4lK52McusZOWmdMX13w2TEu8?usp=sharing).

## Doxygen Documentation
To install Doxygen, run the following commands in a new terminal:
```
sudo apt install doxygen
```
To generate the Doxygen documentation, run the following commands in a new terminal:
```
doxygen Doxyfile
```


