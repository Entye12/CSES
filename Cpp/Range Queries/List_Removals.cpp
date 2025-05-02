#include <bits/stdc++.h>
using namespace std;
using vi = vector<int>;

int n0,n,k;
vi segment_tree,numbers;


int padding(int n){
    int p = 0;
    while ((1<<p)<n) p++;
    return 1<<p;
}

void preprocessing(){
    scanf("%d",&n0);
    n = padding(n0);
    segment_tree = vi(2*n,0);
    for (int i=n;i<n+n0;i++) segment_tree[i]++;
    for (int i=n-1;i>0;i--) segment_tree[i] = segment_tree[2*i]+segment_tree[2*i+1];
    numbers = vi(n0+1,0);
    for (int i=1;i<=n0;i++){
        scanf("%d",&numbers[i]);
    }
}

void delete_at(int idx){
    idx += n-1;
    while (idx >0){
        segment_tree[idx]--;
        idx /= 2;
    }
}

int get_true_index(int k){
    int idx = 1;
    while (idx < n){
        if (segment_tree[2*idx] >= k) idx *= 2;
        else {
            k -= segment_tree[2*idx];
            idx = 2*idx+1;
        }
    }
    return idx-n+1;
}



int main(){
    preprocessing();
    for (int i=1;i<=n0;i++){
        scanf("%d",&k);
        int idx = get_true_index(k);
        delete_at(idx);
        printf("%d ",numbers[idx]);
    }
    return 0;
}
