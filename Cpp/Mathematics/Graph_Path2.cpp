#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vvll = vector<vector<ll>>;
using vll = vector<ll>;

int n,m,a,b;ll k,c;
const ll INF = 4e18;

vvll min_multiply(vvll &mat1, vvll &mat2){
    int s = mat1.size();
    vvll res(s,vll(s,INF));
    for (int i=0;i<s;i++){
        for (int k=0;k<s;k++){
            for (int j=0;j<s;j++){
                res[i][j] = min(res[i][j],mat1[i][k]+mat2[k][j]);
            }
        }
    }
    return res;
}

vvll matrix_power(vvll &mat, ll expo){
    int s = mat.size();
    vvll ans(s,vector<ll>(s,INF));
    for (int k=0;k<s;k++) ans[k][k] = 0;

    while (expo>0){
        if (expo%2) ans = min_multiply(ans, mat);
        mat = min_multiply(mat,mat);

        expo/=2;
    }
    return ans;
}

int main(){
    scanf("%d %d %lld", &n, &m, &k);
    vvll adj_matrix(n,vll(n,INF));
    for (int i=0;i<m;i++){
        scanf("%d %d %lld",&a,&b,&c);
        adj_matrix[a-1][b-1] = min(adj_matrix[a-1][b-1],c);
    }
    vvll res = matrix_power(adj_matrix,k);
    ll ans = res[0][n-1];
    if (ans == INF) printf("%d",-1);
    else  printf("%lld\n", ans);
    return 0;
}