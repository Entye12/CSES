#include <bits/stdc++.h>
using namespace std;
typedef long long ll;


const ll MOD = 1e9+7;
ll n;

vector<vector<ll>> mat = {{0, 1}, {1, 1}};

void matrix_multiply(vector<vector<ll>> &mat1, vector<vector<ll>> &mat2){
    
    ll x = (mat1[0][0] * mat2[0][0] + mat1[0][1] * mat2[1][0])%MOD;
    ll y = (mat1[0][0] * mat2[0][1] + mat1[0][1] * mat2[1][1])%MOD;
    ll z = (mat1[1][0] * mat2[0][0] + mat1[1][1] * mat2[1][0])%MOD;
    ll w = (mat1[1][0] * mat2[0][1] + mat1[1][1] * mat2[1][1])%MOD;

    
    mat1[0][0] = x; mat1[0][1] = y;
    mat1[1][0] = z; mat1[1][1] = w;
}


vector<vector<ll>> matrix_power(vector<vector<ll>> mat, ll expo) {
    vector<vector<ll>> ans = {{1, 0}, {0, 1}};
    while (expo > 0) {
        if (expo % 2) matrix_multiply(ans, mat);
        matrix_multiply(mat, mat);
        expo /= 2;
    }
    return ans;
}

int main(){
    scanf("%lld",&n);
    vector<vector<ll>> ans = matrix_power(mat,n);
    printf("%lld",ans[0][1]);
    return 0;
}