#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll n;

bool ok(ll x){
    ll r = 0;
    for (ll i = 1; i <= n; ++i){
        r += min(x / i, n);
    }
    return r >= (n * n + 1) / 2;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;

    ll x = -1;
    for (ll v = n * n; v >= 1; v /= 2){
        while (!ok(x + v)) x += v;
    }
    x++;

    cout << x << endl;
    return 0;
}
