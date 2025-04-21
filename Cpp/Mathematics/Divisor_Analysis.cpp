#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n; const ll MOD = 1e9+7; const int maxn = 1e5;
ll tau, sigma, ci, mu;

ll pow_mod(ll a,ll b,ll mod){
    ll result = 1;
    a %= mod;
    while (b>0){
        if (b%2) result = (result*a)%mod;
        a = (a*a)%mod;
        b /= 2;
    }
    return result;
}


int main(){
    scanf("%d", &n);
    ll x[n], k[n];
    for(int i = 0; i < n; i++)
        scanf("%lld %lld", &x[i], &k[i]);


    tau = 1;
    for(int i = 0; i < n; i++)
        tau = (tau * (k[i]+1)) % MOD;

    sigma = 1;
    for(int i = 0; i < n; i++){
        ll numerator = (pow_mod(x[i], k[i]+1, MOD)-1+MOD) % MOD;
        ll denominator = pow_mod(x[i]-1, MOD-2,MOD);
        ll r = numerator * denominator % MOD;
        sigma = (sigma * r) % MOD;
    }

    mu = 1;
    ci = 1;
    for (int i=0; i<n; i++){
        ll p = pow_mod(x[i],k[i]*(k[i]+1)/2,MOD);
        mu = (pow_mod(mu,k[i]+1,MOD)*pow_mod(p,ci,MOD))%MOD;
        ci = (ci*(k[i]+1))%(MOD-1);
    }

    printf("%lld %lld %lld\n", tau, sigma, mu);
    return 0;
}