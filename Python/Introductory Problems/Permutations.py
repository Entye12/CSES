n = int(input())


if n == 1 : 
    print("1")
elif n <= 3:
    print("NO SOLUTION")

else: 
    even,odd = [],[]
    for i in range(n,0,-1):
        if i%2 == 0:
            even.append(i)
        else :
            odd.append(i)
    print(*(odd+even))