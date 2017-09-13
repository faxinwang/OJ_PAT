d = {}  # dictionary is faster than list
flag = True
for ch in input(): 
    d[ch] = True
    d[ch.lower()] = True
    if ch == '+': flag = False
for ch in input():
    if ch not in d: 
        if ch.isupper(): 
            if flag: print(ch,end='')
        else:
            print(ch,end='')