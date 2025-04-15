#include <bits/stdc++.h>
using namespace std;

int n,a;
vector<pair<int,int>> wait {make_pair(0,0)};

int main(){
    scanf("%d",&n);
    for (int i=0; i<n;i++){
        scanf("%d",&a);
        while (wait.back().first >= a){
            wait.pop_back();
        }
        printf("%d ",wait.back().second);
        wait.push_back(make_pair(a,i+1));
    }
    return 0;
}