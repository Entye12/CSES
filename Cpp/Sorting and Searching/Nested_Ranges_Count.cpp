#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;

using vi = vector<int>;
using tiii = tuple<int,int,int>;
using vtiii = vector<tiii>;
template<typename T>
using omsi = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;


int n,s,e,idx;


int main(){
    scanf("%d",&n);
    vi countContains(n+1,0); vi countContained(n+1,0);
    vtiii intervals(n+1); omsi<int> leftEnd, rightEnd;
    for (int i=1; i<=n;i++){
        scanf("%d %d",&s,&e);
        intervals[i] = {s,e,i};
    }

    sort(intervals.begin()+1,intervals.end(),[](const auto &a, const auto &b){
        if (get<0>(a) == get<0>(b)) return get<1>(a) > get<1>(b);
        return get<0>(a) < get<0>(b);
    });

    for (int i=1;i<=n;i++){
        auto [s, e, idx] = intervals[i];
        countContained[idx] = leftEnd.size() - leftEnd.order_of_key(e);
        leftEnd.insert(e);
    }

    for (int i=n;i>=1;i--){
        auto [s, e, idx] = intervals[i];
        countContains[idx] = rightEnd.order_of_key(e+1);
        rightEnd.insert(e);
    }

    for (int i=1;i<=n;i++){
        printf("%d ",countContains[i]);
    }
    printf("\n");
    for (int i=1;i<=n;i++){
        printf("%d ",countContained[i]);
    }
    printf("\n");
    return 0;
}