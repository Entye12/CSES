#include <bits/stdc++.h>
using namespace std;

string w1,w2;

int main(){
    cin >> w1 >> w2;
    int n=w1.length(); int m=w2.length();
    vector<vector<int>> dp(n+1,vector<int>(m+1,0));
    for (int i=0;i<=n;i++) {dp[i][0] = i;}
    for (int j=0;j<=m;j++) {dp[0][j] = j;}
    
    
    for (int i=1;i<=n;i++){
        for (int j=1;j<=m;j++){
            int x = (w1[i-1]!=w2[j-1]);
            dp[i][j] = min({dp[i-1][j-1]+x,dp[i-1][j]+1,dp[i][j-1]+1});
        }
    }
    cout << dp[n][m] << endl;
    return 0;
}