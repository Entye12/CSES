#include <bits/stdc++.h>
using namespace std;

int n,x;
set<int> ens;


int main(){
    scanf("%d",&n);
    for (int i=1; i<=n; i++){
        scanf("%d", &x);
        ens.insert(x);
    }
    cout << ens.size()<< endl;
    return 0;
}
