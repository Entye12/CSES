#include <bits/stdc++.h>
using namespace std;
typedef long long ll;


const ll MOD = 1e9+7;
int n;

ll fastpow2(ll expo){
    ll ans = 1;
    ll a = 2;
    while (expo>0){
        if (expo&1){
            ans = (ans*a)%MOD;
        }
        a = (a*a)%MOD;
        expo >>= 1;
    }
    return ans;
}

int main(){
    scanf("%d",&n);
    printf("%lld",fastpow2(n));
}