n = int(input())

ans = ""
while n > 1 : 
    ans += str(n) + " "
    if n%2 == 0:
        n = n//2
    else : 
        n = 3*n+1
ans += str(1)

print(ans)
