#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n,k; ll a;ll S=0;ll maxi=0;
vector<ll> arr;

bool is_all_sum_less_than(ll target,vector<ll> &arr){
    int nb_windows = 0;ll sum = 0;
    for (int l=0;l<n;l++){
        if (arr[l]>target) return false;

        if (sum+arr[l]<=target) sum+=arr[l];
        else {
            nb_windows++;
            sum = arr[l];
        }
        
        if (nb_windows>=k) return false;
    }
    return true;
};

int main(){
    scanf("%d %d",&n,&k);
    for (int i=0;i<n;i++){
        scanf("%lld",&a);
        S += a; maxi = max(maxi,a);
        arr.push_back(a);
    }
    ll x = -1; ll upper = S/k +1+maxi;
    for (ll step=upper;step>=1;step/=2){
        while (!is_all_sum_less_than(x+step,arr)) x+=step;
    }
    x++;
    printf("%lld",x);
    return 0;
}