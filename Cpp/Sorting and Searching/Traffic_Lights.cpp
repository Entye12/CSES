#include <bits/stdc++.h>
using namespace std;

int x,n,p;
set<int> pos; multiset<int> dist;


int main(){
    scanf("%d %d",&x,&n);
    pos.insert(-1); pos.insert(x+1); dist.insert(x);
    for (int i=1;i<=n;i++){
        scanf("%d",&p);
        auto [it,inserted] = pos.insert(p);
        int l = *prev(it); int r = *next(it);
        if (r!=x+1 && l!=-1){
            dist.erase(dist.find(r - l));
            dist.insert(p-l); dist.insert(r-p);
        }
        else if (r==x+1 && l!=-1){
            dist.erase(dist.find(r - l - 1));
            dist.insert(p-l); dist.insert(r-p-1);
        }
        else if (r!=x+1 && l==-1){
            dist.erase(dist.find(r - l - 1));
            dist.insert(p-l-1); dist.insert(r-p);
        }
        else {
            dist.erase(dist.find(r - l - 2));
            dist.insert(p-l-1); dist.insert(r-p-1);
        }
        printf("%d\n",*prev(dist.end()));
    }
    return 0;
}