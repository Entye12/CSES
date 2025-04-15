#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n; int a,b,c,d;
ll x,y;

vector<ll> numbers; map<ll,pair<int,int>> dico;

int main(){
    scanf("%d %lld",&n,&x);
    for (int i=1;i<=n;i++){
        scanf("%lld",&y);
        numbers.push_back(y);
    }
    for (int l=0;l<n-1;l++){
        for (int r=l+1;r<n;r++){
            if (dico.find(x - numbers[l] - numbers[r]) != dico.end()){
                a = dico[x - numbers[l] - numbers[r]].first; b = dico[x - numbers[l] - numbers[r]].second;
                c = l; d = r;
                printf("%d %d %d %d",++a,++b,++c,++d);
                return 0;
            }
        }
        for (int i=0;i<l;i++){
            dico[numbers[i]+numbers[l]] = make_pair(i,l);
        }
    }
    printf("IMPOSSIBLE\n");
    return 0;
}