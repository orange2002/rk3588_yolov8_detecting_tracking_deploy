

#pragma once
#include "opencv2/opencv.hpp"

struct frame_with_time
{
  std::unique_ptr<cv::Mat> frame;
  std::chrono::_V2::system_clock::time_point timestamp;
};
class Camera
{
public:
  int width() const { return m_width; }
  int height() const { return m_height; }
  Camera(uint16_t index, cv::Size size, double framerate);
  Camera(const std::string&rtsp_url, cv::Size size, double framerate);
  ~Camera();
  std::unique_ptr<cv::Mat> GetNextFrame();
 private:
  int m_width;
    int m_height;
  cv::Size size_;
  cv::VideoCapture capture_;
};
