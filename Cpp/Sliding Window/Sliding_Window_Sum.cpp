#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    int n, k;
    ll x, a, b, c;
    scanf("%d %d", &n, &k);
    scanf("%lld %lld %lld %lld", &x, &a, &b, &c);

    ll prefixSum[n+1];
    prefixSum[0] = 0;
    ll current = x;
    for (int i = 1; i <= n; i++) {
        prefixSum[i] = prefixSum[i - 1] + current;
        current = (a * current + b) % c;
    }

    ll xorSum = 0;
    for (int i = 1; i <= n - k + 1; i++) {
        ll windowSum = prefixSum[i + k - 1] - prefixSum[i - 1];
        xorSum ^= windowSum;
    }

    printf("%lld\n", xorSum);
    return 0;
}