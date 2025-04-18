#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n;ll a,b,x;


int main(){
    cin >> n;
    vector<tuple<ll,ll,ll>> projects;
    for (int i=0;i<n;i++){
        cin >> a >> b >> x;
        projects.emplace_back(a,b,x);
    }
    sort(projects.begin(),projects.end(),[](const auto &a, const auto &b){
        return get<1>(a) < get<1>(b);
    });
    map<ll,ll> dp;
    dp[0]=0;

    for (auto &[s, e, r] : projects){

        auto it = dp.upper_bound(s-1);
        it--;
        ll best_before = it->second;
        ll current = max(best_before+r,dp.rbegin()->second);
        dp[e] = current;   
    }
    cout << dp.rbegin()->second << endl;
    return 0;
}