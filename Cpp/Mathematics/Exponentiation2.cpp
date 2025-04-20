#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n; const ll MOD = 1e9+7; ll a,b,c;

ll power(ll a, ll b,ll MOD){
    ll res = 1; a %= MOD;
    while (b>0){
        if (b%2) res = (res*a)%MOD;
        a = (a*a)%MOD;
        b /= 2;
    }
    return res;
}

int main(){
    scanf("%d",&n);
    for (int i=1;i<=n;i++){
        scanf("%lld %lld %lld",&a,&b,&c);
        ll exp = power(b,c,MOD-1);
        printf("%lld\n",power(a,exp,MOD));
    }
    return 0;
}