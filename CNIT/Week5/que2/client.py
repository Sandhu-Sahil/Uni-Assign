import socket

# Create a socket object
client_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)

# Connect to the server
host = '127.0.0.1'  # Replace with the actual IP address of the server
port = 12345
client_socket.connect((host, port))
print(f"Connected to {host}:{port}")

# Get the file path from the user
file_path = input("Enter the path of the file to upload: ")

# Extract the file name from the file path
file_name = file_path.split("/")[-1]

# Send the file name to the server
client_socket.send(file_name.encode())

# Send the file content to the server
with open(file_path, 'rb') as file:
    data = file.read(1024)
    while data:
        client_socket.send(data)
        data = file.read(1024)

print(f"File '{file_name}' has been sent to the server.")

# Close the connection
client_socket.close()
