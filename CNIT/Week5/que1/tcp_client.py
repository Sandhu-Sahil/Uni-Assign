import socket

# Create a TCP socket
tcp_client_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)

# Connect to the server
server_ip = '127.0.0.1'  # Replace with the server's IP address
server_port = 12345  # Replace with the server's port number
tcp_client_socket.connect((server_ip, server_port))
print(f"Connected to TCP server at {server_ip}:{server_port}")

# Send a string to the server
message = "network"
tcp_client_socket.send(message.encode())

# Receive the modified string from the server
modified_message = tcp_client_socket.recv(80).decode()
print(f"Received from TCP server: {modified_message}")

# Close the client socket
tcp_client_socket.close()
