#include <bits/stdc++.h>
using namespace std;

int n,x,a;
map<int,int> dico; // the hash for unordered_map doesn't pass

int main(){
    scanf("%d %d",&n,&x);
    for (int i=1; i<=n; i++){
        scanf("%d",&a);

        if (dico.count(a)){
            printf("%d %d\n",dico[a],i);
            return 0;
        }
        dico[x-a] = i;
    }
    printf("IMPOSSIBLE\n");
    return 0;
}