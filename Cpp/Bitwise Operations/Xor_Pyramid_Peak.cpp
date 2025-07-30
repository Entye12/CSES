#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vll = vector<ll>;


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    vll a(n);
    for (ll &x:a) cin >> x;

    ll ans = 0;

    for (int k=0;k<n;k++){
        // if binomial(n-1,k) is odd
        if (int (k&~(n-1)) == 0) ans ^= a[k];
    }

    cout << ans << endl;
    return 0;
}
