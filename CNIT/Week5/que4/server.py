import socket
import time

# Create a UDP socket
udp_server_socket = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)

# Bind the socket to a specific address and port
host = '0.0.0.0'  # Bind to all available interfaces
port = 12345
udp_server_socket.bind((host, port))

print(f"UDP Server is listening on {host}:{port}")

# Variables for statistics
total_packets = 0
total_rtt = 0
min_rtt = float('inf')
max_rtt = 0
packet_loss_count = 0

while True:
    # Receive data from the client
    data, addr = udp_server_socket.recvfrom(1024)

    # Record the time when the packet is received
    receive_time = time.time()

    # Send the packet back to the client
    udp_server_socket.sendto(data, addr)

    # Record the time when the packet is sent back
    send_back_time = time.time()

    # Calculate the round-trip time (RTT) for the packet
    rtt = (send_back_time - receive_time) * 1000  # in milliseconds

    # Update statistics
    total_packets += 1
    total_rtt += rtt
    min_rtt = min(min_rtt, rtt)
    max_rtt = max(max_rtt, rtt)

    # Print RTT for each packet
    print(f"Ping from {addr}, RTT: {rtt:.2f} ms")

# Close the server socket (Note: This line will never be reached in this example)
udp_server_socket.close()
