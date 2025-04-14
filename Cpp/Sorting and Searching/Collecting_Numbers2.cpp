#include <bits/stdc++.h>
using namespace std;

int n,m;
unordered_map<int,int> idx;
vector<int> numbers {0};
int ans = 0; int cur = 0;



void update(int a, int b){
    if(idx[numbers[a]-1] <= idx[numbers[a]] && b < idx[numbers[a]-1]) ans++;
    if(idx[numbers[a]-1] > idx[numbers[a]] && b >= idx[numbers[a]-1]) ans--;
    if(idx[numbers[a]+1] >= idx[numbers[a]] && b > idx[numbers[a]+1]) ans++;
    if(idx[numbers[a]+1] < idx[numbers[a]] && b <= idx[numbers[a]+1]) ans--;
    idx[numbers[a]] = b;

    if (idx[numbers[b] - 1] <= idx[numbers[b]] && a < idx[numbers[b] - 1]) ans++;
    if (idx[numbers[b] - 1] > idx[numbers[b]] && a >= idx[numbers[b] - 1]) ans--;
    if (idx[numbers[b] + 1] >= idx[numbers[b]] && a > idx[numbers[b] + 1]) ans++;
    if (idx[numbers[b] + 1] < idx[numbers[b]] && a <= idx[numbers[b] + 1]) ans--;
    idx[numbers[b]] = a;

    swap(numbers[a], numbers[b]);
}

int main(){
    scanf("%d %d",&n,&m);
    for (int i=1; i<=n; i++){
        int x;
        scanf("%d",&x);
        numbers.push_back(x);
        idx[x] = i;
    }
    idx[n+1] = n+1;
    while (cur < n){
        cur++;
        ans++;
        while (cur<n && idx[cur]<idx[cur+1]){
            cur++;
        }
    }

    for (int j=1; j<= m; j++){
        int a,b;
        scanf("%d %d",&a,&b);
        update(a,b);
        printf("%d\n",ans);
    }
    return 0;
}