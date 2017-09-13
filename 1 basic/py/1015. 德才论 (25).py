class Stu(object):
    def __init__(self, id,de,cai):
        self.id = id
        self.de = de 
        self.cai = cai
    def __str__(self):
        return '{0} {1} {2}'.format(self.id, self.de, self.cai)

data = input().split()
N,L,H = int(data[0]),int(data[1]),int(data[2])
A,B,C,D = [],[],[],[]
for i in range(N):
    data = input().split()
    id, de, cai = data[0], int(data[1]), int(data[2])
    if de >= L and cai >= L:
        if de >= H and cai >= H:
            A.append(Stu(id,de,cai ))
        elif de >= H and cai < H:
            B.append(Stu(id,de,cai ))
        elif de < H and cai < H and de >= cai:
            C.append(Stu(id,de,cai ))
        else:
            D.append(Stu(id,de,cai ))

def cmp(s1, s2):
    t1 = s1.de + s1.cai
    t2 = s2.de + s2.cai
    if t1 != t2: return t1 > t2   #descending ordering by total score
    if s1.de != s2.de: return s1.de > s2.de #descending ordering by score de 
    return s1.id < s2.id        #ascending ordering by id
    
def quickSort(Low, High, a):
    if Low < High:
        piv = a[int((Low+High)/2)]
        i,j = Low, High
        while True:
            while i < High and cmp(a[i], piv): i = i + 1
            while j > Low and cmp(piv, a[j]): j = j - 1
            if i >= j: break
            t = a[i]
            a[i] = a[j]
            a[j] = t
        quickSort(Low, i-1, a )
        quickSort(i+1, High, a )
        
quickSort(0, len(A)-1, A )
quickSort(0, len(B)-1, B )
quickSort(0, len(C)-1, C )
quickSort(0, len(D)-1, D )

print(len(A)+len(B)+len(C)+len(D))
for s in A: print(s)
for s in B: print(s)
for s in C: print(s)
for s in D: print(s)
# the last test case will be TLE, but I can't make it faster anymore