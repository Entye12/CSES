#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vll = vector<ll>;


int n,q,a,b; ll x,s;


int main(){
    scanf("%d %d",&n,&q);
    vll prefixSum(n+1,0);
    for (int i=1;i<=n;i++){
        scanf("%lld",&x);
        prefixSum[i] = prefixSum[i-1] + x;
    }
    for (int i=0;i<q;i++){
        scanf("%d %d",&a,&b);
        s = prefixSum[b]-prefixSum[a-1];
        printf("%lld\n",s);
    }
    return 0;
}
