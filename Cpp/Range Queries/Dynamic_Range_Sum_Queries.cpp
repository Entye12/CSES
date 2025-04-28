#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vll = vector<ll>;

int n,q;

ll sum_q(int k, vll &tree){
    ll s = 0;
    while (k>=1){
        s += tree[k];
        k -= (k&-k);
    }
    return s;
}

void add(int k, ll x,vll &tree){
    while (k<=n){
        tree[k] += x;
        k += (k&-k);
    }
}


int main(){
    scanf("%d %d",&n,&q);
    vll binary_indexed_tree(n+1,0);
    vll numbers(n+1,0);

    ll x;
    for (int i=1;i<=n;i++){
        scanf("%lld",&x);
        add(i,x,binary_indexed_tree);
        numbers[i]=x;
    }

    for (int i=0;i<q;i++){
        int t;
        scanf("%d ",&t);
        if (t==1){
            int k; ll u;
            scanf("%d %lld",&k,&u);
            add(k,u-numbers[k],binary_indexed_tree);
            numbers[k]=u;
        }
        else {
            int a,b;
            scanf("%d %d",&a,&b);
            printf("%lld\n",sum_q(b,binary_indexed_tree)-sum_q(a-1,binary_indexed_tree));
        }
    }
    return 0;
}