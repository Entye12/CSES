#include <bits/stdc++.h>
using namespace std;

int n,s,e;

int main(){
    scanf("%d",&n);
    vector<int> contains(n,0); vector<int> is_contained(n,0);
    vector<tuple<int,int,int>> intervals;
    for (int i=0; i<n;i++){
        scanf("%d %d",&s,&e);
        intervals.emplace_back(s,e,i);
    }
    sort(intervals.begin(),intervals.end(),[](const auto &a, const auto &b){
        if (get<0>(a)==get<0>(b)) return get<1>(a) > get<1>(b);
        return get<0>(a) < get<0>(b);
    });

    int min_end_toright = INT_MAX;
    for (int i=n-1;i>=0;i--){
        auto [s,e,idx] = intervals[i];
        if (e>=min_end_toright) contains[idx] = 1;
        min_end_toright = min(e,min_end_toright);
    }
    int max_end_toleft = 0;
    for (int i=0;i<n;i++){
        auto [s,e,idx] = intervals[i];
        if (e<=max_end_toleft) is_contained[idx] = 1;
        max_end_toleft = max(max_end_toleft,e);
    }


    for (int i = 0; i < n; i++) {
        printf("%d ", contains[i]);
    }
    printf("\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", is_contained[i]);
    }
    printf("\n");
    return 0;
}