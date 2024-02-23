import socket
import os

# Create a socket object
server_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)

# Bind the socket to a specific address and port
host = '0.0.0.0'  # Bind to all available interfaces
port = 12345
server_socket.bind((host, port))

# Listen for incoming connections
server_socket.listen(1)
print(f"Server is listening on {host}:{port}")

# Accept a connection from a client
client_socket, addr = server_socket.accept()
print(f"Connection from {addr}")

# Receive the file name from the client
file_name = client_socket.recv(1024).decode()
file_path = os.path.join('uploads', file_name)

# Receive and save the file content
with open(file_path, 'wb') as file:
    data = client_socket.recv(1024)
    while data:
        file.write(data)
        data = client_socket.recv(1024)

print(f"File '{file_name}' has been uploaded to the server.")

# Close the connection
client_socket.close()
server_socket.close()
