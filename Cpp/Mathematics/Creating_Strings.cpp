#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll MOD = 1e9+7;

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

string s;
unordered_map<char,int> counter;

int main(){
    cin >> s;
    int n = s.size();
    vector<ll> facto(n+1,1);
    for (int i=2;i<n+1;i++){
        facto[i] = (facto[i-1]*i)%MOD;
    }
    for (char c:s){
        counter[c]++;
    }

    ll res = facto[n];
    for (const auto& [c,v]:counter){
        res = (res*pow_mod(facto[v],MOD-2))%MOD;
    }
    cout << res << endl;
    return 0;
}