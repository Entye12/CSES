#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n; ll x; ll a;
ll ans;
vector<ll> numbers;

int main(){
    scanf("%d %lld",&n,&x);
    for (int i=1; i<=n;i++){
        scanf("%lld",&a);
        numbers.push_back(a);
    }
    int l=0; int r=0; ll sum = numbers[0];
    while (l<n && r<n){
        if (sum == x){
            ans++; sum -= numbers[l]; l++; r++;
            if (r<n) sum += numbers[r];
        }
        else if (sum < x){
            r++;
            if (r<n) sum += numbers[r];
        }
        else {
            sum -= numbers[l];
            l++;
        }
    }
    printf("%lld\n",ans);
    return 0;
}