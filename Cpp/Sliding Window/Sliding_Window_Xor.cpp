#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int n,k;
ll x,a,b,c;

int count(int i){
    return min(i,n-k+1)-max(1,i+1-k)+1;
}

int main(){
    scanf("%d %d",&n,&k);
    scanf("%lld %lld %lld %lld",&x,&a,&b,&c);
    ll xorS = 0;
    for (int i=1;i<=n;i++){
        if (count(i)%2) xorS ^= x;
        x = (a*x+b)%c;
    }
    printf("%lld\n",xorS);
    return 0;
}