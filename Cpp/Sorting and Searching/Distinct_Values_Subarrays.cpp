#include <bits/stdc++.h>
using namespace std;
using ll = long long;

struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }
    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};

using vi = vector<int>;
using umci = unordered_map<int,int,custom_hash>;

int n;
umci freq;

int main(){
    ll ans = 0;
    scanf("%d",&n);
    vi arr(n+1);
    for (int i=1;i<=n;i++) scanf("%d",&arr[i]);

    int l=1;

    for (int r = 1; r <= n; r++) {
        freq[arr[r]]++;
        
        while (freq[arr[r]] > 1) {
            freq[arr[l]]--;
            l++;
        }
        
        ans += (ll)(r - l + 1);
    }
    printf("%lld",ans);
    return 0;
}