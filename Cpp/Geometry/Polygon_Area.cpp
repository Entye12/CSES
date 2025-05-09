#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int n;
ll x,y,a,b,c,d;

int main(){
    ll s = 0;
    scanf("%d",&n);
    scanf("%lld %lld",&x,&y);
    c = x; d = y;
    for (int i=0;i<n-1;i++){
        scanf("%lld %lld",&a,&b);
        s += (x*b-a*y);
        x = a; y = b;
    }
    s += (x*d-y*c);
    printf("%lld\n",abs(s));
    return 0;
}