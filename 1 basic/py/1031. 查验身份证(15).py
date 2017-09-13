d = {0:'1',1:'0',2:'X',3:'9',4:'8',5:'7',
     6:'6',7:'5',8:'4',9:'3',10:'2'}
W = [7, 9, 10, 5, 8, 4, 2, 1, 6, 3, 7, 9, 10, 5, 8, 4, 2]
N = int(input())
L = []
for i in range(N ):
    id = input()
    sum,flag= 0,True
    for j in range(17):
        if id[j].isdigit() : sum += W[j] * int(id[j])
        else:
            L.append(id)
            flag = False
            break
    if flag and d[sum%11] != id[17]: L.append(id)
if len(L )==0: print('All passed')
else:
    for id in L: print(id)
    