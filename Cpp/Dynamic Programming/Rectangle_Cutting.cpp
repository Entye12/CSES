#include <bits/stdc++.h>
using namespace std;

int a,b;

int main(){
    cin >> a >> b;
    vector<vector<int>> dp(a+1,vector<int>(b+1,0));

    for (int i=1;i<=a;i++){
        for (int j=1;j<=b;j++){
            if (i==j) continue;
            if (i==1) dp[i][j]=j-1;
            if (j==1) dp[i][j]=i-1;

            int x = INT_MAX;
            for (int k=1;k<=i-1;k++){
                x = min(x,dp[i-k][j]+dp[k][j]+1);
            }
            for (int k=1;k<=j-1;k++){
                x = min(x,dp[i][j-k]+dp[i][k]+1);
            }
            dp[i][j]=x;
        }
    }
    cout << dp[a][b] << endl;
    return 0;
}