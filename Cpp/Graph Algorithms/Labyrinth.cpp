#include <bits/stdc++.h>
using namespace std;

int n, m;
int x, y, nx, ny;
vector<string> grid;
string s;

map<pair<int, int>, char> direction;
map<char, pair<int, int>> char_direction;

bool in_bound(int i, int j) {
    return (0 <= i && i < n && 0 <= j && j < m);
}

string labyrinth(int i, int j) {
    bool foundB = false;  
    queue<pair<int, int>> Q;
    Q.push({i, j}); 

    while (!Q.empty()) {
        x = Q.front().first; 
        y = Q.front().second;
        Q.pop();

        for (auto [dx, dy] : vector<pair<int, int>>{{-1, 0}, {0, -1}, {1, 0}, {0, 1}}) {
            nx = x + dx; 
            ny = y + dy;
            if (in_bound(nx, ny) && grid[nx][ny] == '.') {
                Q.push({nx, ny});
                grid[nx][ny] = direction[{dx, dy}]; 
            }
            if (in_bound(nx, ny) && grid[nx][ny] == 'B') {
                foundB = true;
                grid[nx][ny] = direction[{dx, dy}]; 
                break; 
            }
        }
        if (foundB) break;
    }

    if (!foundB) return ""; 

    string path;
    x = nx; 
    y = ny;
    while (grid[x][y] != 'A') {  
        
        char d = grid[x][y];
        path.push_back(d);
        int dx = char_direction[d].first; 
        int dy = char_direction[d].second;
        x -= dx; 
        y -= dy;
    }

    reverse(path.begin(), path.end());  
    return path;
}

int main() {
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++) {
        cin >> s;
        grid.emplace_back(s);
    }
    
    direction[{-1, 0}] = 'U'; 
    direction[{0, -1}] = 'L'; 
    direction[{1, 0}] = 'D'; 
    direction[{0, 1}] = 'R';

    char_direction['U'] = {-1, 0}; 
    char_direction['L'] = {0, -1}; 
    char_direction['D'] = {1, 0}; 
    char_direction['R'] = {0, 1}; 

    bool foundA = false; 
    string path = "";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (grid[i][j] == 'A') {
                path = labyrinth(i, j);
                foundA = true;
                break;
            }
        }
        if (foundA) break;  
    }

    if (path.size() == 0) {
        printf("NO\n");
    } else {
        printf("YES\n");
        printf("%zu\n", path.size());
        printf("%s", path.c_str());  
    }

    return 0;
}
