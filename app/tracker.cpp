/*******************************************************************************
 MIT License

 Copyright (c) 2020 Mahmoud Dahmani, Aditya Khopkar

 Permission is hereby granted, free of charge, to any person obtaining a copy
 of this software and associated documentation files (the "Software"), to deal
 in the Software without restriction, including without limitation the rights
 to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 copies of the Software, and to permit persons to whom the Software is
 furnished to do so, subject to the following conditions:

 The above copyright notice and this permission notice shall be included in all
 copies or substantial portions of the Software.

 THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 SOFTWARE.
*******************************************************************************/

/**
 * @file      tracker.cpp
 * @author    Mahmoud Dahmani (Driver)
 * @author    Aditya Khopkar (Navigator)
 * @copyright MIT License
 * @brief     ObjectTracker class implementation
 */

#include "include/tracker.h"
#include <stdio.h>
#include <iostream>
#include <fstream>
#include <opencv2/imgproc.hpp>

ENPM808X::ObjectTracker::ObjectTracker(
    const std::unordered_set<std::string>& objectClasses,
    const cv::Matx34f& extP, const cv::Matx33f& intP,
    const std::string& detectionModel, float minConfidence, float minOverlap)
    : objectClasses_{objectClasses},
      minConfidence_{minConfidence},
      minOverlap_{minOverlap} {}

std::vector<cv::Point3f> ENPM808X::ObjectTracker::localizeObjects(
    cv::Mat frame) {
  std::vector<cv::Point3f> dummyOutput{{0, 0, 0}};

  return dummyOutput;
}

cv::Point3f ENPM808X::ObjectTracker::localizeObjectKeypoint(
    const cv::Point2i& object) const {
  cv::Point3f dummyOutput{0, 0, 0};

  return dummyOutput;
}

std::vector<cv::Point2i> ENPM808X::ObjectTracker::detectObjectKeypoints(
    cv::Mat frame) {
  std::vector<cv::Point2i> dummyOutput{{0, 0}};

  return dummyOutput;
}

std::vector<std::string> ENPM808X::ObjectTracker::parseFile(
    const std::string& fileName) const {
  std::vector<std::string> dummyOutput{""};

  return dummyOutput;
}
