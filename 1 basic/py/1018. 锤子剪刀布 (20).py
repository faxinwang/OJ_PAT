n = int(input())
tab = [['=','>','<'],
       ['<','=','>'],
       ['>','<','=']]
idx = {'C':0,'J':1,'B':2}
A,B = 0,0
cnt1 = {'C':0, 'J':0, 'B':0}
cnt2 = {'C':0, 'J':0, 'B':0}
for i in range(n):
    x,y = input().split()
    res = tab[idx[x]][idx[y]] 
    if  res == '>':
        A = A + 1
        cnt1[x] = cnt1[x] + 1
    elif res == '<':
        B = B + 1
        cnt2[y] = cnt2[y] + 1

ch1,ch2 = 'J','J'
if cnt1[ch1] <= cnt1['C'] and ch1 > 'C': ch1 = 'C'
if cnt1[ch1] <= cnt1['B'] and ch1 > 'B': ch1 = 'B'
if cnt2[ch2] <= cnt2['C'] and ch2 > 'C': ch2 = 'C'
if cnt2[ch2] <= cnt2['B'] and ch2 > 'B': ch2 = 'B'
print(A,n-A-B, B)
print(B,n-A-B, A)
print(ch1,ch2)
