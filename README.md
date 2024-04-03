# Video_ZeromqPublisher.cpp



# Video_ZeromqSubscriber.cpp
This C++ code is a program that receives video frames from a ZeroMQ (Zero Message Queue) subscriber socket and displays them in an OpenCV window. 
Here's a breakdown of what the code does: 
1. The program includes the necessary header files: `<iostream>` for input/output operations, `<opencv2/opencv.hpp>` for OpenCV functions, and `<zmq.hpp>` for ZeroMQ functionality.
2. The `main()` function is the entry point of the program.
3. Inside the `main()`, the program initializes a ZeroMQ context with a single I/O thread.
4. It then creates a ZeroMQ subscriber socket and connects it to the "tcp://localhost:5555" address, which is likely where the video frames are being published.
5. The program sets the socket option to subscribe to all messages (by passing an empty string as the subscription topic).
6. Next, it creates an OpenCV window named "Video Frame" with the `cv::WINDOW_AUTOSIZE` option, which automatically adjusts the window size to fit the displayed image.
7. The program then enters a `while` loop that continues until the user presses the "Esc" key (ASCII code 27).
8. Inside the loop, the program receives a video frame from the ZeroMQ subscriber socket using the `subscriber.recv()` function, which stores the frame data in a `zmq::message_t` object.
9. The received frame data is then converted to an OpenCV `cv::Mat` object using the `cv::imdecode()` function, which decodes the raw data into a color image.
10. The program displays the video frame in the "Video Frame" window using the `cv::imshow()` function.
11. Finally, the program waits for a key press using `cv::waitKey(1)`, and if the "Esc" key is pressed, the loop is exited.
12. The program returns 0 to indicate successful execution. In summary, this code sets up a ZeroMQ subscriber to receive video frames and displays them in an OpenCV window, allowing the user to view the incoming video stream.
