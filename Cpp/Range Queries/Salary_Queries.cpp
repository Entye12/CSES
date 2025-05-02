#include <bits/stdc++.h>
using namespace std;
using vi = vector<int>;

int n0,n,q,p,a,b; char c;
const int N = 6e5+4;
int segment_tree[4*N];
vi salaries;
set<int> all_salaries;
unordered_map<int,int> sToIdx;
vector<tuple<char,int,int>> queries;

int padding(int n){
    int p = 0;
    while ((1<<p)<n) p++;
    return 1<<p;
}

void preprocessing(){
    scanf("%d %d",&n0,&q);
    salaries = vi(n0+1,0);
    for (int i=1;i<=n0;i++){
        scanf("%d",&salaries[i]);
        all_salaries.insert(salaries[i]);
    }
    for (int i=0;i<q;i++){
        scanf(" %c %d %d",&c,&a,&b);
        queries.push_back({c,a,b});
        if (c == '!') all_salaries.insert(b);
        else {
            all_salaries.insert(a); all_salaries.insert(b);
        }
    }
    int idx = 1;
    for (int s: all_salaries) sToIdx[s] = idx++; 
    int n1 = all_salaries.size();
    n = padding(n1);

    //segment_tree = vi(2*n,0);
    for (int s:salaries) segment_tree[sToIdx[s]+n-1]++;
    for (int i=n-1;i>0;i--) segment_tree[i] = segment_tree[2*i]+segment_tree[2*i+1];
}

void addValue(int idx,int u){
    idx += n-1;
    while (idx > 0){
        segment_tree[idx] += u;
        idx /= 2;
    }
}

void change(int k, int newS){
    int oldS = salaries[k];
    int oldIdx = sToIdx[oldS]; int newIdx = sToIdx[newS];
    addValue(oldIdx,-1); addValue(newIdx,1);
    salaries[k] = newS;
}

int count(int a, int b){
    a = sToIdx[a] + n - 1; b = sToIdx[b] + n - 1;
    int s = 0;
    while (a <= b){
        if (a%2){
            s += segment_tree[a]; a++;
        } 
        if (b%2==0){
            s+= segment_tree[b]; b--;
        } 
        a/= 2; b/=2;
    }
    return s;  
}


int main(){
    sToIdx.reserve(1024);
    sToIdx.max_load_factor(0.25);
    preprocessing();
    for (auto &[c,a,b] : queries){
        if (c == '!') change(a,b);
        else printf("%d\n", count(a,b));
    }
    return 0;
}