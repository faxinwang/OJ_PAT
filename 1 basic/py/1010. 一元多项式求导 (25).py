a = input().split()
a = [int(x ) for x in a ]

ans = ''
i,leng = 1,len(a )
while i < leng:
    exp = a[i]*a[i-1]
    coe = a[i ] - 1
    i = i + 2
    if exp == 0:
        if leng <= 2: 
            ans = "0 0"
            break;
        else: continue
    ans = ans + str(exp ) + ' ' + str(coe) + ' '
    
print(ans.strip())