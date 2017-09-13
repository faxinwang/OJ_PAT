from macpath import split

n = int(input())
minName, minNum, minScore = '','',100
maxName, maxNum, maxScore = '','',0
for i in range(n):
    name,num, score = input().split()
    score = int(score)
    if score < minScore:
        minName = name
        minNum = num
        minScore = score
    if score > maxScore:
        maxName = name
        maxNum = num
        maxScore = score
print(maxName, maxNum)
print(minName, minNum)