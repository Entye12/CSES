#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n,a,b;ll x;ll sum = 0; ll maxi = LLONG_MIN;
vector<ll> prefix_sum {0};vector<ll> numbers {0};
priority_queue<pair<ll,ll>> max_heap;

void preprocessing(){
    scanf("%d %d %d",&n,&a,&b);
    for (int i=1;i<=n;i++){
        scanf("%lld",&x);
        sum += x;
        prefix_sum.push_back(sum); numbers.push_back(x);
    }
    for (int i=a;i<=b;i++){
        max_heap.emplace(prefix_sum[i],i);
    }
}

void clean(int threshold){
    while (!max_heap.empty() && max_heap.top().second < threshold){
        max_heap.pop();
    }
}

int main(){
    preprocessing();
    for (int i=1;i<=n-a+1;i++){
        clean(i+a-1);
        maxi = max(maxi,max_heap.top().first - prefix_sum[i-1]);
        if (i+b <= n) max_heap.emplace(prefix_sum[i+b],i+b);
    }
    printf("%lld",maxi);
}