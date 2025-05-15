#include <bits/stdc++.h>
using namespace std;
using vi = vector<int>;
using si = set<int>;
using umii = unordered_map<int,int>;



int n,k,x,mex; int out,in;
vi numbers;
si absent;
umii freq;



int main(){
    scanf("%d %d",&n,&k);
    numbers.resize(n+1);
    for (int i=1;i<=n;i++){
        scanf("%d",&numbers[i]);
    }
    
    for (int i=0;i<=k;i++){
        absent.insert(i);
    }

    for (int i=1;i<=k;i++){
        x = numbers[i];
        freq[x]++;
        absent.erase(x);
    }

    for (int i=1;i<=n-k+1;i++){
        mex = *absent.begin();
        printf("%d ", mex);
        // remove the i-th element from the window
        out = numbers[i];
        freq[out]--;
        if (freq[out] == 0) absent.insert(out);

        // add the i+k element to the window
        if (i+k <= n){
            in = numbers[i+k];
            freq[in]++;
            absent.erase(in);
        }
    }
    return 0;
}