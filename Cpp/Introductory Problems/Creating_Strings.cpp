#include <bits/stdc++.h>
using namespace std;

string word;

unordered_map<int, int> facto = {
    {0, 1},
    {1, 1},
    {2, 2},
    {3, 6},
    {4, 24},
    {5, 120},
    {6, 720},
    {7, 5040},
    {8, 40320}
};

string nextPermutation(string &word){
    int l=word.size();
    int index = l-1;
    while (index > 0 && word[index] <= word[index-1]) index--;
    if (index>0){
        int k = l-1;
        while (word[k] <= word[index-1]) k--;
        swap(word[k],word[index-1]);
        int left = index;
        int right = l-1;

        while (left < right){
            swap(word[left],word[right]);
            left++;
            right--;
        }
    }
    else {
        for (int i=1;i<l/2;i++){
            swap(word[i],word[l-1-i]);
        }
    }
    return word;
}

int main(){
    cin >> word;
    sort(word.begin(), word.end());
    int n = word.size();
    int ans = facto[n];

    unordered_map<char,int> counter;
    for (char c:word) counter[c]++;
    for (const auto& pair : counter) ans /= facto[pair.second];
    printf("%d\n",ans);

    for (int i=1; i<=ans;i++){
        cout << word << endl;
        word = nextPermutation(word);
    }
}