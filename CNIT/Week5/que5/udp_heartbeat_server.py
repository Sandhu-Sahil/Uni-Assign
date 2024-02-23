import socket
import time

# Create a UDP socket
udp_server_socket = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)

# Bind the socket to a specific address and port
host = '0.0.0.0'  # Bind to all available interfaces
port = 12345
udp_server_socket.bind((host, port))

print(f"UDP Heartbeat Server is listening on {host}:{port}")

# Variables for tracking sequence numbers and timestamps
expected_sequence_number = 1
last_received_timestamp = None

while True:
    # Receive data from the client
    data, addr = udp_server_socket.recvfrom(1024)

    # Decode the data and extract sequence number and timestamp
    try:
        sequence_number, timestamp = map(float, data.decode().split(','))
    except ValueError:
        print("Invalid data received from client.")
        continue

    # Print the received Heartbeat
    print(f"Heartbeat received from {addr}, Sequence Number: {sequence_number}, Timestamp: {timestamp}")

    # Check for lost packets
    if last_received_timestamp is not None:
        expected_sequence_number += 1
        while expected_sequence_number < sequence_number:
            print(f"Lost packet! Expected Sequence Number: {expected_sequence_number}")
            expected_sequence_number += 1

    # Update the last received timestamp
    last_received_timestamp = timestamp

# Close the server socket (Note: This line will never be reached in this example)
udp_server_socket.close()
