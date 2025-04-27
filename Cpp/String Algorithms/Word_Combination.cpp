#include <bits/stdc++.h>
using namespace std;
using ll = long long;


const ll MOD = 1e9+7;

class TrieNode{
    public :
        vector<TrieNode*> children;
        bool isleaf;
    
    TrieNode() {
            children = vector<TrieNode*> (26,nullptr);
            isleaf = false;
    }
};

class Trie{
    private:
        TrieNode* root;
    public:
        Trie(){
            root = new TrieNode();
        }

        void insert(const string &word){
            TrieNode* current = root;
            for (char letter : word){
                int index = letter - 'a';
                if (!current -> children[index]){
                    current -> children[index] = new TrieNode();
                }
                current = current -> children[index];
            }
            current -> isleaf = true;
        }

        void construct(int k){
            string word;
            for (int i=0;i<k;i++){
                cin >> word;
                insert(word);
            }
        }

        int word_combination(const string &word){
            int n = word.size();
            vector<int> dp(n + 1, 0);
            dp[n] = 1;
            for (int i=n-1;i >= 0; i--){
                TrieNode* current = root;
                for (int j=i;j<n;j++){
                    int idx = word[j] - 'a';
                    if (!current->children[idx]){
                        break;
                    }
                    current = current -> children[idx];
                    if (current -> isleaf){
                        dp[i] = (dp[i] + dp[j+1])%MOD;
                    }
                }
            }
            return dp[0];
        }
};

int main(){
    string word;
    int k;

    cin >> word;
    cin >> k;

    Trie trie;
    trie.construct(k);

    int ans = trie.word_combination(word);
    cout << ans << endl;
    return 0;
}
