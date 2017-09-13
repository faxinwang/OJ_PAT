A,B = input().split()
B = int(B)
Q,R = '',0
for n in A:
    R = R * 10 + int(n)
    Q = Q + str(int(R / B))
    R = R % B

print( (Q[1:] if len(Q)>1 and Q[0]=='0' else Q ), R )
