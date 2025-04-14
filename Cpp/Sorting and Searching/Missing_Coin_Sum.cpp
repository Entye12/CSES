#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<int> coins;
int n, x; ll target = 1;

int main(){
    scanf("%d",&n);
    for (int i=1; i<=n; i++){
        scanf("%d",&x);
        coins.push_back(x);
    }
    sort(coins.begin(),coins.end());
    for(int c: coins){
        if (target < c){break;}
        target += c;
    }
    printf("%lld\n",target);
    return 0;
}