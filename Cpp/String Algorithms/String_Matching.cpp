#include <bits/stdc++.h>
using namespace std;
using s = string;
using vi = vector<int>;



vi Z_algorithm(s word){
    int n = word.size();
    vi z_array(n,0);
    int x = 0; int y = 0;
    for (int i=1;i<n;i++){
        z_array[i] = max(0,min(z_array[i-x],y-i+1));
        while (i+z_array[i]<n && word[z_array[i]] == word[i+z_array[i]]){
            x = i; y = i+z_array[i]; z_array[i]++;
        }
    }
    return z_array;
}


int main(){
    s word,pattern;
    cin >> word;
    cin >> pattern;
    int p = pattern.size(); int n = word.size();
    s w = pattern + '#' + word;
    vi z_array = Z_algorithm(w);
    int ans = 0;
    for (int x:z_array){
        if (x == p) ans++;
    }
    printf("%d\n",ans);
    return 0;
}