#include <bits/stdc++.h>
using namespace std;
using vi = vector<int>;

int n,N;
vi tree;

int padding(int n){
    int p = 1;
    while (p < n) p <<= 1;
    return p;
}

void build() {
    for (int i = N - 1; i > 0; i--)
        tree[i] = tree[i << 1] + tree[i << 1 | 1];
}

void deleteAt(int idx) {
    idx += N - 1;
    while (idx > 0) {
        tree[idx]--;
        idx >>= 1;
    }
}

int getTrueIdx(int k){
    int idx = 1;
    while (idx < N){
        if (tree[idx << 1] >= k) idx <<= 1;
        else {
            k -= tree[idx << 1];
            idx = (idx << 1) | 1;
        }
    }
    return idx-N+1;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    N = padding(n);
    
    tree.assign(2 * N, 0);
    vi a(n+1,0);
    for (int i=1;i<=n;i++){
        cin >> a[i];
        tree[i+N-1] = 1;
    }
    
    build();

    for (int i=1;i<=n;i++){
        int k;
        cin >> k;
        int idx = getTrueIdx(k);
        deleteAt(idx);
        cout << a[idx] << " ";
    }

    return 0;
}
