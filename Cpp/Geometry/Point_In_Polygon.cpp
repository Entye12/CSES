#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vtll = vector<tuple<ll,ll>>;

int n,m;
ll x,y,a,b,c,d;
vtll polygon;

bool point_in_segment(ll x, ll y, ll a, ll b, ll c, ll d){
    if (min(a,c) <= x && x <= max(a,c) && min(b,d) <= y && y <= max(b,d)) return ((x - a) * (d - b) == (y - b) * (c - a));
    return false;
}

int count(ll x, ll y){
    int s = 0;
    for (int i=0;i<n;i++){
        tie(a, b) = polygon[i]; tie(c, d) = polygon[i+1];
        if (point_in_segment(x,y,a,b,c,d)) return -1;
        if ((a <= x && x < c && (c-a)*(y-b) > (x-a)*(d-b) )|| (c <= x && x < a && (a-c)*(y-d) > (x-c)*(b-d)) ) s++;
    }
    return s;
}


int main(){
    scanf("%d %d",&n,&m);
    polygon.resize(n+1);
    for (int i=0;i<n;i++){
        scanf("%lld %lld",&x,&y);
        polygon[i] = {x,y};
    }
    polygon[n] = polygon[0];

    for (int j=0;j<m;j++){
        scanf("%lld %lld",&x,&y);
        int ans = count(x,y);
        if (ans == -1) printf("BOUNDARY\n");
        else if (ans%2) printf("INSIDE\n");
        else printf("OUTSIDE\n");
    }
    return 0;
}