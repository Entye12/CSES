n = int(input())
line = input().split()

ans = 0

for i in range(1,n):
    if int(line[i]) < int(line[i-1]):
        ans += (int(line[i-1]) - int(line[i]))
        line[i] = line[i-1]

print(ans)
