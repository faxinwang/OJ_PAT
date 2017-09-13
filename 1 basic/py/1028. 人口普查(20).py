Min,Max,cnt = '1814/09/06', '2014/09/06', 0
oldDate,oldName, youngDate,youngName = '','','','' 
N = int(input())
for i in range(N):
    name, date = input().split()
    if date < Min or date > Max: continue
    cnt += 1
    if cnt == 1: 
        oldDate = youngDate = date
        oldName = youngName = name
    else:
        if date < oldDate:
            oldDate = date
            oldName = name
        elif date > youngDate: 
            youngDate = date
            youngName = name
if cnt > 0: print(cnt, oldName, youngName)
else: print('0')