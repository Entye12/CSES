#include <bits/stdc++.h>
using namespace std;
typedef long long ll;


int n; const ll MOD = 1e9+7;

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
    vector<ll> facto(n+1,1);
    for (int i=2;i<n+1;i++){
        facto[i] = (facto[i-1]*i)%MOD;
    }
    ll ans = facto[n];
    for (int k=1;k<=n;k++){
        if (k%2) ans = (MOD + ans - facto[n]*pow_mod(facto[k],MOD-2)%MOD)%MOD;
        else ans = (MOD + ans + facto[n]*pow_mod(facto[k],MOD-2)%MOD)%MOD;
    }
    printf("%lld",ans);
    return 0;
}