#include <bits/stdc++.h>
using namespace std;

const int n = 8;
int ans=0;
vector<string> matrix;

unordered_map<int,bool> col, diag1, diag2;
vector<vector<int>> mat_diag1(n, vector<int>(n, 0));
vector<vector<int>> mat_diag2(n, vector<int>(n, 0));

void preprocessing(){
    for (int i=1;i<=2*n-2;i++){
        col[i] = false;
        diag1[i] = false;
        diag2[i] = false;
    }
    for (int i=0; i<n;i++){
        for (int j=0; j<n;j++){
            mat_diag1[i][j] = i-j+n-1;
            mat_diag2[i][j] = i+j;
        }
    }
}

int backtrack(int row,unordered_map<int, bool>& col, unordered_map<int, bool>& diag1, unordered_map<int, bool>& diag2){
    if (row == n){
        ans++;
        return 0;
    }
    for (int c=0;c<n;c++){
        if (col[c] || diag1[mat_diag1[row][c]] || diag2[mat_diag2[row][c]] || matrix[row][c] == '*') continue;

        col[c] = true; diag1[mat_diag1[row][c]] = true; diag2[mat_diag2[row][c]] = true;
        backtrack(row+1, col, diag1, diag2);
        col[c] = false; diag1[mat_diag1[row][c]] = false; diag2[mat_diag2[row][c]] = false;
    }
    return 0;
}


int main(){
    string line;
    for (int i=0;i<8;i++){
        getline(cin, line);
        matrix.push_back(line);
    }
    preprocessing();
    backtrack(0,col,diag1,diag2);
    printf("%d\n",ans);
    return 0;
}