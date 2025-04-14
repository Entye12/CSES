#include <bits/stdc++.h>
using namespace std;

int ans = 0;
int a,b,n;
vector<pair<int,int>> intervals;


int main(){
    scanf("%d",&n);
    for (int i=1;i<=n;i++){
        scanf("%d %d",&a,&b);
        intervals.push_back(make_pair(a,b));
    }
    sort(intervals.begin(),intervals.end(),[](const pair<int,int> &a, const pair<int,int> &b){return a.second<b.second;});
    int i = 0; int temp = 0;
    while (i<n){
        if (temp <= intervals[i].first){
            ans++;
            temp = intervals[i].second;
        }
        i++;
    }
    printf("%d\n",ans);
    return 0;
}