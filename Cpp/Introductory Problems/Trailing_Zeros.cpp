#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll n;

int main(){
    scanf("%lld",&n);
    int ans = 0;
    int p = 5;
    while (n>=p){
        ans += n/p;
        p *= 5;
    }
    printf("%d\n", ans);
    return 0;
}