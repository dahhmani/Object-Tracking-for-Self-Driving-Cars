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
 * @file      test.cpp
 * @author    Mahmoud Dahmani (Driver)
 * @author    Aditya Khopkar (Navigator)
 * @copyright MIT License
 * @brief     Test Suite for ObjectTracker class methods
 */

#include <gtest/gtest.h>
#include <opencv2/highgui.hpp>
#include "tracker.h"

/**
 * @brief Test fixture for ObjectTracker class
 */
class ObjectTrackerTest : public ::testing::Test {
 protected:
  void SetUp() override {
    std::unordered_set<std::string> objectClasses{"person"};
    cv::Matx34f extP{0, 0, 1, -1, 1, 0, 0, 0, 0, 1, 0, 1};
    cv::Matx33f intP{0.5, 0, 160, 0, 0.5, 160, 0, 0, 1};
    tracker = new ENPM808X::ObjectTracker(objectClasses, extP, intP);
    P = intP * extP;  // camera calibration matrix
  }

  void TearDown() override { delete tracker; }

  ENPM808X::ObjectTracker* tracker;
  cv::Matx34f P;
};

/**
 * @brief Test Case for the localization function of ObjectTracker class
 * Checks if the localiztion method "F" implements the inverse mapping of the
 * camera projection operator "F-1". In mathematical terms, the following
 * condition [F-1(F(pixel_given) == pixel_reconstructed] is evaluated. 
 */
TEST_F(ObjectTrackerTest, LocalizationWorks) {
  cv::Point2i pixel{140, 120};
  cv::Point3f worldPoint{tracker->localizeObjectKeypoint(
      pixel)};  // ground thruth = [-2, -0.975, 0]
  cv::Matx31f pixel_true{static_cast<float>(pixel.x),
                         static_cast<float>(pixel.y), 1},
      pixel_reconstructed;
  cv::Matx41f X{worldPoint.x, worldPoint.y, worldPoint.z, 1};
  pixel_reconstructed = P * X;
  pixel_reconstructed /= pixel_reconstructed(2);
  EXPECT_EQ(pixel_reconstructed, pixel_true);
}

/**
 * @brief Test Case for the multiple object detection function of ObjectTracker
 * Checks if the number of detections matches the number objects in the test
 * image.
 */
TEST_F(ObjectTrackerTest, MultipleHumanDetectionWorks) {
  cv::Mat frame{cv::imread("data/testImage.png")};
  std::vector<cv::Point2i> detections = tracker->detectObjectKeypoints(frame);
  EXPECT_EQ(detections.size(), 2);  // there are 2 humans in this test image
}

/**
 * @brief Test Case for the file parsing function of ObjectTracker class
 * Checks if all the labels in the COCO dataset (which contains 80 classes) are
 * correctly loaded.
 */
TEST_F(ObjectTrackerTest, CocoLabelsAreRead) {
  ASSERT_EQ(tracker->datasetLabels_.size(), 80);
  for (const auto& label : tracker->datasetLabels_) EXPECT_FALSE(label.empty());
}
