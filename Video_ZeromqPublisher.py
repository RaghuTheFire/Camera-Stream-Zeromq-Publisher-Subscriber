
import cv2
import zmq

# Initialize OpenCV video capture
cap = cv2.VideoCapture(0)  # 0 for default camera

# Initialize ZeroMQ context and socket
context = zmq.Context()
socket = context.socket(zmq.PUB)
socket.bind("tcp://*:5555")  # Bind to a local port

while True:
    # Capture frame from OpenCV
    ret, frame = cap.read()

    # Encode the frame as JPEG
    _, buffer = cv2.imencode('.jpg', frame)

    # Send the frame over ZeroMQ
    socket.send(buffer.tobytes())

# Release resources
cap.release()
cv2.destroyAllWindows()
