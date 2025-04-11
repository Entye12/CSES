#include <bits/stdc++.h>
using namespace std;

int n;

int main(){
    scanf("%d",&n);
    if (n%4==1 || n%4==2) printf("NO\n");
    else if (n%4==0){
        printf("YES\n");
        printf("%d\n",n/2);
        for (int i=1; i<=n/2; i += 2){
            printf("%d %d ",i,n-i+1);
        }
        printf("\n%d\n",n/2);
        for (int i=2; i<=n/2; i+=2){
            printf("%d %d ",i,n-i+1);
        }
    }
    else {
        printf("YES\n");
        printf("%d\n",2+(n-3)/2);
        printf("%d %d ",1,2);
        for (int i=4; i<=(n+4)/2; i+=2){
            printf("%d %d ",i,n-i+4);
        }
        printf("\n%d\n",1+(n-3)/2);
        printf("%d ",3);
        for (int i=5;i<=(n+4)/2;i+=2){
            printf("%d %d ",i,n-i+4);
        }
    }
    return 0;
}