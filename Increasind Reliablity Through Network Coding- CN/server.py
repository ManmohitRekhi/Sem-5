from numpy import matrix
from numpy import linalg
from random import *
from socket import *

HOST = '10.1.10.4'
PORT = 8888

s = socket(AF_INET, SOCK_STREAM) 
s.bind((HOST,PORT))
s.listen(1)


conn, addr = s.accept()
print "CONNECTION ESTABLISHED"
print 'Connected By', addr

i = 0
l = []
m = []
while True:
	data1 = conn.recv(1024)
	print "PACKET " + str(i + 1) + " RECIEVED"
	point1 = list(map(int, data1.split("|")))
	n = 2*(len(point1) -1)
	l.append(point1[:len(point1) - 1])
	m.append(point1[-1])
	i += 1
	if i == n: break
	
seed(0)
k = []
l1 = []
m1 = []

print "DECRYPTING PACKETS"

while len(k) != i/2:
	z = randint(0,i-1)
	if z not in k:
		k.append(z)
		l1.append(l[z])
		m1.append(m[z])


ans = linalg.solve(matrix(l1), matrix(m1).T)
for p in ans: print str(float(p[0])).split(".")[0]

conn.close() 
