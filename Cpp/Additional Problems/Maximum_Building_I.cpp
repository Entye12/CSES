#include <bits/stdc++.h>
using namespace std;
using vi = vector<int>;
#define all(x) (x).begin(), (x).end()

int n,m;

int maxRectangle(vi &freeUp){
    
    vi left(m+1,0);
    stack<pair<int,int>> s;
    s.push({-1,0});
    
    for (int j=1;j<=m;j++){
        while (!s.empty() && s.top().first >= freeUp[j]){
            s.pop();
        }
        left[j] = s.top().second;
        s.push({freeUp[j],j});
    }

    vi right(m+1,0);
    while (!s.empty()) s.pop();
    s.push({-1,m+1});
    for (int j=m;j>0;j--){
        while (!s.empty() && s.top().first >= freeUp[j]){
            s.pop();
        }
        right[j] = s.top().second;
        s.push({freeUp[j],j});
    }

    int res = 0;
    for (int j=1;j<=m;j++){
        res = max(res, freeUp[j] * (right[j]-left[j]-1));
    }
    return res;
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int ans = 0;
    
    cin >> n >> m;
    
    vi freeUp(m+2,0);
    for (int i=1;i<=n;i++){
        for (int j=1;j<=m;j++){
            char c;
            cin >> c;
            if (c == '.') {
                freeUp[j]++;
            }
            else freeUp[j] = 0;
        }
        ans = max(ans,maxRectangle(freeUp));
        
    }

    cout << ans << endl;

    return 0;
}
