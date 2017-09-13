A,DA,B,DB = input().split()
PA,PB = '',''
for ch in A:
    if ch == DA: PA = PA + ch
for ch in B:
    if ch == DB: PB = PB + ch 
print( (int(PA) if PA!='' else 0) + (int(PB) if PB!='' else 0) )
