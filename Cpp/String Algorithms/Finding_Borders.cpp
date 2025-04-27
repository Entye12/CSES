#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vll = vector<ll>;



const ll A = 911382323; const ll B = 972663749;
const ll C = 37; const ll D = 1e9+7;
string w;
vll h1,p1,h2,p2;
ll x,y,v,u;

pair<vll,vll> hash0(string word, ll a, ll b){
    int n = word.size();
    vll h(n,0); vll p(n,1);
    h[0] = word[0] - 'a'; 
    for (int k=1;k<n;k++){
        h[k] = (a*h[k-1] + (word[k] - 'a'))%b;
        p[k] = (a*p[k-1])%b;
    }
    return {h,p};
}

int main(){
    cin >> w;
    int n = w.size();

    tie(h1,p1) = hash0(w,A,B); tie(h2,p2) = hash0(w,C,D);

    for (int i=0;i<n-1;i++){
        x = h1[i]; y = h2[i];
        v = (h1[n-1]-h1[n-1-i-1]*p1[i+1])%B; u = (h2[n-1]-h2[n-1-i-1]*p2[i+1])%D;
        v = (v+B)%B; u = (u+D)%D;
        if (x == v && y == u) printf("%d ",i+1);
    }
    return 0;
}