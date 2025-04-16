#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n; ll MOD = 1e9+7;
vector<ll> ans {1};

int main(){
    scanf("%d",&n);
    for (int i=1;i<=n;i++){
        ll cur =0;
        for (int j=1; j<=6 && i-j>=0 ;j++){
            cur += ans[i-j];
        }
        ans.push_back(cur%MOD);
    }
    printf("%lld",ans.back());
    return 0;
}
