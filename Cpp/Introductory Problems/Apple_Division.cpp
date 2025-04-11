#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int n;
vector<int> weights;

ll f(int i,ll a,ll b){
    if (i>=n) return abs(a-b);
    else return min(f(i+1,a+weights[i],b),f(i+1,a,b+weights[i]));
}

int main(){
    scanf("%d",&n);
    ll x;
    for (int i=1;i<=n;i++) {
        cin >> x;
        weights.push_back(x);
    }
    ll ans = f(1,weights[0],0);
    printf("%lld\n",ans);
    return 0;
}