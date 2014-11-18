# from scapy.all import *
from random import *
from socket import *

HOST = '10.2.29.32'
PORT = 8888
seed(0)

print "Enter no of messages"
n = int(raw_input())
m = n
l = []

while n > 0:
	a = int(raw_input())
	l.append(a)
	n -= 1

t = [[randint(1,100) for x in xrange(m)] for k in xrange(2*m)]

print "CONNECTION ESTABLISHED"
s = socket(AF_INET, SOCK_STREAM)
s.connect((HOST, PORT))

for j in xrange(2*m):
	print "CREATING AND ENCRYPTING PACKET " + str(j+ 1)
	sum1 = sum([l[i] * t[j][i] for i in xrange(m)])
	str1 = ''.join(str(e)+'|' for e in t[j])
	c = str1 + str(sum1) + '\n'
	# t1 = "\x00\x00" hex(a) + hex(b)
	# d = Ether()/IP(options = IPOption(t1))/TCP()/str(
	print "TRANSMITTING PACKET " + str(j+ 1)
	s.send(c + ' '*(1024-len(c)))

print "CONNECTION TERMINATED."
s.close()
