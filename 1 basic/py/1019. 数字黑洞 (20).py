from _functools import reduce
n = int(input())
n = '{0:04d}'.format(n)     #notice
x,y = sorted(n,reverse=True),sorted(n)
def fn(a,b):
    return int(a)*10 + int(b)
x,y = reduce(fn, x),reduce(fn,y)
if x == y: print('{0:04d} - {1:04d} = {2:04d}'.format(x,y,x-y))
else:
    d = x - y
    print('{0:04d} - {1:04d} = {2:04d}'.format(x,y,d))
    while d!=6174:
        d = '{0:04d}'.format(d)
        x,y = sorted(d, reverse=True), sorted(d)
        x,y = reduce(fn, x),reduce(fn,y)
        d = x - y
        print('{0:04d} - {1:04d} = {2:04d}'.format(x,y,d))
