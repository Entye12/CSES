#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n;ll x;

int main(){
    cin >> n;
    vector<ll> numbers(n,0);
    for (int i=0;i<n;i++){
        cin >> x;
        numbers[i] = x;
    }
    vector<pair<ll,ll>> prev_diff(n);
    for (int i=0;i<n;i++){prev_diff[i] = {numbers[i],0};}

    for (int diff=1;diff<n;diff++){
        vector<pair<ll,ll>> cur_diff;
        for (int i=0;i<n-diff;i++){
            ll way1 = numbers[i] + prev_diff[i+1].second;
            ll way2 = numbers[i+diff] + prev_diff[i].second;
            ll gain1 = max(way1,way2);
            ll gain2 = (gain1 == way1) ? prev_diff[i+1].first : prev_diff[i].first;
            cur_diff.push_back({gain1,gain2});
        }
        prev_diff = cur_diff;
    }
    cout << prev_diff[0].first << endl;
    return 0;
}