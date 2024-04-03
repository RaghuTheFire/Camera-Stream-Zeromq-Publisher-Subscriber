#include <iostream>
#include <opencv2/opencv.hpp>
#include <zmq.hpp>

int main() 
{
  // Initialize ZeroMQ context
  zmq::context_t context(1);
  zmq::socket_t publisher(context, ZMQ_PUB);
  publisher.bind("tcp://*:5555");

  // Open the camera
  cv::VideoCapture cap(0);
  if (!cap.isOpened()) 
  {
    std::cerr << "Error opening video stream or file" << std::endl;
    return -1;
  }

  while (true) 
  {
    cv::Mat frame;
    cap >> frame;

    // Serialize the frame to a binary message
    std::vector < uchar > buffer;
    cv::imencode(".jpg", frame, buffer);

    // Send the frame over ZeroMQ
    zmq::message_t message(buffer.size());
    memcpy(message.data(), buffer.data(), buffer.size());
    publisher.send(message, zmq::send_flags::none);
  }

  return 0;
}
