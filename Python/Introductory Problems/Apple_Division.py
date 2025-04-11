n = int(input())

line = input().split(" ")


def f(i,a,b):
    if i >= n:
        return abs(a-b)
    else : 
        return min(f(i+1,a+int(line[i]),b),f(i+1,a,b+int(line[i])))

print(f(0,0,0))