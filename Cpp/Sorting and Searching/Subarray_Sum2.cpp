#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n; ll x; ll a; ll prefixsum = 0; ll ans =0;
map<ll,ll> dico{{0,1}};

int main(){
    scanf("%d %lld",&n,&x);
    for (int i=0;i<n;i++){
        scanf("%lld",&a);
        prefixsum += a;
        ans += dico[prefixsum-x];
        dico[prefixsum]++;
    }
    printf("%lld",ans);
    return 0;
}