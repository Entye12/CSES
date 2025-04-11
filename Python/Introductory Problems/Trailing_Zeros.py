# v2(n) >= v5(n)

n = int(input())

# Legendre formula : trivial

p=1
ans = 0
while n >= 5**p :
    ans += n//(5**p)
    p+=1

print(ans)