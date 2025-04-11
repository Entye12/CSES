#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n;

ll f(int k1){
    ll k = k1;
    return (4*(k*k - 3) + 8*(k*k - 4) + 4*(k-3)*(k*k -5)+ 4*(k-4)*(k*k - 7) + (k-4)*(k-4) * (k*k - 9))/2;
}

int main(){
    scanf("%d",&n);
    for (int i=1;i<=n;i++){
        printf("%lld\n",f(i));
    }
}