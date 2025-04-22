#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll MOD = 1e9+7;
int n;

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
    scanf("%d",&n);
    if (n%2) {
        printf("%d",0);
        return 0;
    }
    vector<ll> facto(n+1,1);
    for (int i=2;i<n+1;i++){
        facto[i] = (facto[i-1]*i)%MOD;
    }
    ll res = facto[n];
    res = (res*pow_mod(facto[n/2],MOD-2) + MOD)%MOD;
    res = (res*pow_mod(facto[n/2],MOD-2) + MOD)%MOD;
    res = (res*pow_mod(n/2 + 1,MOD-2) + MOD)%MOD;

    printf("%lld",res);
    return 0;
}