#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vll = vector<ll>;


const ll MOD = 1e9+7;
int maxn = 1e6;

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
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    vll facto(maxn+1,1);
    for (int i=1;i<=maxn;i++) facto[i] = (facto[i-1]*i)%MOD;

    vll invfacto(maxn+1,1);
    invfacto[maxn] = pow_mod(facto[maxn],MOD-2);
    for (int i=maxn;i>=1;i--) invfacto[i-1] = (invfacto[i]*i)%MOD;

    for (int i=0;i<n;i++){
        int a,b;
        cin >> a >> b;
        cout << facto[a] * invfacto[b] % MOD * invfacto[a-b] % MOD << endl;
    }
    return 0;
}