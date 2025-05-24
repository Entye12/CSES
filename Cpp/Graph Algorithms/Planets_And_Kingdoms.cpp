#include <bits/stdc++.h>
using namespace std;
using qi = deque<int>;
using vi = vector<int>;
using vvi = vector<vi>;
using usi = unordered_set<int>;
using vb = vector<bool>;

int n,m,a,b;
vi kingdoms,order;
vvi edges,rEdges;
vb visited;


void dfs(int v,vvi const& adj, vi &output){
    visited[v] = true;
    for (int u:adj[v]){
        if (!visited[u]){
            dfs(u,adj,output);
        }
    }
    output.push_back(v);
}

int main(){
    scanf("%d %d",&n,&m);
    edges.resize(n+1);rEdges.resize(n+1);
    kingdoms.assign(n+1,0); visited.assign(n+1,false);
    for (int i=1;i<=m;i++){
        scanf("%d %d",&a,&b);
        edges[a].push_back(b);
        rEdges[b].push_back(a);
    }
    
    for (int i=1;i<=n;i++){
        if (!visited[i]) dfs(i,edges,order);
    }

    visited.assign(n+1,false);
    reverse(order.begin(),order.end());
    int k=1;

    for (int v:order){
        if (!visited[v]){
            vi component;
            dfs(v,rEdges,component);
            for (int u:component) kingdoms[u] = k;
            k++;
        }
    }
    printf("%d\n",--k);
    for (int i=1;i<=n;i++){
        printf("%d ",kingdoms[i]);
    }
    return 0;
}