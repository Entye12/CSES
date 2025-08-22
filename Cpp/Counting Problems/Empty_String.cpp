#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vll = vector<ll>;
using vvll = vector<vll>;


const ll MOD = 1e9+7;

ll pow_mod(ll a,ll b){
    ll res = 1;
    a %= MOD;
    while (b>0){
        if (b%2) res = (res*a)%MOD;
        a = (a*a)%MOD;
        b /= 2;
    }
    return res;
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    cin >> s;
    int n = s.size();
    
    vll facto(n+1,1),invfacto(n+1,1);
    for (int i=1;i<=n;i++) facto[i] = (facto[i-1]*i)%MOD;
    invfacto[n] = pow_mod(facto[n],MOD-2);
    for (int i=n-1;i>=1;i--) invfacto[i] = (invfacto[i+1]*(i+1))%MOD;
    
    vvll dp(n,vll(n,0));
    for (int i=0;i<n-1;i++) dp[i+1][i] = 1;
    
    for (int i=n-1;i>=0;i--){
        for (int j=i+1;j<n;j+=2){
            for (int k=i+1;k<j;k+=2){
                if (s[i] == s[k]){
                    ll tmp = (dp[i+1][k-1] * dp[k+1][j])%MOD;
                    ll x = (facto[(j-i+1)/2] * invfacto[(k+1-i)/2])%MOD;
                    x = (x * invfacto[(j-k)/2])%MOD;
                    tmp = (tmp * x)%MOD;
                    dp[i][j] = (dp[i][j] + tmp)%MOD;
                    
                }
            }
            if (s[i] == s[j]){
                dp[i][j] = (dp[i][j] + dp[i+1][j-1])%MOD;
            }
        }
    }
    
    cout << dp[0][n-1] << endl;
    return 0;
}
