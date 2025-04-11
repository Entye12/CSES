n = int(input())
line = input()

line = line.split()
to_visit = set([str(i) for i in range(1,n+1)])

for nb in line : 
    
    to_visit.remove(nb)

for s in to_visit :
    print(int(s))