#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n,x,c; const ll MOD=1e9+7;
vector<ll> dp {1}; set<ll> coins;

int main(){
    scanf("%d %d",&n,&x);
    for (int i=1;i<=n;i++){
        scanf("%d",&c);
        coins.insert(c);
    }
    for (int i=1;i<=x;i++){
        ll a = 0;
        for (const auto& c:coins){
            if (i-c<0) break;
            a = (a+dp[i-c])%MOD;
        }
        dp.push_back(a);
    }
    printf("%lld",dp.back());
    return 0;
}