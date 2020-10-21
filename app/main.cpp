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
 * @file      main.cpp
 * @author    Mahmoud Dahmani (Driver)
 * @author    Aditya Khopkar (Navigator)
 * @copyright MIT License
 * @brief     Entry point for the application program
 */

#include <iostream>
#include <opencv2/highgui.hpp>
#include "include/tracker.h"

int main(int argc, char* argv[]) {
  cv::VideoCapture stream("data/testVideo.mp4");
  std::unordered_set<std::string> objectClasses{"person", "car"};
  cv::Mat frame;
  cv::Matx34f extP{0, 0, 1, -1, 1, 0, 0, 0, 0, 1, 0, 1};
  cv::Matx33f intP{0.5, 0, 160, 0, 0.5, 160, 0, 0, 1};
  ENPM808X::ObjectTracker tracker(objectClasses, extP, intP);
  std::vector<cv::Point3f> objectLocations;  // system output

  while (stream.read(frame)) {
    objectLocations = tracker.localizeObjects(frame);

    cv::namedWindow("Live", cv::WINDOW_AUTOSIZE);
    cv::imshow("Live", frame);
    if (cv::waitKey(1) >= 0) break;
  }
  return 0;
}
