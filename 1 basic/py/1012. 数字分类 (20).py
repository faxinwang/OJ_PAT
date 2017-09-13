data = input().split()
data = [int(x) for x in data]
n = data[0]
a = [0,0,0,0,0]
cnt,flag = 0 ,1
flag0,flag1 = False,False
for i in range(1,n+1):
    x = data[i]
    if x % 10 == 0:
        a[0] = a[0] + x
        flag0 = True
    if x % 5 == 1:
        a[1] = a[1] + flag * x
        flag = - flag
        flag1 = True
    if x % 5 == 2: a[2] = a[2] + 1
    if x % 5 == 3:
        a[3] = a[3] + x
        cnt = cnt + 1
    if x % 5 == 4:
        if a[4] < x: a[4] = x
ans = ''
ans = ans + ( str(a[0]) if flag0 else 'N') + ' ' 
ans = ans + ( str(a[1]) if flag1 else 'N') + ' '
ans = ans + ( str(a[2]) if a[2] > 0 else 'N') + ' '
if cnt > 0:
    a3 = a[3] / cnt
    a3 = '{0:.1f}'.format(a3)
else: a3 = 'N'
ans = ans +a3 +' '
ans = ans + ( str(a[4]) if a[4] > 0 else 'N' )

print( ans )
