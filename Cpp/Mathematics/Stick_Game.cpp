#include <bits/stdc++.h>
using namespace std;

int n,k;

int main(){
    scanf("%d %d",&n,&k);
    vector<int> moves(k,0);
    for (int i=0;i<k;i++) scanf("%d",&moves[i]);
    sort(moves.begin(),moves.end());
    
    vector<char> ans(n+1,'L');
    for (int i=0;i<=n;i++){
        if (ans[i]=='L'){
            for (int p:moves){
                if (p+i>n) break;
                ans[i+p] = 'W';
            }
        }
    }
    for (int i=1;i<=n;i++){
        printf("%c",ans[i]);
    }
    return 0;
}