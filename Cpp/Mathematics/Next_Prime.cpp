#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using u128 = __uint128_t;


int t;
ll n,p;
const int s = 20;


ll pow_mod(ll a, ll b, ll mod) {
    ll x = 1;
    a %= mod;
    while (b > 0) {
        if (b % 2) x = (u128)x * a % mod;
        a = (u128)a * a % mod;
        b /= 2;
    }
    return x;
}

// witness that n is a composite number
bool witness(ll a, ll n){
    int t = __builtin_ctzll(n - 1);
    ll u = (n - 1) >> t;
    ll x = pow_mod(a,u,n);

    for (int i=1;i<=t;i++){
        ll y = pow_mod(x,2,n);
        if (x!=1 && y==1 && x!=(n-1)) return true;
        x = y;
    }
    return (x!=1);
}

ll get_random(ll n) {
    static mt19937 rng(random_device{}());
    uniform_int_distribution<ll> dist(2, n - 2);
    return dist(rng);
}

bool isPrime(ll p) {
    if (p == 2 || p == 3) return true;
    if (p < 2 || p % 2 == 0) return false;

    for (int i = 0; i < s; i++) {
        ll a = get_random(p);
        if (witness(a, p)) return false;
    }
    return true;
}

ll nextPrime(ll n) {
    if (n < 2) return 2;
    ll p = (n % 2 == 0) ? n + 1 : n + 2;
    while (true) {
        if (isPrime(p)) return p;
        p += 2;
    }
}


int main(){
    scanf("%d",&t);
    for (int i=0;i<t;i++){
        scanf("%lld",&n);
        p = nextPrime(n);
        printf("%lld\n",p);
    }
    return 0;
}