s = input()


pairs, single = [],set()

for char in s :
    if char in single:
        pairs.append(char)
        single.remove(char)
    else :
        single.add(char)
    
if len(s)%2 == 0 and len(single)>0 or len(single) >= 2 :
    print("NO SOLUTION")
else :
    res = ''.join(pairs) + ''.join(single) + ''.join(pairs)[::-1]
    print(res)
