n = int(input())
b = n / 100
s = n % 100 / 10
g = n % 10
ans = ''
for i in range(int(b)): ans = ans + 'B'
for i in range(int(s)): ans = ans + 'S'
for i in range(1,int(g)+1): ans = ans + str(i)
print(ans)