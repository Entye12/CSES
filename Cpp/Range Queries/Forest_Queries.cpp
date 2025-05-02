#include <bits/stdc++.h>
using namespace std;
using vi = vector<int>;
using vvi = vector<vi>;
using vs = vector<string>;

int n,q; int x,y,a,b;
vs forest;


int main(){
    scanf("%d %d",&n,&q);
    string s;
    for (int i=0;i<n;i++){
        cin >> s;
        forest.push_back(s);
    }
    vvi grid(n+1,vi(n+1,0));
    for (int i=1;i<=n;i++){
        for (int j=1;j<=n;j++){
            grid[i][j] = grid[i-1][j] + grid[i][j-1] - grid[i-1][j-1];
            if (forest[i-1][j-1] == '*') grid[i][j]++; 
        }
    }
     for (int i=0;i<q;i++){
        scanf("%d %d %d %d", &x,&y,&a,&b);
        printf("%d\n",grid[a][b] - grid[x-1][b] - grid[a][y-1] + grid[x-1][y-1]);
    }
    return 0;
}