n = int(input())

def f(k):
    return (4*(k**2 - 3) + 8*(k**2 - 4) + 4*(k-3)*(k**2 -5)+ 4*(k-4)*(k**2 - 7) + (k-4)**2 * (k**2 - 9))//2


for i in range(1,n+1):
    print(f(i))