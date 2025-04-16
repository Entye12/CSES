#include <bits/stdc++.h>
using namespace std;

int n,k,s,e;int ans =0;
multiset<int> closing; vector<pair<int,int>> arr;

int main(){
    scanf("%d %d",&n,&k);
    for (int i=1;i<=n;i++){
        scanf("%d %d",&s,&e);
        arr.emplace_back(e,s);
    }
    sort(arr.begin(), arr.end());
    for (int i=0;i<k;i++){
        closing.insert(0);
    }
    for (int i=0;i<n;i++){
        s = arr[i].second; e = arr[i].first;
        auto it = closing.upper_bound(s);
        if (it != closing.begin()){
            it--;
            closing.erase(it); closing.insert(e);
            ans++;
        }
    }
    printf("%d",ans);
    return 0;
}