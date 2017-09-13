a = input()
b = input()
c = input()
d = input()
len1,len2 = min( len(a),len(b)),min(len(c ),len(d ))
wd = {'A':'MON','B':'TUE','C':'WED','D':'THU','E':'FRI','F':'SAT','G':'SUN'}
tm = {'0':'00','1':'01','2':'02','3':'03','4':'04','5':'05','6':'06','7':'07',
      '8':'08','9':'09','A':'10', 'B':'11','C':'12','D':'13','E':'14','F':'15',
      'G':'16','H':'17','I':'18','J':'19','K':'20','L':'21','M':'22','N':'23'}
mark ,ans = 0,''
for i in range(len1):
    if a[i] == b[i] and 'A' <= a[i] <= 'G':
       ans = ans + wd[a[i]] + ' '
       mark = i + 1
       break
for i in range(mark, len1):
    if a[i]== b[i] and ('A'<=a[i]<='N' or '0'<=a[i ]<='9'):
        ans = ans + tm[a[i ]]
        break
for i in range(len2):
    if c[i ]== d[i ]:
        if 'A'<=c[i]<='Z' or 'a'<=c[i]<='z' :
            ans = ans + ':{0:02d}'.format(i)
            break
print(ans)