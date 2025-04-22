#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll MOD = 1e9+7;
int maxn = 1e6; int n,a,b;

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

vector<ll> facto(maxn+1,1);

void init(){
    for (int i=1;i<=maxn;i++){
        facto[i] = (facto[i-1]*i)%MOD;
    }
}


int main(){
    init();
    scanf("%d",&n);

    for (int i=0;i<n;i++){
        scanf("%d %d",&a,&b);
        printf("%lld\n",facto[a] * pow_mod(facto[b],MOD-2) % MOD * pow_mod(facto[a-b],MOD-2) % MOD);
    }
    return 0;
}
