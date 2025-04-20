#include <bits/stdc++.h>
using namespace std;

int n,x;const int top = 1e6+2;
vector<int> n_divisors(top,1);

int main(){
    scanf("%d",&n);
    for (int d=2;d<top;d++){
        for (int i=d;i<top;i+=d){
            n_divisors[i]++;
        }
    }
    for (int i=0;i<n;i++){
        scanf("%d",&x);
        printf("%d\n",n_divisors[x]);
    }
    return 0;
}