import socket
import time

# Create a UDP socket
udp_client_socket = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)

# Server address
server_ip = '127.0.0.1'  # Replace with the actual IP address of the server
server_port = 12345

# Heartbeat interval in seconds
heartbeat_interval = 2.0

# Sequence number for each heartbeat
sequence_number = 1

while True:
    # Record the current time on the client
    timestamp = time.time()

    # Create a heartbeat packet with sequence number and timestamp
    heartbeat_packet = f"{sequence_number},{timestamp}"

    # Send the heartbeat packet to the server
    udp_client_socket.sendto(heartbeat_packet.encode(), (server_ip, server_port))

    # Print information about the sent heartbeat
    print(f"Heartbeat sent: Sequence Number: {sequence_number}, Timestamp: {timestamp}")

    # Increment the sequence number
    sequence_number += 1

    # Wait for the next heartbeat interval
    time.sleep(heartbeat_interval)

# Close the client socket (Note: This line will never be reached in this example)
udp_client_socket.close()
