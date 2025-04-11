n = int(input())

sum = (n*(n+1))//2

if sum%2 == 1:
    print("NO")
else : 
    print("YES")
    subsum = sum//2
    first, second = set(),set()
    for i in range(n,0,-1):
        if i <= subsum :
            first.add(i)
            subsum -= i
        else :
            second.add(i)
    print(len(first))
    print(*first)
    print(len(second))
    print(*second)
