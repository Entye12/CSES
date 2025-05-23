#include <bits/stdc++.h>
using namespace std;
using tiii = tuple<int,int,int>;
using vtiii = vector<tiii>;
using vi = vector<int>;
using ll = long long;


int n,m,a,b,c;
vtiii edges;
vi rep,sizeComp;
ll cost = 0;



int find(int x){
    while (x!=rep[x]) x = rep[x];
    return x;
}

bool same(int a,int b){
    return (find(a) == find(b));
}

void unite(int a,int b){
    a = find(a); b = find(b);
    if (sizeComp[a] < sizeComp[b]) swap(a,b);
    sizeComp[a] += sizeComp[b];
    rep[b] = a;
}

int main(){
    scanf("%d %d",&n,&m);
    rep.resize(n+1);sizeComp.assign(n+1,1);
    for (int i=1;i<=n;i++) rep[i] = i;
    for (int i=1;i<=m;i++){
        scanf("%d %d %d",&a,&b,&c);
        edges.push_back({a,b,c});
    }
    sort(edges.begin(),edges.end(),[](const tiii& a, const tiii& b){
        return get<2>(a) < get<2>(b);
    });
    int comp = n;
    for (auto e : edges){
        tie(a,b,c) = e;
        if (!same(a,b)){
            unite(a,b);
            cost += c;
            comp--;
        }
    }
    if (comp==1){
        printf("%lld\n",cost);
    }
    else printf("IMPOSSIBLE\n");
    return 0;
}