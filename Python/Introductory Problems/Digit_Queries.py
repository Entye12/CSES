q = int(input())

queries = []
for i in range(q):
    queries.append(int(input())-1)

def size(n):
    return 9*n*(10**(n-1))

def wich_window(k):
    cur = 0
    window = 0
    while k >= cur :
        window += 1
        cur += size(window)
        
    return window,cur-size(window)


def deal_with_queries(queries):
    for k in queries:
        window, first_pos = wich_window(k)
        k -= first_pos
        first_number = 10**(window-1)
        quotient, remainder = k//window, k%window
        number_containing_k = first_number + quotient
        ans = str(number_containing_k)[remainder]
        print(ans)


deal_with_queries(queries)