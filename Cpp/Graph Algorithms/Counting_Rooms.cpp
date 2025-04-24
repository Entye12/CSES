#include <bits/stdc++.h>
using namespace std;

int n,m; string s;
int x,y,nx,ny;
vector<string> grid;
int ans = 0;

bool in_bound(int i, int j){
    return (0 <= i && i < n && 0 <= j && j < m);
}

void bfs(int i,int j){
    queue<pair<int,int>> Q;
    Q.push({i,j}); grid[i][j] = '#';
    while (!Q.empty()){
        x = Q.front().first; y = Q.front().second;
        Q.pop();
        for (auto [dx,dy]: vector<pair<int,int>> {{-1,0},{0,-1},{1,0},{0,1}}){
            nx = x+dx; ny = y+dy;
            if (in_bound(nx,ny) && grid[nx][ny] == '.'){
                Q.push({nx,ny});
                grid[nx][ny] = '#';
            }
        }
    }
}


int main() {
    scanf("%d %d",&n,&m);
    for (int i = 0; i < n; i++) {
        cin >> s;
        grid.emplace_back(s);
    }
    for (int i=0;i<n;i++){
        for (int j=0;j<m;j++){
            if (grid[i][j] == '.'){
                bfs(i,j);
                ans++;
            }
        }
    }
    printf("%d\n",ans);
    return 0;
}
