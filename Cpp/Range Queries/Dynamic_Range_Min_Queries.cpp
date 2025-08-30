#include <bits/stdc++.h>
using namespace std;
using vi = vector<int>;


int n,q;
vi tree;
const int inf = 1e9+1;

void build(){
    for (int i=n-1;i>0;i--){
        tree[i] = min(tree[i<<1],tree[i<<1|1]);
    }
}

void modify(int k,int u){
    for (tree[k+=n-1] = u; k>1; k>>=1) tree[k>>1] = min(tree[k],tree[k^1]);
}

int getMin(int l, int r){
    int res = inf;
    for (l += n-1, r += n-1; l <= r; l >>= 1, r >>= 1){
        if (l&1) res = min(res,tree[l++]);
        if ((r & 1) == 0) res = min(res,tree[r--]);
    }
    return res;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> q;
    tree.assign(2*n,inf);
    for (int i=n;i<2*n;i++) cin >> tree[i];
    
    build();

    while (q--){
        int type;
        cin >> type;
        if (type == 1){
            int k,u;
            cin >> k >> u;
            modify(k,u);
        }
        else {
            int a,b;
            cin >> a >> b;
            cout << getMin(a,b) << '\n';
        }
    }
    return 0;
}
