#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n;
const ll MOD =1e9+7;

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
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    while (n--){
        ll a,b;
        cin >> a >> b;
        cout << pow_mod(a,b) << endl;
    }
    return 0;
}
