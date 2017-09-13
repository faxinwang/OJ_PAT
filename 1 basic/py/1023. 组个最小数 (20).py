data = list(map(int, input().split()))
ans = ''
for i in range(1,10):
    if data[i] != 0:
        ans += str(i)
        data[i] -= 1
        break
for i in range(10):
    while data[i] > 0:
        ans += str(i)
        data[i] -= 1
print(ans)