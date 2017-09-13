N, ch = input().split()
N = int(N)
total,Max = 1,3
while total + Max * 2 <= N:
    total += Max * 2
    Max += 2
Max -= 2
space,i = 0, Max
while i >= 1:
    print(' ' * space + ch * i)
    space += 1
    i -= 2
i = 1
space -= 1
while i < Max:
    i += 2
    space -= 1
    print(' ' * space + ch * i)
print(N - total)