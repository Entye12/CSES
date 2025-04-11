t = int(input())
x_y = []
for i in range(t):
    x_y.append(input().split())

for couple in x_y :
    x,y = int(couple[0]), int(couple[1])
    s = max(x,y)
    # the max is on the top right corner
    if s%2 == 1 :
        if y == s:
            print(y**2 - x + 1)
        else : 
            print((x-1)**2 + y)
    # the max is on the left bot corner
    else : 
        if x == s:
            print(s**2-y+1)
        else :
            print((s-1)**2 + x)