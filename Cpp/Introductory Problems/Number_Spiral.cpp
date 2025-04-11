#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int t;
ll x, y;

ll numberSpiral(ll x,ll y){
    ll m = max(x,y);
    if (m&1) {
        if (x > y) return (m-1)*(m-1)+y;
        else return m*m-x+1;
    }
    else {
        if (x>y) return m*m-y+1;
        else return (m-1)*(m-1)+x;
    }
}

int main(){
    scanf("%d",&t);
    for (int i=1;i<=t;i++){
        scanf("%lld %lld",&x,&y);
        printf("%lld\n",numberSpiral(x,y));
    }
}