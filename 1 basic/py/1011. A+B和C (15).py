n = int(input())
for i in range(1,n+1):
    data = input().split()
    a,b,c = int(data[0]),int(data[1]),int(data[2])
    ans = 'true' if a + b > c else 'false'
    print( 'Case #{0}: {1}'.format(i,ans ))