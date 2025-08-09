#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;
using vl = vector<ll>;
using vvl = vector<vl>;

const ll MOD = 1e9+7;
const int MAX_N = 20;



int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n,m;
    cin >> n >> m;

    vvi radj(n);

    for (int i=1;i<=m;i++){
        int a,b;
        cin >> a >> b;
        radj[--b].push_back(--a);
    }  

    vvl dp(1<<MAX_N,vl(MAX_N,0));
    dp[1][0] = 1;

    for (int s = 2;s < (1<<n); s++){
        if ((s & (1<<0)) == 0) continue;

        if ((s & (1<<(n-1))) && s != ((1<<n)-1) ) continue;

        for (int i=0;i<n;i++){
            if ((s & (1<<i)) == 0) continue;

            for (int j : radj[i]){
                if ((s & (1<<j))){
                    dp[s][i] = (dp[s-(1<<i)][j] + dp[s][i])%MOD;
                }
                    
            }
        }
    }

    cout << dp[(1<<n)-1][n-1] << endl;
    
    return 0; 
}