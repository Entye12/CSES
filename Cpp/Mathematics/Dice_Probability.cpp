#include <bits/stdc++.h> 
using namespace std;


int n,a,b;

int main(){
    scanf("%d %d %d",&n,&a,&b);
    vector<double> prev(6*n+1,0.0);
    prev[0] = 1.0;

    for (int k=1;k<n+1;k++){
        vector<double> cur(6*n+1,0.0);
        for (int x=k;x<=6*k;x++){
            for (int l=1;l<=6;l++){
                if (x-l>=0) cur[x] += prev[x-l]/6;
            }
        }
        prev = cur;
    }
    double s=0;
    for (int i=a;i<=b;i++){
        s += prev[i];
    }
    printf("%.6f\n", s);
    return 0;
}  