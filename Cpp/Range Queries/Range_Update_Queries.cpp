#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vll = vector<ll>;

int n,q,k,t;
vll numbers,windows;

void update_window(int idx,ll u){
    windows[idx] += u;
}

void increase(int a, int b, ll u){
    int l = (a-1)/k; int r = (b-1)/k;
    for (int idx = l+1; idx < r; idx++) update_window(idx,u);
    if (l<r){
        for (int i=a;i<=(l+1)*k;i++) numbers[i] += u;
        for (int i=r*k+1;i<=b;i++) numbers[i] += u;
    }
    else {
        for (int i=a;i<=b;i++) numbers[i] += u;
    }
}

ll get_value(int idx){
    return numbers[idx] + windows[(idx-1)/k];
}

int main(){
    scanf("%d %d",&n,&q);
    numbers = vll(n+1,0);
    for (int i=1;i<=n;i++){
        scanf("%lld",&numbers[i]);
    }
    k = sqrt(n);
    windows = vll((n+k-1)/k,0);
    for (int i=0;i<q;i++){
        scanf("%d ",&t);
        if (t==1){
            int a,b; ll u;
            scanf("%d %d %lld",&a,&b,&u);
            increase(a,b,u);
        }
        else {
            int idx;
            scanf("%d",&idx);
            printf("%lld\n",get_value(idx));
        }
    }
    return 0;
}