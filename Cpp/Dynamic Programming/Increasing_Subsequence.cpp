#include <bits/stdc++.h>
using namespace std;

int n,x;

int main(){
    cin >> n;
    vector<int> numbers(n,0);
    vector<int> ans;
    for (int i=0;i<n;i++){
        cin >> x;
        auto it = lower_bound(ans.begin(),ans.end(),x);
        if (it==ans.end()) ans.push_back(x);
        else *it=x;
    }
    cout << ans.size() << endl;
    return 0;
}