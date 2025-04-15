#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n; ll a;

int main(){
    scanf("%d",&n);
    ll sum = 0; ll maxi = 0;
    for (int i=1;i<=n;i++){
        scanf("%lld",&a);
        maxi = max(maxi,a);
        sum += a;
    }
    if (sum < 2*maxi) printf("%lld",2*maxi);
    else printf("%lld",sum);
    return 0;
}