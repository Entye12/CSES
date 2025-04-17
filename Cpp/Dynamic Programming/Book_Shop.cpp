#include <bits/stdc++.h>
using namespace std;

int n,x;

int main(){
    cin >> n >> x;
    vector<int> prices(n); vector<int> pages(n);
    for (int i=0;i<n;i++) {cin >> prices[i];}
    for (int j=0;j<n;j++) {cin >> pages[j];}

    vector<int> dp(x+1,0);

    for (int i=0;i<n;i++){
        int h = prices[i]; int s = pages[i];
        for (int p=x;p>=h;p--){
            dp[p] = max(dp[p],dp[p-h]+s);
        }
    }
    cout << dp[x] << endl;
    return 0;
}