#include <iostream>
#include <opencv2/opencv.hpp>
#include <zmq.hpp>

int main() 
{
  // Initialize ZeroMQ context
  zmq::context_t context(1);

  // Create a ZeroMQ subscriber socket
  zmq::socket_t subscriber(context, ZMQ_SUB);
  subscriber.connect("tcp://localhost:5555");
  subscriber.setsockopt(ZMQ_SUBSCRIBE, "", 0);

  // Create an OpenCV window
  cv::namedWindow("Video Frame", cv::WINDOW_AUTOSIZE);

  while (true) 
  {
    // Receive video frame from ZeroMQ
    zmq::message_t frame;
    subscriber.recv( & frame);

    // Convert the received data to an OpenCV Mat
    cv::Mat image = cv::imdecode(cv::Mat(1, frame.size(), CV_8UC1, frame.data()), cv::IMREAD_COLOR);

    // Display the video frame
    cv::imshow("Video Frame", image);

    // Wait for a key press to exit the loop
    if (cv::waitKey(1) == 27) 
    {
      break;
    }
  }

  return 0;
}
