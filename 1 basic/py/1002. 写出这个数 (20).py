from _functools import reduce

n = input()
def char2int(ch):
    return {'0':0,'1':1,'2':2,'3':3,'4':4,'5':5,'6':6,'7':7,'8':8,'9':9}[ch]
s = reduce(lambda x,y: x+y, map(char2int, n))
s = str(s)
def switch(ch):
    return {'0':'ling ','1':'yi ','2':'er ', 
            '3':'san ', '4':'si ', '5':'wu ',
            '6':'liu ', '7':'qi ', '8':'ba ','9':'jiu '}[ch]
ans = ''
for ch in s: ans = ans + switch(ch)
print(ans.strip())