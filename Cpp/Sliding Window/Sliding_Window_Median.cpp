#include <bits/stdc++.h>
using namespace std;

int n,k,a; vector<int> arr; int x,idx;
priority_queue<pair<int,int>> max_heap; 
priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> min_heap;
set<int> in_max_heap;

void clean_min_heap(int threshold){
    while (!min_heap.empty() && min_heap.top().second <= threshold){
        min_heap.pop();
    }
};

void clean_max_heap(int threshold){
    while (!max_heap.empty() && max_heap.top().second <= threshold){
        max_heap.pop();
    }
};

void preprocessing(){
    scanf("%d %d",&n,&k);
    for (int i=1;i<=n;i++){
        scanf("%d",&a);
        arr.push_back(a);
    }
    for (int i=0;i<k;i++){
        max_heap.emplace(arr[i],i); in_max_heap.insert(i);
        if (max_heap.size()>k-k/2){
            x = max_heap.top().first; idx = max_heap.top().second;
            max_heap.pop(); in_max_heap.erase(idx);
            min_heap.emplace(x,idx);
        }
    }
}

int main(){
    preprocessing();
    printf("%d ",max_heap.top().first);
    
    for (int i=k;i<n;i++){
        if (in_max_heap.count(i-k)) in_max_heap.erase(i-k);

        if (in_max_heap.size() < k-k/2){
            if (min_heap.empty() || arr[i] < min_heap.top().first){
                max_heap.emplace(arr[i],i); in_max_heap.insert(i);
            }
            else {
                x = min_heap.top().first; idx = min_heap.top().second;
                min_heap.pop();
                max_heap.emplace(x,idx); in_max_heap.insert(idx);
                min_heap.emplace(arr[i],i);
            }
        }
        else {
            if (arr[i] > max_heap.top().first) min_heap.emplace(arr[i],i);
            else {
                x = max_heap.top().first; idx = max_heap.top().second;
                max_heap.pop();in_max_heap.erase(idx);
                max_heap.emplace(arr[i],i); in_max_heap.insert(i);
                min_heap.emplace(x,idx);
            }
        }
        clean_max_heap(i-k); clean_min_heap(i-k);
        printf("%d ",max_heap.top().first);
    }
    return 0;
}
