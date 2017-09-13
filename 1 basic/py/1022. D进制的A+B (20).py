data = input().split()
SUM,D = int(data[0]) + int(data[1]),int(data[2])
res = []
if SUM == 0: print(0)
while SUM > 0:
    res.append(SUM % D) 
    SUM //= D
res.reverse()
for a in res: print(a, end='')
