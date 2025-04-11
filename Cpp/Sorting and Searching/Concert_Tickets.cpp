#include <bits/stdc++.h>
using namespace std;

int n,m,x;
multiset<int> prices;

int main(){
    scanf("%d %d",&n,&m);
    for (int i=1;i<=n;i++){
        scanf("%d",&x);
        prices.insert(x);
    }
    for (int i=1;i<=m;i++){
        scanf("%d",&x);
        auto it = prices.upper_bound(x);
        if (it == prices.begin()) printf("%d\n",-1);
        else {
            it--;
            printf("%d\n",*it);
            prices.erase(it);
        }
    }
    return 0;
}