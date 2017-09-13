n = int(input())
for i in range(n):
    s = input()
    cntP,cntA,cntT = 0,0,0
    posP,posT = 0,0
    leng = len(s)
    for j in range(leng):
        if s[j] == 'P':
            cntP = cntP + 1
            posP = j
        if s[j] == 'T':
            cntT = cntT + 1
            posT = j
        if s[j] == 'A':
            cntA = cntA + 1
    if( cntP + cntA + cntT != leng or
        posT - posP <= 1 or
        cntP > 1 or
        cntT > 1 or
        posP*(posT-posP-1) != leng-posT-1 ):
        print("NO")
    else:
        print("YES")
        