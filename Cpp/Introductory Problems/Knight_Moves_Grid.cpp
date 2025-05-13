#include <bits/stdc++.h>
using namespace std;
using vi = vector<int>;
using vvi = vector<vi>;
using vtii = vector<tuple<int,int>>;
using qii = queue<tuple<int,int>>;

vtii steps = {{1, 2}, {1, -2}, {-1, 2}, {-1, -2},
                               {2, 1}, {2, -1}, {-2, 1}, {-2, -1}};


int n,x,y; const int INF = 1e9+1;


bool inBound(int i, int j){
    return (0<=i && i < n && 0<=j && j<n);
}

vtii neighbors(int x, int y){
    vtii res;
    for (auto &[dx,dy] : steps){
        if (inBound(x+dx,y+dy)) res.push_back({x+dx,y+dy});
    }
    return res;
}

int main(){
    scanf("%d",&n);
    vvi grid(n,vi(n,INF));
    grid[0][0] = 0;
    qii Q;
    Q.push({0,0});
    while (!Q.empty()){
        tie(x,y) = Q.front(); Q.pop();
        vtii neigh = neighbors(x,y);
        for (auto &[a,b] : neigh){
            if (grid[a][b] == INF){
                grid[a][b] = grid[x][y]+1;
                Q.push({a,b});
            }
        }
    }
    for (int i=0;i<n;i++){
        for (int j=0; j<n;j++){
            printf("%d ",grid[i][j]);
        }
        printf("\n");
    }
    return 0;
}
