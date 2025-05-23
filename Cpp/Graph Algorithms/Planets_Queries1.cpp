#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;

int n,q,x; ll k;
const int r = 30;

int main(){
    scanf("%d %d",&n,&q);
    vvi step(r+1,vi(n+1,0));

    for (int i=1;i<=n;i++){
        scanf("%d",&step[0][i]);
    }
    for (int e=1;e<=r;e++){
        for (int i=1;i<=n;i++){
            step[e][i] = step[e-1][step[e-1][i]];
        }
    }

    for (int i=1;i<=q;i++){
        scanf("%d %lld",&x,&k);
        
        for (int ord=0;ord<r;ord++){
            if (k & (1LL<<ord)) x = step[ord][x];
        }
        printf("%d\n",x);
    }
    return 0;
}