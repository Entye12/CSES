#include <bits/stdc++.h>
using namespace std;

int n,x,a;
vector<int> weights;
int l,r;
int ans = 0;

int main(){
    scanf("%d %d",&n,&x);
    for (int i=1;i<=n;i++){
        scanf("%d",&a);
        weights.push_back(a);
    }
    sort(weights.begin(),weights.end());
    l = 0; r = n-1;

    while (l <= r){
        ans++;
        if (weights[l]+weights[r] <= x){
            l++;
        }
        r--;
    }
    printf("%d\n",ans);
    return 0;
}