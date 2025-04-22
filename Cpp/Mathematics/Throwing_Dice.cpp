#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll MOD = 1e9+7; ll n;

vector<vector<ll>> multiply(vector<vector<ll>> &mat1, vector<vector<ll>> &mat2){
    vector<vector<ll>> res(6,vector<ll>(6,0));
    for (int i=0;i<6;i++){
        for (int j=0;j<6;j++){
            for (int k=0;k<6;k++){
                res[i][j] = (res[i][j] + mat1[i][k]*mat2[k][j])%MOD;
            }
        }
    }
    return res;
}

vector<vector<ll>> matrix_power(vector<vector<ll>> &mat, ll expo){
    vector<vector<ll>> ans(6,vector<ll>(6,0));
    for (int k=0;k<6;k++) ans[k][k] = 1;

    while (expo>0){
        if (expo%2) ans = multiply(ans, mat);
        mat = multiply(mat,mat);

        expo/=2;
    }
    return ans;
}

int main(){
    scanf("%lld",&n);
    vector<ll> initial({1,1,2,4,8,16,32});
    if (n<=6){
        printf("%lld",initial[n]);
        return 0;
    }

    vector<vector<ll>> A;
    for (int i = 0; i < 5; i++) {
        vector<ll> row(6, 0);
        row[i + 1] = 1;
        A.push_back(row);
    }
    vector<ll> last_row(6, 1);
    A.push_back(last_row);

    vector<vector<ll>> A_pow = matrix_power(A,n);
    ll ans = 0;
    for (int j=0;j<6;j++){
        ans = (ans + A_pow[0][j]*initial[j])%MOD;
    }
    printf("%lld", ans);
    return 0;
}