d = {}
s1,s2 = input(),input()
for ch in s2: d[ch] = 1
for ch in s1:
    if d.get(ch,0) == 0:
        print(ch.upper(), end='')
        d[ch.upper()] = 1
        d[ch.lower()] = 1