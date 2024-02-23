import socket

def handle_tcp_client(client_socket):
    data = client_socket.recv(80).decode()
    reversed_data = data[::-1].swapcase()
    client_socket.send(reversed_data.encode())
    client_socket.close()

# Create a TCP socket
tcp_server_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)

# Bind the socket to a specific address and port
tcp_server_socket.bind(('127.0.0.1', 12345))

# Listen for incoming connections
tcp_server_socket.listen(1)
print("TCP Server is listening on port 12345")

# Accept a connection from a client
client_socket, addr = tcp_server_socket.accept()
print(f"Connection from {addr}")

# Handle the client's request
handle_tcp_client(client_socket)

# Close the server socket
tcp_server_socket.close()
