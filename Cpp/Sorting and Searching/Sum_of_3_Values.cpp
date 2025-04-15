#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n; ll x; ll y;
vector<ll> numbers;
map<ll,vector<int>> number_to_index;
int a,b,c;

int main(){
    scanf("%d %lld",&n,&x);
    for (int i=1;i<=n;i++){
        scanf("%lld",&y);
        numbers.push_back(y);
    }
    for (int i=1;i<=n;i++){
        number_to_index[numbers[i-1]].push_back(i);
    }
    sort(numbers.begin(),numbers.end());
    bool found = false;

    for (int l=0;l<n-2;l++){
        int m = l+1; int r = n-1;

        while (m < r){
            ll sum = numbers[l]+numbers[m]+numbers[r];
            if (sum == x){
                found = true; 
                a = number_to_index[numbers[l]].back(); number_to_index[numbers[l]].pop_back();
                b = number_to_index[numbers[m]].back(); number_to_index[numbers[m]].pop_back();
                c = number_to_index[numbers[r]].back(); number_to_index[numbers[r]].pop_back();
                break;
            }
            else if (sum < x) m++;
            else r--;
        }
        if (found) break;
    }
    if (found) printf("%d %d %d \n",a,b,c);
    else printf("IMPOSSIBLE\n");
    return 0;
}