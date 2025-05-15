#include <bits/stdc++.h>
using namespace std;
using umii = unordered_map<int,int>;
using misi = map<int,set<int>>;
using vi = vector<int>;

int n,k,x,mode; int oldFreq,newFreq,out,in,oldOutFreq,newOutFreq,oldInFreq,newInFreq;
umii xToFreq;
misi freqToX;
vi numbers;

int main(){
    scanf("%d %d",&n,&k);
    numbers.resize(n+1);
    
    for (int i=1;i<=n;i++){
        scanf("%d",&numbers[i]);
    }

    for (int i=1;i<=k;i++){
        x = numbers[i];
        oldFreq = xToFreq[x];
        
        freqToX[oldFreq].erase(x);
        if (freqToX[oldFreq].empty()) freqToX.erase(oldFreq);

        xToFreq[x]++;
        newFreq = xToFreq[x];
        freqToX[newFreq].insert(x);
    }

    for (int i=1;i<=n-k+1;i++){
        auto it = freqToX.rbegin();

        mode = *it->second.begin();
        printf("%d ",mode);
        
        out = numbers[i];
        oldOutFreq = xToFreq[out];
        
        freqToX[oldOutFreq].erase(out);
        if (freqToX[oldOutFreq].empty()) freqToX.erase(oldOutFreq);

        xToFreq[out]--;
        newOutFreq = xToFreq[out];
        if (newOutFreq>0) freqToX[newOutFreq].insert(out);
        else xToFreq.erase(out); 

        if (i+k<=n){
            in = numbers[i+k];
            oldInFreq = xToFreq[in];
            freqToX[oldInFreq].erase(in);
            if (freqToX[oldInFreq].empty()) freqToX.erase(oldInFreq);
            
            xToFreq[in]++;
            newInFreq = xToFreq[in];
            freqToX[newInFreq].insert(in);
        }
    }
    return 0;
}