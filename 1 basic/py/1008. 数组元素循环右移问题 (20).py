def reverse(a,m,n):
    mid = int((n - m) / 2)
    for i in range(mid):
        t = a[m + i ]
        a[m + i ]= a[n - i -1]
        a[n - i -1] = t 

s = input().split()
n,m = int(s[0]),int(s[1])
a = input().split()
a = [int(x) for x in a ]
m = m % n
reverse(a, 0, n - m)
reverse(a, n - m, n)
reverse(a, 0, n)
ans = ''
for x in a: ans = ans + str(x)+ ' '
print(ans.strip())