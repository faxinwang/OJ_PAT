num = input()
d = {}
for c in num:d[c] = d.get(c,0) + 1
for k in sorted(d): print('%c:%d'%(k,d[k]))