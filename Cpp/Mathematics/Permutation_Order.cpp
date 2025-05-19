#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

using ll = long long;
template<typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag,
                         tree_order_statistics_node_update>;
using osi = ordered_set<int>;
using vll = vector<ll>;
using vi = vector<int>;


vll facto;

void computeFacto(){
    facto.resize(21);
    facto[0] = 1;
    for (int i = 1; i <= 20; i++) facto[i] = facto[i - 1] * i;
}

void p(int n,ll k){
    osi numbers;k--;
    for (int i=1;i<=n;i++) numbers.insert(i);

    while (!numbers.empty()){
        int d = numbers.size();
        ll order = k/facto[d-1];
        k%=facto[d-1];
        int x = *numbers.find_by_order(order);
        printf("%d ",x);
        numbers.erase(x);
    }
    printf("\n");
}

void invP(int n,const vi& permutation){
    ll k = 0;
    osi numbers;
    for (int i=1;i<=n;i++) numbers.insert(i);
    
    for (int i=0;i<n;i++){
        int x = permutation[i];
        ll order = numbers.order_of_key(x);
        k += order*facto[n-1-i];
        numbers.erase(x);
    }
    k++;
    printf("%lld\n",k);
}


int main(){
    computeFacto();
    int t;
    scanf("%d",&t);
    for (int i=0;i<t;i++){
        int q;
        scanf("%d",&q);
        if (q==1){
            int n; ll k;
            scanf("%d %lld",&n,&k);
            p(n,k);
        }
        else {
            int n;
            scanf("%d",&n);
            vi permutation(n);
            for (int i=0;i<n;i++){
                scanf("%d",&permutation[i]);
            }
            invP(n,permutation);
        }
    }
    return 0;
}
