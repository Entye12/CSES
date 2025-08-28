#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using vi = vector<int>;
#define all(x) (x).begin(),(x).end()

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    vi a(n+2,0);
    for (int i=1;i<=n;i++){
        cin >> a[i];
    }
    
    vi maxMvtLeft(n+1,0);
    stack<pii> sl;
    sl.push({0,0});
    for (int i=1;i<=n;i++){
        while (sl.top().first >= a[i]){
            sl.pop();
        }
        maxMvtLeft[i] = sl.top().second + 1;
        sl.push({a[i],i});
    }
    
    vi maxMvtRight(n+1,0);
    stack<pii> sr;
    sr.push({0,n+1});
    for (int i=n;i>0;i--){
        while (sr.top().first >= a[i]){
            sr.pop();
        }
        maxMvtRight[i] = sr.top().second - 1;
        sr.push({a[i],i});
    }
    
    ll ans = 0;
    for (int i=1;i<=n;i++){
        ans = max(ans, 1LL * (maxMvtRight[i] - maxMvtLeft[i] + 1) * a[i]);
    }
    
    cout << ans << endl;
    return 0;
}
