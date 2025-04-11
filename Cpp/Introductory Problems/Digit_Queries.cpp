#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int q;
ll k;
ll window; ll first_pos;

ll size(int n){
    return 9*n*pow(10,n-1);
}

pair<ll,ll> wich_window(ll k){
    ll cur = 0; ll window = 0;
    while (cur <= k){
        window++;
        cur += size(window);
    }
    return make_pair(window,cur-size(window));
}

int main(){
    scanf("%d",&q);
    for (int i=1;i<=q;i++){
        cin >> k;k--;
        pair<ll, ll> window_info = wich_window(k);
        window = window_info.first; first_pos = window_info.second;
        
        ll first_number = pow(10,window-1);
        k -= first_pos;
        ll quotient = k/window ; ll remainder = k%window;

        string number_containing_k = to_string(first_number + quotient);
        char digit = number_containing_k[remainder];
        printf("%c\n",digit);  
    }
    return 0;
}