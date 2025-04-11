I = lambda : list(input())

def N_Queens(matrix):

    n = 8
    ans = 0
    # preprocessing

    col, diag1, diag2 = {}, {}, {}
    for i in range(2*n-1):
        col[i], diag1[i], diag2[i] = False, False, False

    mat_diag1, mat_diag2 = [[0 for i in range(n)] for j in range(n)], [[0 for i in range(n)] for j in range(n)]

    for i in range(n):
        for j in range(n):
            mat_diag1[i][j] = i-j+n-1
            mat_diag2[i][j] = i+j
    
    def backtrack(row, col, diag1, diag2):
        nonlocal ans
        if row == n :
            ans += 1
            return
        
        for c in range(n):
            if col[c] or diag1[mat_diag1[row][c]] or diag2[mat_diag2[row][c]] or matrix[row][c] == "*":
                continue

            col[c], diag1[mat_diag1[row][c]], diag2[mat_diag2[row][c]] = True,True,True
            backtrack(row+1,col,diag1,diag2)
            col[c], diag1[mat_diag1[row][c]], diag2[mat_diag2[row][c]] = False,False,False
    
    backtrack(0,col,diag1,diag2)

    return ans

matrix = []
for _ in range(8):
    matrix.append(I())

ans = N_Queens(matrix)
print(ans)