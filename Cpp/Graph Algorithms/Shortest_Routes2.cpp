#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<int>;
using vll = vector<ll>;
using vvll = vector<vll>;



const ll INF = 1e18;
int n,m,q,a,b; ll c,w;
vvll adj,dist;

void floyd_warchall() {
    for (int k = 1; k <= n; k++) {
        for (int j = 1; j <= n; j++) {
            for (int i = 1; i <= n; i++) {
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }
}


int main() {
    scanf("%d %d %d", &n, &m, &q);
    dist = vvll(n+1,vll(n+1,INF));
    
    for (int i=0;i<=n;i++){
        dist[i][i] = 0;
    }

    for (int i = 0; i < m; i++) { 
        scanf("%d %d %lld", &a, &b, &c);
        w = min(dist[a][b],c);
        dist[a][b] = w; dist[b][a] = w;
    }

    floyd_warchall();

    for (int i=0;i<q;i++){
        scanf("%d %d",&a,&b);
        ll w = (dist[a][b]==INF) ? -1 : dist[a][b];
        printf("%lld\n",w);
    }
    return 0;
}