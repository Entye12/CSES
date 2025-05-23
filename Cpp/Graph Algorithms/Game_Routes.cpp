#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vll = vector<ll>;
using vi = vector<int>;
using vvi = vector<vi>;
const ll MOD = 1e9+7;

int n,m,a,b;
vvi adj;
vi visited;
vi topologicalSort;

void dfs(int v){
    visited[v] = 1;
    for (int u:adj[v]){
        if (!visited[u]) dfs(u);
    }
    topologicalSort.push_back(v);
}

int main(){
    scanf("%d %d",&n,&m);
    visited.assign(n+1, 0);
    adj.resize(n+1);
    for (int i=1;i<=m;i++){
        scanf("%d %d",&a,&b);
        adj[a].push_back(b);
    }
    
    dfs(1);
    reverse(topologicalSort.begin(),topologicalSort.end());
    
    vll ways(n+1,0);
    ways[1]=1;
    for (int x:topologicalSort){
        for (int y:adj[x]){
            ways[y] = (ways[y]+ways[x])%MOD;
        }
    }
    printf("%lld\n",ways[n]);
    return 0;
}