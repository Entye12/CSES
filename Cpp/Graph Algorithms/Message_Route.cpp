#include <bits/stdc++.h>
using namespace std;
using vi = vector<int>;
using vvi = vector<vector<int>>;

int n,m,a,b,x;
unordered_set<int> visited;

void bfs(int x,const vvi& adj, vi& prev){
    queue<int> Q;
    Q.push(x);
    while (!Q.empty()){
        x = Q.front();
        Q.pop();
        for (int y:adj[x]){
            if (visited.find(y) == visited.end()){
                Q.push(y);
                visited.insert(y);
                prev[y] = x;
            }
        }
    }
}

int main(){
    scanf("%d %d",&n,&m);
    vvi adj(n+1);
    for (int i=0;i<m;i++){
        scanf("%d %d",&a,&b);
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    vi prev(n+1,-1);
    prev[1] = 0;
    visited.insert(1);
    bfs(1,adj,prev);
    if (prev[n]==-1) {
        printf("IMPOSSIBLE\n");
        return 0;
    }
    vi path;
    x = n;
    while (x != 0){
        path.push_back(x);
        x = prev[x];
    }
    reverse(path.begin(),path.end());
    int k = path.size();
    printf("%d\n",k);
    for (int i=0;i<k;i++){
        printf("%d ",path[i]);
    }
    return 0;
}