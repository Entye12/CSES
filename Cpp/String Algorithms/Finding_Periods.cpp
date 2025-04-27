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


    for (int k=0;k<n;k++){

        x = h1[k]; y = h2[k];

        bool period = true;

        for (int i=k+1; i<n; i+=(k+1)){
            if (i+k<n){
                u = (h1[i+k]-p1[k+1]*h1[i-1])%B; v = (h2[i+k]-p2[k+1]*h2[i-1])%D;
                u = (u+B)%B; v = (v+D)%D;
            }
            else {
                x = h1[n-i-1]; y = h2[n-i-1];
                u = (h1[n-1]-p1[n-i]*h1[i-1])%B; v = (h2[n-1]-p2[n-i]*h2[i-1])%D;
                u = (u+B)%B; v = (v+D)%D;
            }

            if (x != u || y != v){
                period = false; break;
            }
        }

        if (period) printf("%d ",k+1);
    }
    return 0;
}