#include <bits/stdc++.h>
using namespace std;

int n,x;
set<int> visited; vector<int> numbers;
int ans=0;
int lft = 0; int rit = 0;

int main(){
    scanf("%d",&n);
    for (int i=1;i<=n;i++){
        scanf("%d",&x);
        numbers.push_back(x);
    }
    while (rit < n){
        if (!visited.count(numbers[rit])){
            visited.insert(numbers[rit]);
        }
        else {
            ans = max(ans,rit-lft);
            while (visited.count(numbers[rit])){
                visited.erase(numbers[lft]);
                lft++;
            }
            visited.insert(numbers[rit]);
        }
        rit++;
    }
    ans = max(ans,rit-lft);
    printf("%d\n",ans);
    return 0;
}