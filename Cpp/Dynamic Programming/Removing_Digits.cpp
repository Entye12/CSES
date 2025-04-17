#include <bits/stdc++.h>
using namespace std;

int n;

vector<int> getDigits(int x){
    string s = to_string(x);
    vector<int> digits;
    for (char c:s){
        digits.push_back(c-'0');
    }
    return digits;
}

int main(){
    scanf("%d",&n);
    vector<int> dp(n+1,INT_MAX-100);
    dp[0]=0;
    for (int i=1;i<=n;i++){
        vector<int> digits = getDigits(i);
        int y = INT_MAX;
        for (int x:digits){
            y = min(y,dp[i-x]+1);
        }
        dp[i]=y;
    }
    printf("%d",dp[n]);
    return 0;
}