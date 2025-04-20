#include <bits/stdc++.h>
using namespace std;

const int top = 1e6+1;
int n,x,count, counter[top];

int main(){
    scanf("%d",&n);
    for (int i=0; i<n;i++){
        scanf("%d",&x);
        counter[x]++;
    }
    for (int i=top-1;i>0;i--){
        int count = 0;
        for (int j=i;j<top;j+=i){
            count += counter[j];
            if (count >= 2) {
                printf("%d\n",i);
                return 0;
            }
        }
    }
}