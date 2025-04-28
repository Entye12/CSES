#include <bits/stdc++.h>
using namespace std;
using vi = vector<int>;


int n0,n,q; const int INF = 1e9+1;
vi segment_tree;

int padding(int n){
    int p = 0;
    while ((1<<p)<n) p++;
    return 1<<p;
}

int get_min(int a, int b){
    a += (n-1); b += (n-1);
    int x = INF;
    while (a<=b){
        if (a%2){
            x = min(x,segment_tree[a]);
            a++;
        } 
        if (b%2==0){
            x = min(x,segment_tree[b]);
            b--;
        }
        a/=2 ; b/=2;
    }
    return x;
}

void update(int k, int u){
    k += n-1;
    segment_tree[k] = u;
    k /= 2;
    while (k>0){
        segment_tree[k] = min(segment_tree[2*k],segment_tree[2*k+1]);
        k /= 2;
    }
}

void preprocessing(){
    scanf("%d %d",&n0,&q);
    n = padding(n0);
    segment_tree = vi(2*n,INF);
    for (int i=n;i<n+n0;i++) scanf("%d",&segment_tree[i]);
    for (int i=n-1;i>0;i--) segment_tree[i] = min(segment_tree[2*i],segment_tree[2*i+1]);
}


int main(){
    preprocessing();
    for (int i=0;i<q;i++){
        int t;
        scanf("%d ",&t);
        if (t==1){
            int k; int u;
            scanf("%d %d",&k,&u);
            update(k,u);
        }
        else {
            int a,b;
            scanf("%d %d",&a,&b);
            printf("%d\n",get_min(a,b));
        }
    }
    return 0;
}