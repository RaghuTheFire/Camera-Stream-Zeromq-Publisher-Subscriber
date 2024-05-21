
import cv2
import zmq

# Create a ZeroMQ context
context = zmq.Context()

# Create a ZeroMQ socket for receiving video frames
socket = context.socket(zmq.SUB)
socket.connect("tcp://localhost:5555")  # Replace with the appropriate address and port
socket.setsockopt(zmq.SUBSCRIBE, b'')  # Subscribe to all messages

while True:
    # Receive the video frame from the socket
    frame_data = socket.recv()

    # Decode the received data into a NumPy array
    frame = cv2.imdecode(np.frombuffer(frame_data, dtype=np.uint8), cv2.IMREAD_COLOR)

    # Display the video frame
    cv2.imshow('Video', frame)

    # Check for the 'q' key to exit
    if cv2.waitKey(1) & 0xFF == ord('q'):
        break

# Clean up
cv2.destroyAllWindows()
socket.close()
context.term()
