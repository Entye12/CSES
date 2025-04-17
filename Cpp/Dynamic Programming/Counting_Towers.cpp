#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int t,n; const ll MOD = 1e9+7;

int main(){
    cin >> t;
    vector<int> queries(t,0);
    int maxi = 0;
    for (int i=0;i<t;i++) {
        scanf("%d",&n);
        queries[i] = n;
        maxi = max(maxi,n);
    }
    vector<ll> a(maxi+1,0);vector<ll> b(maxi+1,0);vector<ll> ans(maxi+1,0);
    a[1]=1;b[1]=1;ans[1]=2;
    for (int i=2;i<=maxi;i++){
        a[i] = (4*a[i-1]+b[i-1])%MOD;
        b[i] = (a[i-1]+2*b[i-1])%MOD;
        ans[i] = (a[i]+b[i])%MOD;
    }
    for (int n:queries){
        printf("%lld\n",ans[n]);
    }
    return 0;
}