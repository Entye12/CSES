#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vll = vector<ll>;
using vi = vector<int>;
using vvi = vector<vi>;
using si = set<int>;
using vtiill = vector<tuple<int,int,ll>>;
using sti = stack<int>;


const ll INF = 1e18;
int n,m,a,b;ll c; int x;
vll gain;
vtiill edges;
si nodes_inf, reachable_from_n;
vvi reverse_edges;


bool bellman_ford(){
    gain[1]=0;
    bool updated;
    for (int i=1;i<=n;i++){
        updated = false;
        for (auto &[a,b,c]:edges){
            if (gain[a] != -INF && gain[b] < gain[a] + c) {
                gain[b] = gain[a] + c;
                updated = true;
                if (i == n) nodes_inf.insert(b); 
            }
        }
        if (!updated) break;
    }
    return !nodes_inf.empty();
}

bool dfs(){
    sti S; si visited;
    visited.insert(n); S.push(n);
    while (!S.empty()){
        x = S.top(); S.pop();
        if (nodes_inf.find(x) != nodes_inf.end()) return true;

        for (int y:reverse_edges[x]){
            if (visited.find(y) == visited.end()){
                S.push(y);
                visited.insert(y);
            }
        }
    }
    return false;
}


int main(){
    scanf("%d %d",&n,&m);
    reverse_edges.resize(n+1);

    for (int i=0; i<m; i++){
        scanf("%d %d %lld",&a,&b,&c);
        edges.push_back({a,b,c});
        reverse_edges[b].push_back(a);
    }
    gain = vll(n+1,-INF);
    bool cycle = bellman_ford();
    if (cycle && dfs()) printf("%d\n",-1);
    else printf("%lld\n", gain[n]);
    return 0;
}