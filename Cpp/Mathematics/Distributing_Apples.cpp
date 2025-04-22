#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll MOD = 1e9+7; ll n,m;

ll pow_mod(ll a,ll b){
    ll result = 1;
    a %= MOD;
    while (b>0){
        if (b%2) result = (result*a)%MOD;
        a = (a*a)%MOD;
        b /= 2;
    }
    return result;
}

int main(){
    scanf("%lld %lld",&n,&m);

    vector<ll> facto(n+m,1);
    for (int i=2;i<n+m;i++){
        facto[i] = (facto[i-1]*i)%MOD;
    }
    printf("%lld", facto[n+m-1] * pow_mod(facto[m],MOD-2) % MOD * pow_mod(facto[n-1],MOD-2) % MOD);
    return 0;
}
