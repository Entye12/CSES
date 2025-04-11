#include <bits/stdc++.h>
using namespace std;

int n;
int a,b;
vector<pair<int,string>> elements;
int cur = 0; int ans = 0;

int main(){
    scanf("%d",&n);
    for (int i=1;i<=n;i++){
        scanf("%d %d",&a,&b);
        elements.push_back({a,"in"});
        elements.push_back({b,"out"});
    }
    sort(elements.begin(),elements.end());

    for (auto e : elements){
        if (e.second == "in"){
            cur++;
            ans = max(ans,cur);
        }
        else cur--;
    }
    printf("%d\n",ans);
    return 0;
}
