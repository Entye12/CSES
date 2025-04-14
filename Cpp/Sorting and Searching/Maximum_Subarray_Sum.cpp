#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll inf = 1e10;

int n;
ll ans = -inf; ll sum = 0; ll x;

int main(){
    scanf("%d",&n);
    for (int i=1; i<=n;i++){
        scanf("%lld",&x);
        sum += x;
        ans = max(ans,sum);
        if (sum<0) {sum = 0;}
    }
    printf("%lld\n",ans);
    return 0;
}