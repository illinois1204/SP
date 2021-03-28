import socket
import sys

def StartTCP():
    server_sock = socket.socket()
    server_sock.bind(('', 44444))
    server_sock.listen(1)
    client_sock, addr = server_sock.accept()
    print("Client "+addr[0]+" connected!")
    data = client_sock.recv(128)
    print(data.decode("utf-8"))
    client_sock.close()
    server_sock.close()

def StartUDP():
    server_sock = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
    server_sock.bind(('', 55555))
    data, addr = server_sock.recvfrom(128)
    print("Client "+ addr[0] +" connected!")
    print(data.decode("utf-8"))
    server_sock.close()

print("Server:")
mode = input("Select socket mode TCP[1] or UDP[2]: ")
if mode == "1":
    StartTCP()
elif mode == "2":
    StartUDP()
else:
    print("Wrong")
sys.exit(0)