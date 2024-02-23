import socket

# Create a UDP socket
udp_client_socket = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)

# Connect to the server
server_ip = '127.0.0.1'  # Replace with the server's IP address
server_port = 12346  # Replace with the server's port number

# Send a string to the server
message = "network"
udp_client_socket.sendto(message.encode(), (server_ip, server_port))

# Receive the modified string from the server
modified_message, addr = udp_client_socket.recvfrom(80)
print(f"Received from UDP server: {modified_message.decode()}")

# Close the client socket
udp_client_socket.close()
