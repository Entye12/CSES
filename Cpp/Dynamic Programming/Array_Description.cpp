#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll MOD = 1e9+7; int n,m;

int main(){
    cin >> n >> m;
    vector<int> numbers(n,0);
    for (int i=0;i<n;i++) cin >> numbers[i];
    vector<ll> prev(m+1,0);
    if (numbers[0]==0) { fill(prev.begin() + 1, prev.end(), 1);}
    else {prev[numbers[0]] = 1;}

    for (int i=1;i<n;i++){
        vector<ll> cur(m+1,0);
        int x = numbers[i];
        if (x>0){
            cur[x] += prev[x];
            if (x>1) {cur[x] += prev[x-1];}
            if (x<m) {cur[x] += prev[x+1];}
            cur[x] %= MOD;
        }
        else {
            for (int j = 1; j <= m; j++) {
                if (j > 1) cur[j] += prev[j - 1];
                cur[j] += prev[j];
                if (j < m) cur[j] += prev[j + 1];
                cur[j] %= MOD;
            }
        }
        prev = cur;
    }
    ll ans = accumulate(prev.begin(), prev.end(), 0LL,
        [](ll a, ll b) {
            return (a + b) % MOD;
        });
    cout << ans << endl;
    return 0;
}