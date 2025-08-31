#include <bits/stdc++.h>
using namespace std;
using vi = vector<int>;
using umi = unordered_map<int,int>;
#define all(x) (x).begin(),(x).end()

const int MOD = 1e9+7;
int n, N;
vi tree;
umi xToIdx;

int padding(int n) {
    int p = 1;
    while (p < n) p <<= 1;
    return p;
}

void update(int idx, int val) {
    idx += N - 1;
    tree[idx] = (tree[idx] + val) % MOD;
    for (idx >>= 1; idx >= 1; idx >>= 1) {
        tree[idx] = (tree[idx<<1] + tree[idx<<1|1]) % MOD;
    }
}

int getSum(int l, int r) {
    int res = 0;
    for (l += N-1, r += N-1; l <= r; l >>= 1, r >>= 1) {
        if (l & 1) res = (res + tree[l++]) % MOD;
        if (!(r & 1)) res = (res + tree[r--]) % MOD;
    }
    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    vi a(n), sa(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        sa[i] = a[i];
    }
    sort(all(sa));
    sa.erase(unique(all(sa)), sa.end());

    int n1 = sa.size();
    N = padding(n1);
    tree.assign(2 * N, 0);

    for (int i = 0; i < n1; i++) xToIdx[sa[i]] = i+1;

    long long ans = 0;
    for (int i = 0; i < n; i++) {
        int idx = xToIdx[a[i]];
        int ways = (1 + getSum(1, idx-1)) % MOD;
        update(idx, ways);
        ans = (ans + ways) % MOD;
    }

    cout << ans << "\n";
    return 0;
}
