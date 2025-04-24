#include <bits/stdc++.h>
using namespace std;
using vi = vector<int>;
using vvi = vector<vector<int>>;

int n,m,x,y,a,b;
int s = -1; int e = -1; 
unordered_set<int> visited;


bool dfs(int u,int p,const vvi& adj,vi& parent){
    stack<pair<int,int>> S;
    S.push({u,p});
    visited.insert(u);
    parent[u]=p;

    while (!S.empty()){
        tie(u, p) = S.top(); S.pop();
        visited.insert(u);
        for (int y:adj[u]){
            if (y==p) continue;
            else if (visited.find(y)!=visited.end()){
                s = y; e = u;
                return true;
            }
            else {
                parent[y] = u;
                S.push({y,u});
            }
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
    vi parent(n+1,-1);
    for (int i=1;i<=n;i++){
        if (visited.find(i)==visited.end()){
            if (dfs(i,-1,adj,parent)){
                vi ans{e};
                x = e;
                while (x!=s){
                    x = parent[x];
                    ans.push_back(x);
                }
                ans.push_back(e);

                printf("%zu\n",ans.size());
                for (int x:ans){
                    printf("%d ",x);
                }
                return 0;
            }
        }
    }
    printf("IMPOSSIBLE\n");
    return 0;
}