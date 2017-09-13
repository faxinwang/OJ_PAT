N = int(input())
d = {}
Max_id, Max_score = 1,0
for i in range(N ):
    id,score = list( map(int, input().split() ) )
    tmp = d[id] = d.get(id, 0) + score
    if Max_score < tmp:
        Max_score = tmp
        Max_id = id
print(Max_id, Max_score)