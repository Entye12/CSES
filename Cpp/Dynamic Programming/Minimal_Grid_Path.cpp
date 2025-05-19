#include <bits/stdc++.h>
using namespace std;
using vc = vector<char>;
using vvc = vector<vc>;
using pii = pair<int,int>;
using vpii = vector<pii>;
using vb = vector<bool>;
using vvb = vector<vb>;


int main(){
    int n;
    scanf("%d", &n);
    vvc grid(n, vc(n));
    for (int i=0; i<n; i++)
        for (int j=0; j<n; j++)
            scanf(" %c", &grid[i][j]);

    string ans;
    ans += grid[0][0];

    vvb visited(n, vb(n, false));
    visited[0][0] = true;

    vpii frontier = {{0, 0}};

    for (int d = 1; d < 2 * n - 1; d++) {
        char mini = 'Z' + 1;
        vpii nextFrontier;

        for (auto [i, j] : frontier) {
            if (i + 1 < n && !visited[i+1][j]) {
                char c = grid[i+1][j];
                if (c < mini) {
                    mini = c;
                    nextFrontier.clear();
                }
                if (c == mini) {
                    visited[i+1][j] = true;
                    nextFrontier.emplace_back(i+1, j);
                }
            }
            if (j + 1 < n && !visited[i][j+1]) {
                char c = grid[i][j+1];
                if (c < mini) {
                    mini = c;
                    nextFrontier.clear();
                }
                if (c == mini) {
                    visited[i][j+1] = true;
                    nextFrontier.emplace_back(i, j+1);
                }
            }
        }

        ans += mini;
        swap(frontier, nextFrontier);
    }

    cout << ans << '\n';
    return 0;
}
