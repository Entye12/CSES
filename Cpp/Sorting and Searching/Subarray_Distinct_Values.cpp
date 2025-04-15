#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n,k,x; ll ans = 0;
map<int,int> seen; vector<int> numbers;

int main(){
    scanf("%d %d",&n,&k);
    for (int i=1; i<=n;i++){
        scanf("%d",&x);
        numbers.push_back(x);
    }
    int r = 0; int unique = 0;
    for (int l=0;l<n;l++){
        while (r<n && (unique<k || (unique == k && seen[numbers[r]]>0))){
            if (seen[numbers[r]] == 0) unique++;
            seen[numbers[r]]++;
            r++;
        }
        ans += (r-l);
        seen[numbers[l]]--;
        if (!seen[numbers[l]]) unique--;
    }
    printf("%lld",ans);
    return 0;
}