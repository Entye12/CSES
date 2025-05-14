#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using plli = pair<ll,int>;
using pq = priority_queue<plli, vector<plli>, greater<plli>>;

int n,k;
ll x,a,b,c,y;
pq minHeap;

void clean(int j){
    while (!minHeap.empty() && minHeap.top().second < j) minHeap.pop();
}

int main(){
    ll xorMinSum = 0;
    scanf("%d %d",&n,&k);
    scanf("%lld %lld %lld %lld",&x,&a,&b,&c);
    y = x;
    for (int i=1;i<=k;i++){
        minHeap.push(make_pair(y,i));
        y = (a*y+b)%c;
    }   

    for (int i=1;i<=n-k+1;i++){
        clean(i);
        xorMinSum ^= minHeap.top().first;
        if (i+k <= n){
            minHeap.push(make_pair(y,i+k));
            y = (a*y+b)%c;
        } 
    }

    printf("%lld\n",xorMinSum);
    return 0;
}