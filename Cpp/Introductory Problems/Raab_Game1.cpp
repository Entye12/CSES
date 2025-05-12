#include <bits/stdc++.h>
using namespace std;

int t,n,a,b;

int raab(int n, int a, int b){
    if ( (a+b>n) || (a*b == 0 && a+b>0)){
        printf("NO\n");
        return 0;
    }
    int m = a+b;
    printf("YES\n");
    for (int i=1;i<=n;i++){
        printf("%d ",i);
    }
    printf("\n");
    for (int i=1;a+i<=m;i++){
        printf("%d ",a+i);
    }
    for (int i=1;i<=a;i++){
        printf("%d ",i);
    }
    for (int i=m+1;i<=n;i++){
        printf("%d ",i);
    }
    printf("\n");
    return 0;
}

int main(){
    scanf("%d",&t);
    for (int i=0;i<t;i++){
        scanf("%d %d %d",&n,&a,&b);
        raab(n,a,b);
    }
    return 0;
}