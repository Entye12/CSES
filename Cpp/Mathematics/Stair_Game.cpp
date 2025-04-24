#include <bits/stdc++.h>
using namespace std;

int n,t,p;

int main(){
    scanf("%d",&t);
    for (int i=0;i<t;i++){
        scanf("%d",&n);
        int grundy = 0;
        for (int j=0;j<n;j++){
            scanf("%d",&p);
            if (j%2) grundy ^= p;
        }
        if (grundy) printf("first\n");
        else printf("second\n");
    }
    return 0;
}