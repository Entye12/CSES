#include <bits/stdc++.h>
using namespace std;

int n;

void f(int n,int start,int end,int inter){
    if (n==1){
        printf("%d %d\n",start,end);
    }
    else {
        f(n-1,start,inter,end);
        printf("%d %d\n",start,end);
        f(n-1,inter,end,start);
    }
}

int main(){
    scanf("%d",&n);
    int ans = (1<<n)-1;
    printf("%d\n",ans);
    f(n,1,3,2);
}