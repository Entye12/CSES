#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
using ll = long long;
using vll = vector<ll>;
using plli = pair<ll,int>;
template<typename T>
using os = tree<T,null_type,less<T>,rb_tree_tag,tree_order_statistics_node_update>;
int n,k;

int main(){
    scanf("%d %d",&n,&k);
    vll numbers(n+1);
    for (int i=1;i<=n;i++) scanf("%lld",&numbers[i]);
    ll x = 0;
    os<plli> window;
    for (int i=1;i<=k;i++){
        window.insert({numbers[i],i});
        x += (i-window.order_of_key({numbers[i]+1,-1}));
    }

    for (int i=1;i<=n-k+1;i++){
        printf("%lld ",x);
        x -= window.order_of_key({numbers[i],-1});
        window.erase({numbers[i],i});
        if (i+k<=n){
            window.insert({numbers[i+k],i+k});
            x += (k-window.order_of_key({numbers[i+k]+1,-1}));
        }
    }
    return 0;
}