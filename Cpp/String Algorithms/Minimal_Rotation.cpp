#include <bits/stdc++.h>
using namespace std;
using vi = vector<int>;
using si = unordered_set<int>;

string word;
int n; char mini;

void unite(si &s1, si &s2){
    for (int a: s2){
        s1.insert(a);
    }
}

int main(){
    cin >> word;
    n = word.length();
    vi battle(n+1,-1);
    si survivor{};
    mini = *min_element(word.begin(), word.end());

    for (int i=0;i<n;i++){
        if (word[i] == mini){
            survivor.insert(i);
            battle[i] = (i+1)%n;
        }
    }

    while (survivor.size() > 1){
        si toDelete{}; si lived{};
        mini = 'z';
        for (int idx : survivor){
            if (word[battle[idx]] < mini){
                mini = word[battle[idx]];
                unite(toDelete,lived);
                lived.clear();
                lived.insert(idx);
            }
            else if (word[battle[idx]] == mini){
                lived.insert(idx);
            }
            else {
                toDelete.insert(idx);
            }
        }

        for (int i:toDelete) survivor.erase(i);
        
        si secondDelete{};
        for (int idx : survivor){
            if ( survivor.count(battle[idx]) && secondDelete.size() < survivor.size()-1 ) secondDelete.insert(battle[idx]);
        }

        for (int i:secondDelete) survivor.erase(i);

        for (int i:survivor) battle[i] = (battle[i]+1)%n;
    }
    int start = *survivor.begin();
    cout << word.substr(start) + word.substr(0, start);
    return 0;
}