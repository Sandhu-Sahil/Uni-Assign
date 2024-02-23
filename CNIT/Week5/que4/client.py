import socket
import time

# Create a UDP socket
udp_client_socket = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)

# Server address
server_ip = '127.0.0.1'  # Replace with the actual IP address of the server
server_port = 12345

# Number of pings
num_pings = 10

# Variables for statistics
sent_packets = 0
received_packets = 0
total_rtt = 0
min_rtt = float('inf')
max_rtt = 0

for _ in range(num_pings):
    # Record the time when the packet is sent
    send_time = time.time()

    # Send a ping packet to the server
    udp_client_socket.sendto(b'Ping', (server_ip, server_port))
    sent_packets += 1

    try:
        # Set a timeout for receiving the packet back
        udp_client_socket.settimeout(1.0)

        # Receive the packet back from the server
        data, addr = udp_client_socket.recvfrom(1024)

        # Record the time when the packet is received back
        receive_time = time.time()

        # Calculate the round-trip time (RTT) for the packet
        rtt = (receive_time - send_time) * 1000  # in milliseconds

        # Update statistics
        received_packets += 1
        total_rtt += rtt
        min_rtt = min(min_rtt, rtt)
        max_rtt = max(max_rtt, rtt)

        # Print RTT for each packet
        print(f"Ping reply from {addr}, RTT: {rtt:.2f} ms")

    except socket.timeout:
        # Packet loss (no reply received within the timeout)
        print("Request timed out.")
        pass

# Calculate average RTT and packet loss rate
avg_rtt = total_rtt / received_packets if received_packets > 0 else 0
packet_loss_rate = ((sent_packets - received_packets) / sent_packets) * 100 if sent_packets > 0 else 0

# Print summary statistics
print("\nPing statistics:")
print(f"    Packets: Sent = {sent_packets}, Received = {received_packets}, Lost = {sent_packets - received_packets} ({packet_loss_rate:.2f}% loss)")
print(f"Approximate round-trip times in milliseconds:")
print(f"    Minimum = {min_rtt:.2f} ms, Maximum = {max_rtt:.2f} ms, Average = {avg_rtt:.2f} ms")

# Close the client socket
udp_client_socket.close()
