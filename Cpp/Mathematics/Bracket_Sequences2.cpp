#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll MOD = 1e9+7;
int n; string prefix;

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

ll binomial(int m, int k, vector<ll> &facto){
    ll res = facto[m];
    res = res * pow_mod(facto[k],MOD-2) % MOD;
    res = res * pow_mod(facto[m-k],MOD-2) % MOD;
    return res;
}

int main(){
    cin >> n;
    cin >> prefix;
    int u = 0; int d = 0;

    if (n%2){
        printf("%d",0);
        return 0;
    }

    for (char c: prefix){
        if (c == '(') u++;
        else d++;

        if (u-d<0) {
            printf("%d",0);
            return 0;
        }
    }
    if (u>n/2){
        printf("%d",0);
        return 0;
    }
    else if (u == n/2){
        printf("%d",1);
        return 0;
    }

    vector<ll> facto(n+1,1);
    for (int i=2;i<n+1;i++){
        facto[i] = (facto[i-1]*i)%MOD;
    }
    

    ll a = binomial(n - (u + d), n / 2 - u, facto);
    ll b = binomial(n - (u + d), n / 2 - d + 1, facto);
    ll ans = (a - b + MOD) % MOD;

    printf("%lld",ans);
    return 0;
}