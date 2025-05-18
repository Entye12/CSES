#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using umlli = unordered_map<ll,int>;

const ll MOD = 1e9+7;
int n;
umlli freq;


int main(){
    scanf("%d",&n);
    for (int i=0;i<n;i++){
        ll x;
        scanf("%lld",&x);
        freq[x]++;
    }
    ll ans = 1;

    for (const auto& pair: freq){
        ans = (ans * (1+pair.second))%MOD;
    }
    ans = (ans - 1 + MOD)%MOD;
    printf("%lld",ans);
    return 0;
}