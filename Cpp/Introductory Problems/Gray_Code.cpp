#include <bits/stdc++.h>
using namespace std;

int n;
vector<string> ans;

int main(){
    scanf("%d", &n);
    ans.push_back(string(n, '0'));
    int p = 1;

    while (p <= n) {
        vector<string> res;
        for (int i = 1; i <= 1 << (p - 1); i++) {
            string x = ans[ans.size() - i];
            x[n - p] = '1';
            res.push_back(x);
        }
        ans.insert(ans.end(), res.begin(), res.end());
        p++;
    }

    for (const string &c : ans) {
        cout << c << "\n";
    }
    return 0;
}