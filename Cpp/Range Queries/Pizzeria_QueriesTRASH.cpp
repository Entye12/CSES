#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9+1;
int n0,n,q;
int leftTree[],rightTree[], floor[];

int padding(int n){
    int p = 0;
    while ((1<<p)<n) p++;
    return 1<<p;
}

void pull(int i){
    leftTree[i] = min(1+leftTree[2*i],rightTree[2*i+1]);
    rightTree[i] = min(leftTree[2*i],1+rightTree[2*i+1]);
}


void update(int k, int x){
    k += (n-1);
    leftTree[k] = x; rightTree[k] = x;
    k/=2;
    while (k>0){
        pull(k); k/= 2;
    }
}


int get_left(int k){
    int r = k + (n-1); int l = n;
    int ans = INF;int step = 0;
    while (l < r){
        if (r%2){
            ans = min(ans,leftTree[r]+step);
            step += 1<<floor[r];
            r--;
        }
        r /= 2; l /= 2;
    }
    ans = min(ans,leftTree[r]+step);
    return ans;
}

int get_right(int k){
    int l = k + (n-1); int r = 2*n-1;
    int ans = INF;int step = 0;
    while (l < r){
        if (l%2==0){
            ans = min(ans,rightTree[l]+step);
            step += 1<<floor[l];
            l++;
        }
        r /= 2; l /= 2;
    }
    ans = min(ans,rightTree[r]+step);
    return ans;
}

int get(int k){
    return min(get_left(k),get_right(k));
}

void preprocessing(){
    scanf("%d %d",&n0,&q);
    n = padding(n0);
    leftTree[2*n]; rightTree[2*n]; floor[2*n];
    for (int i=n;i<n+n0;i++){
        scanf("%d",&rightTree[i]);
        leftTree[i] = rightTree[i]; floor[i]=0;
    } 

    for (int i=n-1;i>0;i--){
        pull(i);
        floor[i] = floor[2*i]+1;
    } 
}

int main(){
    preprocessing();
    for (int i=0;i<q;i++){
        int t;
        scanf("%d ",&t);
        if (t==1){
            int k; int x;
            scanf("%d %d",&k,&x);
            update(k,x);
        }
        else {
            int k;
            scanf("%d",&k);
            printf("%d\n",get(k));
        }
    }
    return 0;
}
