# Optimization 3 : if I hit the upper or bottom wall and I still can turn right and left then it's a cul-de-sac 
#                  the same thing when I hit a right or left wall and I still can go up and down


def ham_path(n,directions):

    ans = 0

    grid = [[False for i in range(n)] for j in range(n)]
    grid[0][0] = True

    def backtrack(x,y,step, grid):
        nonlocal ans
        if x == n-1 and y == 0 and step == n*n - 1 :
            ans += 1
            return
        
        # check if I've hit a top or bottom wall and i still can go left then my grid is subdivided in two non connexe sets
        if (x == 0 and y-1>=0 and grid[x][y-1] == False) or (x == n-1 and y+1 <= n-1 and grid[x][y+1] == False):
            return
        # check if I've hit a left or right wall and i still can go top then my grid is subdivided in two non connexe sets
        if (y == 0 and x-1>=0 and grid[x-1][y] == False) or (y == n-1 and x-1>=0 and grid[x-1][y] == False):
            return

        

        # if i can turn left
        if y-1 >= 0 and grid[x][y-1] == False and (directions[step] == "?" or directions[step] == "L"):
            grid[x][y-1] = True
            backtrack(x,y-1,step+1,grid)
            grid[x][y-1] = False
        
        # if i can turn right
        if y+1 < n and grid[x][y+1] == False and (directions[step] == "?" or directions[step] == "R"):
            grid[x][y+1] = True
            backtrack(x,y+1,step+1,grid)
            grid[x][y+1] = False

        
        # if can go up
        if x-1>=0 and grid[x-1][y] == False and (directions[step] == "?" or directions[step] == "U"):
            grid[x-1][y] = True
            backtrack(x-1,y,step+1,grid)
            grid[x-1][y] = False

        # if can go down
        if x+1<n and grid[x+1][y] == False and (directions[step] == "?" or directions[step] == "D"):
            grid[x+1][y] = True
            backtrack(x+1,y,step+1,grid)
            grid[x+1][y] = False

    
    backtrack(0,0,0,grid)
    return ans


directions = input()

print(ham_path(7,directions))