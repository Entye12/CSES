#include <bits/stdc++.h>
using namespace std;
using pi = pair<int,int>;
using vpi = vector<pi>;
using vi = vector<int>;


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n,x;
    cin >> n >> x;
    
    vi w(n,0);
    for (int &y : w) cin >> y;
    
    vpi best(1<<n,{n+1,0});
    best[0] = {1,0};
    
    for (int mask=1;mask<(1<<n);mask++){
        for (int i=0;i<n;i++){
            if (mask & (1<<i)){
                pi option = best[mask^(1<<i)];
                if (option.second + w[i] <= x) option.second += w[i];
                else {
                    option.first++;
                    option.second = w[i];
                }
                best[mask] = min(best[mask],option);
            }
        }
    }
    int ans = best[(1<<n)-1].first;
    
    cout << ans << endl;
    
    return 0;
}