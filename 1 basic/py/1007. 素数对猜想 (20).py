Max = 100010
a = [0 for i in range(Max)]
p = []
for i in range(2,Max):
    if a[i ] == 0:
        p.append(i)
        j = i * i 
        while j < Max:
            a[j ] = 1
            j = j + i

cnt,j = 0,1
n = int(input())
while p[j] <= n :
    if p[j ] - p[j-1] == 2: cnt = cnt + 1
    j = j + 1
print(cnt)