#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll n,x,c;
vector<ll> dp {0};set<ll> coins;

int main(){
    scanf("%lld %lld",&n,&x);
    for (ll i=1;i<=n;i++){
        scanf("%lld",&c);
        coins.insert(c);
    }
    for (ll i=1;i<=x;i++){
        ll mini = LLONG_MAX;
        for (const auto& c:coins){
            if (i-c<0) break;

            if (dp[i-c] != LLONG_MAX) mini = min(mini,dp[i-c]+1);
        }
        dp.push_back(mini);
    }
    printf("%lld", dp.back() != LLONG_MAX ? dp.back() : -1LL);
    return 0;
}