#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int t;
ll x,y,a,b,c,d;

ll vecto(ll x, ll y, ll a, ll b){
    return x*b - y*a;
}

int main(){
    scanf("%d",&t);
    for (int i=0;i<t;i++){
        scanf("%lld %lld %lld %lld %lld %lld",&x,&y,&a,&b,&c,&d);
        ll res = vecto(a-x,b-y,c-x,d-y);
        if (res>0) printf("LEFT\n");
        else if (res==0) printf("TOUCH\n");
        else printf("RIGHT\n");
    }
    return 0;
}
