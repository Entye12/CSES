#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n;
ll t, a;
ll ans = -1;
vector<ll> numbers;

ll number_of_product_at_time(ll x, vector<ll> &numbers) {
    ll cur = 0;
    for (auto e : numbers) {
        cur += x / e;
    }
    return cur;
}

int main() {
    scanf("%d %lld", &n, &t);
    for (int i = 1; i <= n; i++) {
        scanf("%lld", &a);
        numbers.push_back(a);
    }
    ll min_a = *min_element(numbers.begin(), numbers.end());
    ll heuristic = t * min_a;

    for (ll z = heuristic; z >= 1; z /= 2) {
        while (number_of_product_at_time(ans + z, numbers) < t)
            ans += z;
    }

    ans++;
    printf("%lld\n", ans);
    return 0;
}
