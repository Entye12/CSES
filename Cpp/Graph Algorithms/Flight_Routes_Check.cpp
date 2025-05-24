#include <bits/stdc++.h>
using namespace std;
using vi = vector<int>;
using vvi = vector<vi>;
using usi = unordered_set<int>;
using qi = deque<int>;

int n,m,a,b;
vvi edges,rEdges;
usi reachFrom1, reach1;

void mark(int i,vvi &adj, usi &visited){
    int x = i;
    qi nodes; nodes.push_back(x); visited.insert(x);
    while (!nodes.empty()){
        x = nodes.front();
        nodes.pop_front();
        for (int y: adj[x]){
            if (!visited.count(y)){
                visited.insert(y);
                nodes.push_back(y);
            }
        }
    }
}


int main(){
    scanf("%d %d",&n,&m);
    edges.resize(n+1);rEdges.resize(n+1);
    for (int i=1;i<=m;i++){
        scanf("%d %d",&a,&b);
        edges[a].push_back(b);
        rEdges[b].push_back(a);
    }
    mark(1,edges,reachFrom1);
    mark(1,rEdges,reach1);
    if (reachFrom1.size() < n){
        printf("NO\n");
        for (int i=1;i<=n;i++){
            if (reachFrom1.count(i)==0){
                printf("%d %d\n",1,i);
                return 0;
            }
        }
    }
    else if (reach1.size() < n){
        printf("NO\n");
        for (int i=1;i<=n;i++){
            if (reach1.count(i)==0){
                printf("%d %d\n",i,1);
                return 0;
            }
        }
    }
    else printf("YES\n");
    return 0;
}