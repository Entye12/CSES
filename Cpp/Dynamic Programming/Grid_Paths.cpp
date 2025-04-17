#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n; char c;
vector<vector<ll>> matrix;
ll MOD = 1e9+7;

int main(){
    cin >> n;
    matrix.resize(n,vector<ll>(n));
    for (int i=0;i<n;i++){
        string row;
        cin >> row;
        for (int j=0;j<n;j++){
            matrix[i][j] = (row[j] == '*') ? 0 : 1;
        }
    }

    if (matrix[0][0] == 0) {
        cout << 0 << endl;
        return 0;
    }

    for (int i=0;i<n;i++){
        for (int j=0;j<n;j++){
            if (i == 0 && j == 0) continue; 
            if (matrix[i][j] == 0) continue;

            ll x = 0;
            if (i>0) x += matrix[i-1][j];
            if (j>0) x += matrix[i][j-1];
            matrix[i][j] = x%MOD;
            
        }
    }
    cout << matrix[n-1][n-1] <<endl;
    return 0;
}
