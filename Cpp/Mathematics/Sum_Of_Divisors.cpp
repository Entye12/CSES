#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll MOD = 1e9+7;
ll n;

// Modular inverse of 2 modulo MOD = 500000004
ll sum_arithmetic(ll a, ll b){
    if (a > b) return 0;
    ll len = (b - a + 1) % MOD;
    ll sum = (a + b) % MOD;
    return (len * sum % MOD * 500000004 % MOD);
}

int main(){
    scanf("%lld", &n);

    ll x = 1;
    while (x * x <= n) x++;
    x--;

    ll ans = 0;
    for (ll p = 1; p <= x; p++){
        ans = (ans + p * (n / p) % MOD) % MOD;
    }

    for (ll q = x; q > 0; q--){
        ll upper_bound = n / q;
        ll lower_bound = max(n / (q + 1) + 1, x + 1);
        ans = (ans + q * sum_arithmetic(lower_bound, upper_bound) % MOD) % MOD;
    }

    printf("%lld\n", ans);
    return 0;
}
