import socket

# Create a UDP socket
udp_server_socket = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)

# Bind the socket to a specific address and port
udp_server_socket.bind(('127.0.0.1', 12346))

print("UDP Server is listening on port 12346")

# Receive data from the client
data, addr = udp_server_socket.recvfrom(80)
reversed_data = data.decode()[::-1].swapcase()

# Send the modified string back to the client
udp_server_socket.sendto(reversed_data.encode(), addr)

# Close the server socket
udp_server_socket.close()
