#include <bits/stdc++.h>
using namespace std;
using vi = vector<int>;


int n0,n,m,w;
vi segment_tree;

int padding(int n){
    int p = 0;
    while ((1<<p)<n) p++;
    return 1<<p;
}

int get_index(int w){
    int idx = 1;
    if (segment_tree[1]<w) return 0;
    while (2*idx +1 < 2*n){
        if (segment_tree[2*idx] >= w) idx *= 2;
        else idx = 2*idx+1;
    }
    return idx-n+1;
}   

void update(int idx, int u){
    idx += n-1;
    segment_tree[idx] -= u;
    idx /= 2;
    while (idx > 0){
        segment_tree[idx] = max(segment_tree[2*idx],segment_tree[2*idx+1]);
        idx /= 2;
    }
}

void preprocessing(){
    scanf("%d %d",&n0,&m);
    n = padding(n0);
    segment_tree = vi(2*n,0);
    for (int i=n;i<n+n0;i++) scanf("%d",&segment_tree[i]);
    for (int i=n-1;i>0;i--) segment_tree[i] = max(segment_tree[2*i],segment_tree[2*i+1]);
}


int main(){
    preprocessing();
    for (int i=0;i<m;i++){
        scanf("%d",&w);
        int idx = get_index(w);
        printf("%d ", idx);
        if (idx > 0) update(idx,w);
    }
    return 0;
}