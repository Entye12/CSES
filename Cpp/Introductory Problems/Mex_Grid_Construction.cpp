#include <bits/stdc++.h>
using namespace std;
using si = unordered_set<int>;

int n;

int mex(si &numbers){
    int x = 0;
    while (numbers.count(x))x++;
    return x;
}

int main(){
    scanf("%d",&n);
    int grid[n][n];
    for (int i=0;i<n;i++){
        grid[i][0] = i;
        grid[0][i] = i;
    }
    for (int i=1;i<n;i++){
        for (int j=1;j<n;j++){
            si numbers{};
            for (int a=0;a<i;a++){
                numbers.insert(grid[a][j]);
            }
            for (int b=0;b<j;b++){
                numbers.insert(grid[i][b]);
            }
            grid[i][j] = mex(numbers);
        }
    }
    for (int i=0;i<n;i++){
        for (int j=0;j<n;j++){
            printf("%d ",grid[i][j]);
        }
        printf("\n");
    }
    return 0;
}