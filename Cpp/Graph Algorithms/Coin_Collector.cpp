#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vll = vector<ll>;
using vi = vector<int>;
using vvi = vector<vi>;
using vb = vector<bool>;


int n,m,a,b;
vi comp,order,rep;
vll coins;
vvi edges,edges_t;
vb visited;



void dfs(int v,vvi const &adj,vi &output){
    visited[v] = true;
    for (int u:adj[v]){
        if (!visited[u]) dfs(u,adj,output);
    }
    output.push_back(v);
}

int main(){
    scanf("%d %d",&n,&m);
    edges.resize(n+1);edges_t.resize(n+1);
    comp.assign(n+1,0); visited.assign(n+1,false);
    coins.assign(n+1,0);
    for (int i=1;i<=n;i++) scanf("%lld",&coins[i]);
    for (int i=1;i<=m;i++){
        scanf("%d %d",&a,&b);
        edges[a].push_back(b);
        edges_t[b].push_back(a);
    }
    

    
    for (int i=1;i<=n;i++){
        if (!visited[i]) dfs(i,edges,order);
    }

    visited.assign(n+1,false);
    reverse(order.begin(),order.end());
    int k=1;
    
    

    for (int v: order){
        if (!visited[v]){
            vi component;
            dfs(v,edges_t,component);
            for (int u:component) comp[u]=k;
            k++;
        } 
    }
    k--;
    int maxCoin = 0;
    vll coinsComp(k+1,0);
    for (int i=1;i<=n;i++){
        coinsComp[comp[i]] += coins[i];
    }
    
    vvi edgesComp(k+1);
    for (int i=1;i<=n;i++){
        int v = comp[i];
        for (int y : edges[i]){
            if (comp[y] != v) edgesComp[v].push_back(comp[y]);
        }
    }
    vll coinsSum(k+1,0);
    for (int i=k;i>=1;i--){
        coinsSum[i] = coinsComp[i];
        for (int j:edgesComp[i]){
            coinsSum[i] = max(coinsSum[i],coinsComp[i]+coinsSum[j]);
        }
    }
    ll ans = *max_element(coinsSum.begin(),coinsSum.end());
    cout << ans << endl;
    return 0;
}