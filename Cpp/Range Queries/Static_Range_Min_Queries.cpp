#include <bits/stdc++.h>
using namespace std;
using vi = vector<int>;
using vvi = vector<vi>;

const int N = 2*1e5 + 1;
int log2_table[N];

void build_log2_table(int n){
    log2_table[1] = 0;
    for (int i = 2; i <= n; i++) {
        log2_table[i] = log2_table[i/2] + 1;
    }
}

int main(){
    int n,q;
    scanf("%d %d",&n,&q);
    build_log2_table(n); 
    int p = log2_table[n];
    vvi table(p+1,vi(n));


    for (int i=0;i<n;i++){
        scanf("%d",&table[0][i]);
    }

    for (int k=1;k<=p;k++){
        for (int i=0;i+(1<<k) <= n;i++){
            table[k][i] = min(table[k-1][i],table[k-1][i+(1<<(k-1))]);
        }
    }

    for (int i=0;i<q;i++){
        int a,b;
        scanf("%d %d",&a,&b);
        a--;b--;
        int k = log2_table[b-a+1];
        int m = min(table[k][a], table[k][b-(1<<k)+1]);
        printf("%d\n",m);
    }
    return 0;
}