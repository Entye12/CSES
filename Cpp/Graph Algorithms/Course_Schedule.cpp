#include <bits/stdc++.h>
using namespace std;
using vi = vector<int>;
using vvi = vector<vi>;


int n,m,a,b;
vvi adj;
vi visited;
vi ans;


bool dfs(int v){
    visited[v] = 1;
    for (int u:adj[v]){
        if (visited[u]==1) return false;
        else if (visited[u]==0){
            if (!dfs(u)) return false;
        }
    }
    visited[v]=2;
    ans.push_back(v);
    return true;
}


int main(){
    scanf("%d %d",&n,&m);
    visited.assign(n+1, 0);
    adj.resize(n+1);
    for (int i=1;i<=m;i++){
        scanf("%d %d",&a,&b);
        adj[a].push_back(b);
    }

    for (int i=1;i<=n;i++){
        if (visited[i]==0){
            if (!dfs(i)){
                printf("IMPOSSIBLE\n");
                return 0;
            }
        }
    }
    reverse(ans.begin(),ans.end());
    for (int u:ans){
        printf("%d ",u);
    }
    return 0;
}