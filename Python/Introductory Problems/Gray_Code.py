n = int(input())

p = 1
ans = [['0']*n]
while p <= n :
    # do the sym
    res = []
    for i in range(1,2**(p-1)+1):
        x = ans[-i].copy()
        x[n-p] = '1'
        res.append(x)
    ans.extend(res)
    p += 1

for x in ans :
    print(''.join(x))