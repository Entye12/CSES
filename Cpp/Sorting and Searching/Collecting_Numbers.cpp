#include <bits/stdc++.h>
using namespace std;

int n;
unordered_map<int,int> idx;
int ans = 0; int cur = 0;

int main(){
    scanf("%d",&n);
    for (int i=1; i<=n; i++){
        int x;
        scanf("%d",&x);
        idx[x] = i;
    }
    while (cur < n){
        cur++;
        ans++;
        while (cur<n && idx[cur]<idx[cur+1]){
            cur++;
        }
    }
    printf("%d",ans);
    return 0;
}