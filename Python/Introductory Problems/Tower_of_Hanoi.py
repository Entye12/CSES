n = int(input())

ans = 2**n - 1

def f(n,start,end,inter):
    if n == 1 :
        print(str(start) + " " + str(end))
    else : 
        f(n-1,start,inter,end)
        print(str(start)+" "+str(end))
        f(n-1,inter, end,start)
    
print(ans)
f(n,1,3,2)