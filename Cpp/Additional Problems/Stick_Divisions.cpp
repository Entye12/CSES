#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vll = vector<ll>;
using pqll = priority_queue<ll,vll,greater<ll>>;

int n;
ll x;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> x >> n;
    pqll pq;
    for (int i=0;i<n;i++){
        ll y;
        cin >> y;
        pq.push(y);
    }
    
    ll ans = 0;
    for (int i=1;i<n;i++){
        ll d1 = pq.top(); pq.pop();
        ll d2 = pq.top(); pq.pop();
        ans += (d1+d2);
        pq.push(d1+d2);
    }
    
    cout << ans << endl;
    return 0;
}
