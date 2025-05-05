#include <bits/stdc++.h>
using namespace std;
using vi = vector<int>;

int n0,n,k;
vi segment_tree;


int padding(int n){
    int p = 0;
    while ((1<<p)<n) p++;
    return 1<<p;
}

void preprocessing(){
    scanf("%d %d",&n0,&k);
    n = padding(n0);
    segment_tree = vi(2*n,0);
    for (int i=n;i<n+n0;i++) segment_tree[i]++;
    for (int i=n-1;i>0;i--) segment_tree[i] = segment_tree[2*i]+segment_tree[2*i+1];
}

void delete_at(int idx){
    idx += n-1;
    while (idx >0){
        segment_tree[idx]--;
        idx /= 2;
    }
}

int get_sum(int l, int r) {
    l += n - 1;
    r += n - 1;
    int s = 0;
    while (l <= r) {
        if (l % 2 == 1) s += segment_tree[l++];
        if (r % 2 == 0) s += segment_tree[r--];
        l >>= 1;
        r >>= 1;
    }
    return s;
}


int get_next(int idx){
    int total = segment_tree[1];
    int sum_up_idx = get_sum(1,idx);
    int target = (sum_up_idx + k)%total + 1;

    int i = 1;

    while (i < n){
        if (segment_tree[2*i] >= target) i *= 2;
        else {
            target -= segment_tree[2*i];
            i = 2*i+1;
        }
    }
    return i-n+1;
}


int main(){
    preprocessing();
    int idx = 0;
    for (int i=1;i<=n0;i++){
        int j = get_next(idx);
        printf("%d ",j);
        delete_at(j);
        idx = j;
    }
    return 0;
}