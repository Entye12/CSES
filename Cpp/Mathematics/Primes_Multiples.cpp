#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll n; int k;

int main(){
    scanf("%lld %d",&n,&k);
    vector<ll> primes(k,0);
    for (int i=0; i<k; i++){
        scanf("%lld",&primes[i]);
    }
    ll ans = 0;

    for (ll mask=1; mask<(1<<k); mask++){
        ll tmp = n; int size = 0;
        for (int i=0; i<k; i++){
            if ((1<<i)&mask){
                tmp /= primes[i]; size++;
                if (tmp==0) break;
            }
        }
        if (size%2) ans += tmp;
        else ans -= tmp;
    }
    printf("%lld",ans);
    return 0;
}