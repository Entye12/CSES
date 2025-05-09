#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int t;
ll x,y,a,b,c,d,u,v;

int orientation(ll x, ll y, ll a, ll b){
    ll val = x*b - y*a;
    if (val > 0) return 1;
    else if (val == 0) return 0;
    return 2;
}
bool possible_on_segment(ll x,ll y,ll a,ll b,ll z, ll w){
    return (min(a,x) <= z && z <= max(a,x) && min(y,b) <= w && w <= max(y,b));
}

int main(){
    scanf("%d",&t);
    for (int i=0;i<t;i++){
        scanf("%lld %lld %lld %lld %lld %lld %lld %lld",&x,&y,&a,&b,&c,&d,&u,&v);
        int or1 = orientation(a-x,b-y,c-x,d-y);
        int or2 = orientation(a-x,b-y,u-x,v-y);
        int or3 = orientation(u-c,v-d,x-c,y-d);
        int or4 = orientation(u-c,v-d,a-c,b-d);
        if ((or1 != or2) && (or3!=or4)) printf("YES\n");
        else if (or1 == 0 && possible_on_segment(x,y,a,b,c,d)) printf("YES\n");
        else if (or2 == 0 && possible_on_segment(x,y,a,b,u,v)) printf("YES\n");
        else if (or3 == 0 && possible_on_segment(c,d,u,v,x,y)) printf("YES\n");
        else if (or4 == 0 && possible_on_segment(c,d,u,v,a,b)) printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}