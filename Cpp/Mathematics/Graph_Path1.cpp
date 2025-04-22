#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n,m,a,b;ll k;
const ll MOD = 1e9+7;

vector<vector<ll>> multiply(vector<vector<ll>> &mat1, vector<vector<ll>> &mat2){
    int s = mat1.size();
    vector<vector<ll>> res(s,vector<ll>(s,0));
    for (int i=0;i<s;i++){
        for (int k=0;k<s;k++){
            for (int j=0;j<s;j++){
                res[i][j] = (res[i][j] + mat1[i][k]*mat2[k][j])%MOD;
            }
        }
    }
    return res;
}

vector<vector<ll>> matrix_power(vector<vector<ll>> &mat, ll expo){
    int s = mat.size();
    vector<vector<ll>> ans(s,vector<ll>(s,0));
    for (int k=0;k<s;k++) ans[k][k] = 1;

    while (expo>0){
        if (expo%2) ans = multiply(ans, mat);
        mat = multiply(mat,mat);

        expo/=2;
    }
    return ans;
}

int main(){
    scanf("%d %d %lld", &n, &m, &k);
    vector<vector<ll>> adj_matrix(n,vector<ll>(n,0));
    for (int i=0;i<m;i++){
        scanf("%d %d",&a,&b);
        adj_matrix[a-1][b-1]++;
    }
    vector<vector<ll>> res = matrix_power(adj_matrix,k);
    ll ans = res[0][n-1];
    printf("%lld\n", ans);
    return 0;
}