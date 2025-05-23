#include <bits/stdc++.h>
using namespace std;
using vi = vector<int>;
using usi = unordered_set<int>;



int n;
vi nextPlanet,cycle;

void fillCycle(int i){
    vi nodes; 
    usi visited;
    int x = i;
    while (true){
        nodes.push_back(x); visited.insert(x);
        int y = nextPlanet[x];
        int m = nodes.size();
        if (cycle[y]>0){
            for (int i=0;i<m;i++){
                cycle[nodes[i]] = cycle[y] + m - i;
            }
            return;
        }
        if (visited.count(y)){
            int i=0;
            while (nodes[i] != y){
                cycle[nodes[i]] = m - i;
                i++;
            }
            int cycleSize = m-i;
            while (i<=m-1){
                cycle[nodes[i]] = cycleSize;
                i++;
            }
            return;
        }
        x = y;
    }
}

int main(){
    scanf("%d",&n);
    nextPlanet.resize(n+1); cycle.assign(n+1,0);
    for (int i=1;i<=n;i++) scanf("%d",&nextPlanet[i]);
    for (int i=1;i<=n;i++){
        if (cycle[i]==0) fillCycle(i);
    }

    for (int i=1;i<=n;i++) printf("%d ",cycle[i]);
    return 0;
}