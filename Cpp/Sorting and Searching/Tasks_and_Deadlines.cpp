#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n,a,d;
ll ans=0;ll t=0;
vector<pair<int,int>> duration_deadline;

int main(){
    scanf("%d",&n);
    for (int i=1;i<=n;i++){
        scanf("%d %d",&a,&d);
        duration_deadline.push_back(make_pair(a,d));
    }
    sort(duration_deadline.begin(), duration_deadline.end(), 
        [](const pair<int, int>& x, const pair<int, int>& y) {
            return x.first < y.first;
        }
    );
    for (auto e:duration_deadline){
        a = e.first; d = e.second;
        t += a;
        ans += (d-t);
    }
    printf("%lld",ans);
    return 0;
}