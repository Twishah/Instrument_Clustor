import can

# Define the host and port for the server
HOST = 'localhost'  # Localhost, change this for remote server
PORT =  0x1235       # Port to bind to (should be > 1024 to avoid privileged ports) 0x1235  

# create a CAN bus interface using the TCP-IP connection
bus = can.interface.Bus(channel='can0', bustype='socketcan', ip=HOST, port=PORT)
print(f"Server listening on {HOST}:{PORT}...")

while True:
    print(f"Connection established with {HOST}:{PORT}...")

    try:
        # Keep receiving data from the client
        while True:
             message = bus.recv()
             if message is not None:
             	print(f"Received message: {message}")

    except Exception as e:
        print(f"Error: {e}")

    finally:
        # Close the client connection
         bus.shutdown()
         print(f"Connection with {client_address} closed.")
