coe,exp = input().split('E')
if coe[0]=='-': print('-', end='')
exp =int(exp)
if exp == 0: print(coe[1:])
elif exp > 0:
    if exp >= len(coe)-3:
        print(coe[1] + coe[3:] + '0'*(exp - len(coe)+3))
    else:
        print(coe[1] + coe[3:(exp+3)] + '.' + coe[(exp+3):])
else:
    exp = -exp
    print('0.'+'0'*(exp - 1) + coe[1] + coe[3:])