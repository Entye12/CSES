#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n; ll a; ll prefixsum = 0; ll ans = 0;
unordered_map<int,ll> modulo_freq{{0,1}};

int main(){
    scanf("%d",&n);
    for (int i=1; i<=n;i++){
        scanf("%lld",&a);
        prefixsum = (prefixsum+a)%n;
        prefixsum = (prefixsum+n)%n;
        ans += modulo_freq[prefixsum];
        modulo_freq[prefixsum]++;
    }
    printf("%lld",ans);
    return 0;
}