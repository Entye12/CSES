#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vll = vector<ll>;
using pli = pair<ll,int>;
using vpli = vector<pli>;
using maxH = priority_queue<pli>;
using minH = priority_queue<pli,vpli,greater<pli>>;
using si = set<int>;

int n,k,sizeMin,sizeMax,idx;
maxH maxHeap; minH minHeap;
vll arr;
si inMaxHeap;
ll x,in,cost,median,sumMax,sumMin;


void cleanMaxHeap(int threshold){
    while (!maxHeap.empty() && maxHeap.top().second <= threshold) maxHeap.pop();
}

void cleanMinHeap(int threshold){
    while (!minHeap.empty() && minHeap.top().second <= threshold) minHeap.pop();
}

void preprocessing(){
    scanf("%d %d",&n,&k);
    sizeMax = (k+1)/2;sizeMin = k-sizeMax; 
    arr.resize(n+1);
    for (int i=1;i<=n;i++){
        scanf("%lld",&arr[i]);
    }

    for (int i=1;i<=k;i++){
        maxHeap.emplace(arr[i],i); inMaxHeap.insert(i);
        sumMax += arr[i];
        if (maxHeap.size()>sizeMax){
            auto [x, idx] = maxHeap.top();
            maxHeap.pop();
            sumMax -= x; sumMin += x;
            inMaxHeap.erase(idx);
            minHeap.emplace(x,idx);
        }
    }
}



int main(){
    preprocessing();

    for (int i=1;i<=n-k+1;i++){
        median = maxHeap.top().first;
        printf("%lld ", sizeMax*median - sumMax + sumMin - sizeMin*median);
        cleanMaxHeap(i); cleanMinHeap(i);
        if (i+k==n+1) continue;
        // remove the i-th element
        if (inMaxHeap.count(i)){
            inMaxHeap.erase(i);
            sumMax -= arr[i];
        }
        else sumMin -= arr[i];

        in = arr[i+k];
        if (inMaxHeap.size() < sizeMax){
            if (minHeap.empty() || minHeap.top().first > in){
                maxHeap.emplace(in,i+k);
                inMaxHeap.insert(i+k);
                sumMax += in;
            }
            else {
                auto [x, idx] = minHeap.top();
                minHeap.pop(); sumMin -= x;
                maxHeap.emplace(x,idx); inMaxHeap.insert(idx); sumMax += x;
                minHeap.emplace(in,i+k); sumMin += in;
            }
        }
        else {
            if (in > maxHeap.top().first){
                minHeap.emplace(in,i+k);
                sumMin += in;
            } 
            else {
                auto [x, idx] = maxHeap.top(); maxHeap.pop(); inMaxHeap.erase(idx); sumMax -= x;
                minHeap.emplace(x,idx); sumMin += x;
                maxHeap.emplace(in,i+k); inMaxHeap.insert(i+k); sumMax += in;
            }
        }

    }
    return 0;
}