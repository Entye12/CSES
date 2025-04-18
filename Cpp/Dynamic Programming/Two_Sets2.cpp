#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n; const ll MOD = 1e9+7;

int main(){
    cin >> n;
    if (n%4==1 || n%4==2) {
        cout << 0 << endl;
        return 0;
    }
    int target = n*(n+1)/4;
    vector<ll> prev(target+1,0);
    prev[0]=1;
    for (int i=1;i<=n;i++){
        vector<ll> cur(target+1,0);
        for (int s=0;s<=target;s++){
            cur[s] = prev[s];
            if (s>=i) cur[s] = (cur[s] + prev[s-i])%MOD;
        }
        prev = cur;
    }
    ll result = prev[target];
    result = (result * ((MOD + 1)/2)) % MOD;
    cout << result <<endl;
    return 0;
}