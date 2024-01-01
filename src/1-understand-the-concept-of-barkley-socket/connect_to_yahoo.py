import socket

if __name__ == "__main__":
    # Create a socket object
    sock = socket.socket(socket.AF_INET, socket.SOCK_STREAM)

    # Define the IP address and port number
    ip_address = '183.79.250.123'
    port = 80

    # Connect to the server
    sock.connect((ip_address, port))

    # Print a success message
    print(f"Connected to {ip_address} on port {port}")

    # Close the socket
    sock.close()
