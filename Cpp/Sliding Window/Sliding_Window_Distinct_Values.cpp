#include <bits/stdc++.h>
using namespace std;
using ll = long long;


struct CustomHash {
    static uint64_t splitmix64(uint64_t x) {
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }
    size_t operator()(ll x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};

using us = unordered_set<ll,CustomHash>;
using um = unordered_map<ll,int,CustomHash>;
using vll = vector<ll>;


vll numbers;
um frequency;
us present;

int n,k;



int main(){
    scanf("%d %d",&n,&k);
    numbers.resize(n);
    for (int i=0;i<n;i++){
        scanf("%lld",&numbers[i]);
    }


    for (int i=0;i<k;i++){
        frequency[numbers[i]]++;
        present.insert(numbers[i]);
    }

    for (int i=0;i<n-k+1;i++){
        printf("%zu ",present.size());
        frequency[numbers[i]]--;
        if (frequency[numbers[i]]==0) present.erase(numbers[i]);
        if (i+k<n){
            frequency[numbers[i+k]]++;
            present.insert(numbers[i+k]);
        }
    }
    return 0;
}