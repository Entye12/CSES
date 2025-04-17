#include <bits/stdc++.h>
using namespace std;

int n,y;int s = 0;int nb = 0;

int main(){
    cin >> n;
    vector<int> coins(n,0);
    unordered_map<int,int> counter;
    for (int i=0;i<n;i++){
        cin >> y;
        coins[i] = y; counter[y]++; s+=y;
    }
    vector<pair<int,int>> res(s+1,{0,0});
    res[0] = {-1,-1};

    for (auto [c, occur] : counter){
        for (int i=c;i<=s;i++){
            if (res[i] == make_pair(0,0) && res[i-c] != make_pair(0,0)){
                if (res[i-c].first != c) {
                    res[i] = make_pair(c,1);
                    nb++;
                }
                else if (res[i-c].second < occur){
                    res[i] = make_pair(c,res[i-c].second+1);
                    nb++;
                }
            }
        }
    }
    printf("%d\n",nb);
    for (int x=1;x<=s;x++){
        if (res[x] != make_pair(0,0)) cout << x << " ";
    }
}