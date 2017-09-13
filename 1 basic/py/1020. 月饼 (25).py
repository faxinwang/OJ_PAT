class MoonCake(object):
    def __init__(self, total, money):
        self.total = total
        self.money = money
        self.price = money / total
    def __str__(self):
        return '%s %s %s '%(self.total,self.money,self.price)

n,need = input().split()
n,need = int(n),int(need)
s = list(map(int, input().split()))
p = list(map(int, input().split()))
mc = []
for i in range(n): mc.append(MoonCake(s[i], p[i]))
mc.sort(key = lambda obj: obj.price, reverse=True)

profit = 0
for o in mc:
    if need >= o.total:
        need = need - o.total
        profit = profit + o.money
    else:
        profit = profit + need * o.price
        break
print('{0:.2f}'.format(profit))