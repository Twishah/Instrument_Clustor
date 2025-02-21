import socket

# Define the host and port for the server
HOST = 'localhost'  # Localhost, change this for remote server
PORT =  0x1235       # Port to bind to (should be > 1024 to avoid privileged ports) 0x1235  

# Create a socket (IPv4, TCP)
server_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)

# Bind the socket to the address and port
server_socket.bind((HOST, PORT))

# Enable the server to accept connections (max 5 clients in the backlog)
server_socket.listen(5)
print(f"Server listening on {HOST}:{PORT}...")

while True:
    # Accept a connection from a client
    client_socket, client_address = server_socket.accept()
    print(f"Connection established with {client_address}")

    # Send a welcome message to the client
    client_socket.sendall(b"Hello, client! You are connected to the TCP server.")

    try:
        # Keep receiving data from the client
        while True:

             data = client_socket.recv(1024)  # Buffer size of 1024 bytes
             if not data:
                break  # Connection closed by the client
             print(f"Received: {data.decode()}")

            # Respond to the client
             client_socket.sendall(b"Message received")

    except Exception as e:
        print(f"Error: {e}")

    finally:
        # Close the client connection

         client_socket.close()
         print(f"Connection with {client_address} closed.")
