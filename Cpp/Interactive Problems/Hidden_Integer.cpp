#include <bits/stdc++.h>
using namespace std;

int x;
string ans;

int main(){
    int mini = 1; int maxi = 1e9;
    while (mini < maxi){
        int mid = (maxi+mini)/2;
        printf("? %d\n", mid);
        fflush(stdout);
        cin >> ans;
        if (ans == "YES"){
            mini = mid+1;
        }
        else maxi = mid;
    }
    printf("! %d\n", mini);
    fflush(stdout);
    return 0;
}
