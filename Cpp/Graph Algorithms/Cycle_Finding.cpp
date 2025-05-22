#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vll = vector<ll>;
using vtiill = vector<tuple<int,int,ll>>;
using vi = vector<int>;

int n,m,x; int a,b; ll c;


int main(){
    scanf("%d %d",&n,&m);
    vi parents(n+1,-1);
    vll distances(n+1,0);
    vtiill edges(m);
    for (int i=0;i<m;i++){
        scanf("%d %d %lld",&a,&b,&c);
        edges[i] = {a,b,c};
    }

    for (int i=1;i<=n;i++){
        x = -1;
        for (auto e:edges){
            tie(a,b,c) = e;
            if (distances[b] > distances[a]+c){
                distances[b] = distances[a]+c;
                parents[b] = a;
                x = b;
            }
        }
    }

    if (x==-1) printf("NO\n");
    else {
        printf("YES\n");
        for (int i=1;i<=n;i++) x = parents[x];

        vi cycle;
        for (int v=x;;v=parents[v]){
            cycle.push_back(v);
            if (v==x && cycle.size() > 1) break;
        }
        reverse(cycle.begin(),cycle.end());
        for (int v:cycle) printf("%d ",v);
    }
    
    return 0;
}