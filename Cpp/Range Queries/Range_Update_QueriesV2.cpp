// Using Segment tree with difference array

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vll = vector<ll>;

int n, q;
vll tree;

void build() {
    for (int i = n + 1; i > 0; i--)
        tree[i] = tree[i << 1] + tree[i << 1 | 1];
}

void pointUpdate(int pos, ll delta) {
    for (tree[pos += n + 2] += delta; pos > 1; pos >>= 1)
        tree[pos >> 1] = tree[pos] + tree[pos ^ 1];
}

void update(int a, int b, ll u) {
    pointUpdate(a, u);
    pointUpdate(b + 1, -u);
}

ll getValue(int k) {
    ll res = 0;
    int l = 1, r = k;
    for (l += n + 2, r += n + 2; l <= r; l >>= 1, r >>= 1) {
        if (l & 1) res += tree[l++];
        if (!(r & 1)) res += tree[r--];
    }
    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> q;
    tree.assign(2 * (n + 2), 0);

    vll arr(n + 2, 0);
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
        ll diff = arr[i] - arr[i - 1];
        tree[i + n + 2] = diff;
    }
    build();

    while (q--) {
        int type;
        cin >> type;
        if (type == 1) {
            int a, b;
            ll u;
            cin >> a >> b >> u;
            update(a, b, u);
        } else {
            int k;
            cin >> k;
            cout << getValue(k) << "\n";
        }
    }

    return 0;
}
