t = int(input())

piles = []
for i in range(t):
    piles.append(input().split())

for pile in piles :
    a,b = int(pile[0]), int(pile[1])
    if (a+b)%3 == 0 and 2*a-b>=0 and 2*b-a>=0 : 
        print("YES")
    else :
        print("NO")