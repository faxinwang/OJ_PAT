N,P = list(  map(int, input().split()) )
a = list(  map(int, input().split()) )
a.sort(key = lambda x: x)
i,j,Max = 0,0,1
while i < N - Max :
    j = i + Max
    tmp = a[i] * P  
    while j < N and a[j] <= tmp: j += 1
    if Max < j - i: Max = j - i
    i += 1
print(Max)