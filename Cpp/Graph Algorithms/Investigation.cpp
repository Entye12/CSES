#include <bits/stdc++.h>
using namespace std;
using vi = vector<int>;
using ll = long long;
using vll = vector<ll>;
using plli = pair<ll,int>;
using vvpill = vector<vector<pair<int,ll>>>;
using pqplli = priority_queue<plli,vector<plli>,greater<pair<ll,int>>>;
using usi = unordered_set<int>;

const ll MOD = 1e9+7;
const ll INF = 1e18;

int n,m,a,b; ll c,d;
vvpill routes;
vll distances; 
pqplli nextc;
vi miniNb, maxiNb;
vll countNb;


void dijkstra() {
    distances = vll(n+1, INF);

    distances[1] = 0;
    nextc.push({0, 1});
    miniNb[1] = 0; maxiNb[1] = 0; countNb[1] = 1;

    while (!nextc.empty()) {
        tie(d, a) = nextc.top(); nextc.pop(); 
        
        if (d>distances[a]) continue;

        for (auto &[b, c] : routes[a]) {
            if (c + distances[a] < distances[b]) {
                distances[b] = c + distances[a];
                nextc.push({distances[b], b});
                miniNb[b] = miniNb[a]+1; maxiNb[b] = maxiNb[a]+1;countNb[b]=countNb[a];
            }
            else if (c + distances[a] == distances[b]){
                miniNb[b] = min(miniNb[b],miniNb[a]+1);
                maxiNb[b] = max(maxiNb[b],maxiNb[a]+1);
                countNb[b] = (countNb[b]+countNb[a])%MOD;
            }
        }
    }
}


int main(){
    scanf("%d %d",&n,&m);
    routes.resize(n+1); miniNb.assign(n+1,INT_MAX);maxiNb.assign(n+1,0);countNb.assign(n+1,0);
    for (int i=0;i<m;i++){
        scanf("%d %d %lld",&a,&b,&c);
        routes[a].push_back({b,c});
    }

    dijkstra();
    printf("%lld %lld %d %d\n",distances[n],countNb[n],miniNb[n],maxiNb[n]);
    return 0;
}