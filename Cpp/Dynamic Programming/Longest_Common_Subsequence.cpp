#include <bits/stdc++.h>
using namespace std;
using vi = vector<int>;
using vvi = vector<vi>;

int n,m;

int main(){
    scanf("%d %d",&n,&m);
    vi A(n+1,0); vi B(m+1,0); vvi dp(n+1,vi(m+1,0));
    for (int i=1;i<=n;i++){
        scanf("%d",&A[i]);
    }
    for (int j=1;j<=m;j++){
        scanf("%d",&B[j]);
    }
    for (int i=1;i<=n;i++){
        for (int j=1;j<=m;j++){
            if (A[i]==B[j]) dp[i][j] = dp[i-1][j-1] + 1;
            else dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
        }
    }

    vi ans;
    int i = n; int j = m;
    printf("%d\n",dp[i][j]);
    while (i>0 && j>0){
        if (A[i]==B[j]){
            ans.push_back(A[i]);
            i--;j--;
        }
        else if (dp[i-1][j] > dp[i][j-1]) {
            i--;
        } 
        else {
            j--;
        }
    }
    
    reverse(ans.begin(), ans.end());
    for (int x : ans) printf("%d ",x);
    return 0;
}