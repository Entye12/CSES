#include <bits/stdc++.h>
using namespace std;

string s;
unordered_set<char> single;
vector<char> pairs;

int main(){
    cin >> s;
    for (char c: s){
        if (single.count(c)){
            single.erase(c);
            pairs.push_back(c);
        }
        else single.insert(c);
    }
    if ( single.size() >= 2 || (s.length()%2==0 && !single.empty()) ) printf("NO SOLUTION");
    else {
        for (char c:pairs) {
            printf("%c",c);
        }
        if (!single.empty()) printf("%c",*single.begin());
        for (int i = (int)pairs.size()-1; i>=0; i--){
            printf("%c",pairs[i]);
        }
    }
    return 0;
}