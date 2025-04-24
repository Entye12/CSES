#include <bits/stdc++.h>
using namespace std;
using vi = vector<int>;
using vvi = vector<vector<int>>;

int n,m,a,b,x; int nb = 0;
unordered_set<int> visited;
vi rep;

void bfs(int p, const vvi& adj){
    queue<int> Q;
    Q.push(p);
    visited.insert(p);
    while (!Q.empty()){
        x = Q.front();
        Q.pop();
        for (int y:adj[x]){
            if (visited.find(y) == visited.end()){
                Q.push(y);
                visited.insert(y);
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
    
    for (int p=1;p<=n;p++){
        if (visited.find(p) == visited.end()){
            bfs(p,adj);
            rep.push_back(p);
        }
    }
    int k = rep.size()-1;
    printf("%d\n",k);
    for (int i=0; i<k;i++){
        printf("%d %d\n", rep[i], rep[i+1]);
    }
    return 0;
}