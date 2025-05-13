#include <bits/stdc++.h>
using namespace std;
using vi = vector<int>;

string s;

vi oddManacher(string &s){
    int n = s.size();
    s = '$' + s + '@';
    vi ans(n+2,0);
    int l=0; int r = 1;
    for (int i=1;i<=n;i++){
        ans[i] = max(0,min(ans[r+l-i],r-i));
        while (s[i+ans[i]] == s[i-ans[i]]){
            ans[i]++;
        }
        if (i+ans[i]>r){
            l = i-ans[i];r=i+ans[i];
        }
    }
    return vi(begin(ans)+1,end(ans)-1);
}

int main(){
    cin >> s;
    int n = s.size();
    string ss = string("#");
    for (char c:s){
        ss += c + string("#");
    }
    vi d = oddManacher(ss);
    int maxi = 0; int idx;

    for (int i=0;i<2*n+1;i++){
        if (d[i]-1 > maxi){
            maxi = d[i]-1;idx = i/2;
        }
    }
    cout << s.substr(idx-maxi/2,maxi) << endl;
    return 0;
}