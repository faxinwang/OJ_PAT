import math
N = 10005
Max = N * 8
pp = [1 for x in range(Max)]
p = []
for i in range(2,int(math.sqrt(Max))):
    if pp[i] == 1:
        p.append(i)
        j = i*i
        while j < Max: 
            pp[j ] = 0
            j = j + i 

data = input().split()
m,n = int(data[0]),int(data[1])
ans = []
for i in range(m-1,n ):
    ans.append(str(p[i]))
    if len(ans) == 10:
        print( ' '.join(ans) )
        ans.clear()
    i = i + 1
print(' '.join(ans))