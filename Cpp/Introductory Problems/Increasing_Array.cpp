#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n;
ll ans = 0, x, bx;


int main(){
    scanf("%d",&n);
    scanf("%lld", &bx);
    for (int i=1; i<n; i++){
        scanf("%lld",&x);
        bx = max(bx,x);
        ans += (bx-x);
    }
    printf("%lld\n", ans);
}