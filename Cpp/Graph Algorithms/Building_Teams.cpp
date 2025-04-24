#include <bits/stdc++.h>
using namespace std;
using vi = vector<int>;
using vvi = vector<vector<int>>;


int n,m,a,b,x;

bool bfs(int x, const vvi& adj, vi& colors){
    // new connexe component
    queue<int> Q;
    Q.push(x); colors[x]=1;
    while (!Q.empty()){
        x = Q.front(); Q.pop();
        for (int y: adj[x]){
            if (colors[y] == -1){
                colors[y] = 1-colors[x];
                Q.push(y);
            }
            else if (colors[x]==colors[y]) return true;
        }
    }
    return false;
}

int main(){
    scanf("%d %d",&n,&m);
    vvi adj(n+1);
    for (int i=0;i<m;i++){
        scanf("%d %d",&a,&b);
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    vi colors(n+1,-1);

    for (int i=1;i<=n;i++){
        if (colors[i]==-1){
            if (bfs(i,adj,colors)){
                printf("IMPOSSIBLE\n");
                return 0;
            }
        }
    }
    for (int i=1;i<=n;i++){
        int col = (colors[i]==1) ? 1: 2;
        printf("%d ", col);
    }
    return 0;
}