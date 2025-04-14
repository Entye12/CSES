#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll cost = 0; int x; int n;
vector<int> numbers;

int main(){
    scanf("%d",&n);
    for (int i = 1; i<=n; i++){
        scanf("%d",&x);
        numbers.push_back(x);
    }
    sort(numbers.begin(),numbers.end());
    int median = numbers[n/2];
    for (int e: numbers){
        cost += abs(e-median);
    }
    printf("%lld\n",cost);
    return 0;
}