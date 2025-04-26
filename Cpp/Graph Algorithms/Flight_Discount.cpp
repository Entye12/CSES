#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vll = vector<ll>;
using vvll = vector<vll>;
using tllill = tuple<ll,int,ll>;
using pq = priority_queue<tllill, vector<tllill>, greater<tllill>>;
using vvpill = vector<vector<pair<int,ll>>>;

const ll INF = 1e18;
int n,m; int a,b; ll d,c; int coupon;
vvll dist;
vvpill adj;


void dijkstra(){
    pq nextc;
    nextc.push({0,1,0});

    while (!nextc.empty()){
        tie(d,a,coupon) = nextc.top(); nextc.pop();

        if (d>dist[a][coupon]) continue;

        for (auto &[b,c] : adj[a]){

            if (coupon){
                if (dist[b][1] > dist[a][1] + c){
                    dist[b][1] = dist[a][1] + c;
                    nextc.push({dist[b][1],b,1});
                }
            }

            else {
                if (dist[b][1] > dist[a][0] + c/2){
                    dist[b][1] = dist[a][0] + c/2;
                    nextc.push({dist[b][1],b,1});
                }

                if (dist[b][0] > dist[a][0] + c){
                    dist[b][0] = dist[a][0] + c;
                    nextc.push({dist[b][0],b,0});
                }
            }
        }
    }
}

int main(){
    scanf("%d %d",&n,&m);
    dist = vvll(n+1,vll(2,INF));
    dist[1] = {0,1,0};
    adj.resize(n+1);

    for (int i=0;i<m;i++){
        scanf("%d %d %lld",&a,&b,&c);
        adj[a].push_back({b,c});
    }

    dijkstra();
    printf("%lld",dist[n][1]);
    return 0;
}