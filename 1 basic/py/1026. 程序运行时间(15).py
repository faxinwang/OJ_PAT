C1,C2= list(map(int ,input().split()))
span = C2 - C1
total = span // 100 + (1 if span % 100 >= 50 else 0)
print('{0:02d}:{1:02d}:{2:02d}'.format( total // 3600, total%3600//60, total%60))