DNA = input()

n = len(DNA)
best, cur = 1,1

for i in range(1,n):
    if DNA[i]==DNA[i-1]:
        cur += 1
    else :
        best = max(best,cur)
        cur = 1
        
best = max(best,cur)
print(best)