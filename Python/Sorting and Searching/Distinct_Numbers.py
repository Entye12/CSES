n = int(input())
numbers = input().split(" ")

ens = set()
for nb in numbers:
    ens.add(nb)

print(len(ens))
