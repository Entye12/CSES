#include <bits/stdc++.h>
using namespace std;
using vi = vector<int>;
using vvi = vector<vi>;

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
    if (visited[n]==0) {
        printf("IMPOSSIBLE\n");
        return 0;
    }
    
    reverse(topologicalSort.begin(),topologicalSort.end());
    vi nCities(n+1,1);
    vi parents(n+1);

    for (int x:topologicalSort){
        for (int y:adj[x]){
            if (nCities[y] < nCities[x]+1){
                parents[y] = x;
                nCities[y] = nCities[x]+1;
            }
        }
    }
    printf("%d\n",nCities[n]);
    vi  ans;
    int cur = n;
    while (cur>1){
        ans.push_back(cur);
        cur = parents[cur];
    }
    ans.push_back(1);
    reverse(ans.begin(),ans.end());
    for (int x:ans) printf("%d ",x);
    return 0;
}