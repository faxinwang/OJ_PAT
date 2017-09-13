class Node(object):
    def __init__(self, address, data, next):
        self.add = address
        self.data = data
        self.next = next

start,N,K = input().split()
N,K = int(N),int(K)
d = {}
for i in range(N ):
    add, data, next = input().split()
    d[add] = Node(add,data,next)
L = []
cur = d[start];
if cur.next == '-1': L.append(cur) #if there is just only one Node
while cur.next != '-1':
    tmp,t= [],K
    while t > 0 and cur.next != '-1':
        tmp.append(cur)
        cur = d[cur.next]
        t -= 1
    if cur.next == '-1': tmp.append(cur)
    if len(tmp) == K: tmp.reverse()
    L += tmp
N = len(L)
for i in range(N-1): print(L[i].add,L[i].data,L[i+1].add)
print(L[N-1].add, L[N-1].data, '-1')
