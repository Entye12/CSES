#include <bits/stdc++.h>
using namespace std;


int q,k,n,x;

struct hash_pair {
    template <class T1, class T2>
    size_t operator()(const pair<T1, T2>& p) const
    {
        size_t hash1 = hash<T1>{}(p.first);
        size_t hash2 = hash<T2>{}(p.second);
        return hash1
               ^ (hash2 + 0x9e3779b9 + (hash1 << 6)
                  + (hash1 >> 2));
    }
};

using umiii = unordered_map<pair<int,int>,int,hash_pair>;

umiii dico;


int f(int n,int k){
    if (dico.count({n,k})) return dico[{n,k}];

    if (k<=(n+1)/2) return (2*k<=n) ? 2*k : 2*k % n;
    x = (n%2==0) ? 2*f(n/2,k-(n+1)/2)-1 : 2*f(n/2,k-(n+1)/2)+1;
    dico[{n,k}] = x;
    return x;
}

int main(){
    dico[{1,1}]=1;
    scanf("%d",&q);
    for (int i=0;i<q;i++){
        scanf("%d %d",&n,&k);
        printf("%d\n",f(n,k));
    }
    return 0;
}