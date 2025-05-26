#include <bits/stdc++.h>
using namespace std;
using pii = pair<int,int>;
using vi = vector<int>;
using vpii = vector<pii>;
using vvpii = vector<vpii>;
using vb = vector<bool>;


int n,m,a,b;
vvpii edges;
vb used;
vi deg;
stack<int> S;

int main(){
    scanf("%d %d",&n,&m);
    edges.resize(n+1);
    used.assign(m+1,false);
    deg.assign(n+1,0);
    for (int i=1;i<=m;i++){
        scanf("%d %d",&a,&b);
        edges[a].push_back({b,i});
        edges[b].push_back({a,i});
        deg[a]++; deg[b]++;
    }

    for (int i=1;i<=n;i++){
        if (deg[i]%2){
            printf("IMPOSSIBLE\n");
            return 0;
        }
    }

    S.push(1);
    vi circuit;

    while (!S.empty()){
        int x = S.top();
        if (deg[x]){
            while (!edges[x].empty()){
                int y = edges[x].back().first; int id = edges[x].back().second;
                edges[x].pop_back();

                if (!used[id]){
                    used[id] = true;
                    S.push(y);
                    deg[x]--;deg[y]--;
                    break;
                }
            }
        }
        else {
            circuit.push_back(x);
            S.pop();
        }
    }

    if (circuit.size()<m+1){
        printf("IMPOSSIBLE\n");
    }
    else {
        for (int i=0;i<=m;i++){
            printf("%d ",circuit[i]);
        }
    }
    return 0;
}