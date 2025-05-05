#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9+1;
int n0,n,q;

const int MAXN = 1<<18;
int leftTree[2 * MAXN];
int rightTree[2 * MAXN];

int padding(int n) {
    return 1 << (32 - __builtin_clz(n - 1));
}


void left_pull(int i){
    leftTree[i] = min(leftTree[2*i],leftTree[2*i+1]);
}

void right_pull(int i){
    rightTree[i] = min(rightTree[2*i],rightTree[2*i+1]);
}

void update(int k, int x){
    int idx = k + n - 1;
    leftTree[idx] = x - k;
    rightTree[idx] = x + k;
    idx /= 2;
    while (idx > 0){
        left_pull(idx);
        right_pull(idx);
        idx /= 2;
    }
}

int get_left(int k){
    int r = k + (n-1); int l = n;
    int ans = INF;
    while (l <= r){
        if (r%2==0){
            ans = min(ans,leftTree[r]);
            r--;
        }
        if (l%2){
            ans = min(ans,leftTree[l]);
            l++;
        }
        r /= 2; l /= 2;
    }
    return ans+k;
}

int get_right(int k){
    int l = k + (n-1); int r = 2*n-1;
    int ans = INF;
    while (l <= r){
        if (r%2==0){
            ans = min(ans,rightTree[r]);
            r--;
        }
        if (l%2){
            ans = min(ans,rightTree[l]);
            l++;
        }
        r /= 2; l /= 2;
    }
    return ans-k;
}

int get(int k){
    return min(get_left(k),get_right(k));
}

void preprocessing(){
    scanf("%d %d",&n0,&q);
    n = padding(n0);
    for (int i = 1; i <= n0; i++){
        int x;
        scanf("%d", &x);
        leftTree[n - 1 + i] = x - i;
        rightTree[n - 1 + i] = x + i;
    }

    for (int i = n + n0; i < 2 * n; i++) {
        leftTree[i] = rightTree[i] = INF;
    }

    for (int i=n-1;i>0;i--){
        left_pull(i); right_pull(i);
    } 
}

int main(){
    preprocessing();
    for (int i=0;i<q;i++){
        int t;
        scanf("%d",&t);
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