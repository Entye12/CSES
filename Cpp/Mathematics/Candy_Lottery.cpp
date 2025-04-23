#include <bits/stdc++.h>
using namespace std;
 
int n,k;
 
int main(){
    scanf("%d %d",&n,&k);
    double ans = 0;
 
    for (int i=1;i<=k;i++){
        ans += 1.0 - pow((i - 1.0) / k, n);
    }
    cout<<fixed<<setprecision(6)<<ans<<'\n';

    return 0;
}