#include <bits/stdc++.h>
using namespace std;

int t;
int n,x;

int main(){
    scanf("%d",&t);
    for (int i=0;i<t;i++){
        scanf("%d",&n);
        int s = 0;
        for (int j=0;j<n;j++){
            scanf("%d",&x);
            s ^= x;
        }
        if (s) printf("first\n");
        else printf("second\n");
    }
    return 0;
}