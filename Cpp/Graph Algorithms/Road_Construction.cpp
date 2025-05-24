#include <bits/stdc++.h>
using namespace std;
using vi = vector<int>;


int n,m,a,b;
int mSize, nComp;
vi sizeComp,rep;

int find(int x){
    while (x!=rep[x]) x = rep[x];
    return x;
}

bool same(int a,int b){
    return (find(a)==find(b));
}

void unite(int a, int b){
    a = find(a); b = find(b);
    if (sizeComp[a] < sizeComp[b]) swap(a,b);
    sizeComp[a] += sizeComp[b];
    rep[b] = a;
    nComp--;
    mSize = max(mSize,sizeComp[a]);
}

int main(){
    scanf("%d %d",&n,&m);
    mSize = 1; nComp = n;
    rep.resize(n+1); sizeComp.assign(n+1,1);
    for (int i=1;i<=n;i++) rep[i] = i;

    for (int i=1;i<=m;i++){
        scanf("%d %d",&a,&b);
        if (same(a,b)) printf("%d %d\n",nComp,mSize);
        else {
            unite(a,b);
            printf("%d %d\n",nComp,mSize);
        }
    }
    return 0;
}