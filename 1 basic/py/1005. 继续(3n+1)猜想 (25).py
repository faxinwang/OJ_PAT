L = [0 for i in range(105)] #initialize list L with value 0

def process(n):
    while n > 1:
        if n % 2 == 1: n = (3 * n + 1) / 2
        else: n = n / 2
        if(n < 105 and L[int(n)]==2): L[int(n)] = 1    # with value 1 means this place has been override

n = input()
a = input().split()
a = [int(x) for x in a]

for x in a:
    L[x] = 2    #with value 2 means L[x] have value but not override yet
    
for i in range(1,100): 
    if L[i ]==2: process(i)
ans = ''
i = 100
while i >= 1:
    if L[i]==2: ans = ans + str(i) + ' '
    i = i - 1
print(ans.strip())
