#include <bits/stdc++.h> 
using namespace std;
using vi = vector<int>;
using vc = vector<char>;
using vvi = vector<vector<int>>;
using vvc = vector<vector<char>>;
using qpii = queue<pair<int,int>>;
using mpiic = map<pair<int, int>, char>;
using mcpii = map<char, pair<int, int>>;
using vpii = vector<pair<int,int>>;

int const INF = 1e9;


int n,m; int Ax,Ay;
string s;
vvc grid, direction;
vvi distanceA; vvi distanceM;
qpii Qm, Qa;
mpiic direction_to_char; mcpii char_to_direction;



bool in_bound(int i, int j){
    return (0 <= i && i < n && 0 <= j && j < m);
}

void bfs(qpii &Q, vvi &distance, bool isA, vvc &direction){

    while (!Q.empty()){
        int x,y;
        tie(x,y) = Q.front(); Q.pop();
        for (auto [dx, dy] : vpii{{-1, 0}, {0, -1}, {1, 0}, {0, 1}}) {
            int nx = x + dx; int ny = y + dy;
            if (in_bound(nx, ny) && grid[nx][ny] != '#' && distance[nx][ny] == INF) {
                Q.push({nx, ny});
                distance[nx][ny] = distance[x][y]+1;
                if (isA){
                    direction[nx][ny] = direction_to_char[{dx,dy}];
                }
            }
        }
    }
}

void printSolution(int x, int y){

    printf("YES\n");
    printf("%d\n",distanceA[x][y]);
    string ans = "";
    while (grid[x][y] != 'A'){
        char d = direction[x][y];
        ans.push_back(d);
        auto [dx, dy] = char_to_direction[d];
        x -= dx; y -= dy;
    }
    reverse(ans.begin(),ans.end());
    for (char c:ans){
        cout << c;
    }
    cout << '\n';
}

int main(){

    direction_to_char[{-1, 0}] = 'U';
    direction_to_char[{1, 0}] = 'D';
    direction_to_char[{0, -1}] = 'L';
    direction_to_char[{0, 1}] = 'R';

    char_to_direction['U'] = {-1, 0};
    char_to_direction['D'] = {1, 0};
    char_to_direction['L'] = {0, -1};
    char_to_direction['R'] = {0, 1};


    scanf("%d %d",&n,&m);
    grid.resize(n);
    for (int i=0;i<n;i++){
        cin >> s;
        grid[i] = vc(s.begin(), s.end());
    }
    distanceA = vvi(n, vi(m, INF)); distanceM = vvi(n, vi(m, INF));
    direction = vvc(n, vc(m,'.'));

    for (int i=0;i<n;i++){
        for (int j=0;j<m;j++){
            if (grid[i][j] == 'A'){
                distanceA[i][j] = 0;
                Ax = i; Ay = j;
                Qa.push({i,j});
            }
            else if (grid[i][j] == 'M'){
                distanceM[i][j] = 0;
                Qm.push({i,j});
            }
        }
    }

    bfs(Qa,distanceA,true,direction);
    bfs(Qm,distanceM,false,direction);

    for (int i=0; i<n; i++){
        if (distanceA[i][0] < distanceM[i][0]){
            printSolution(i,0);
            return 0;
        }
        if (distanceA[i][m-1] < distanceM[i][m-1]){
            printSolution(i,m-1);
            return 0;
        }
    }

    for (int j=0; j<m; j++){
        if (distanceA[0][j] < distanceM[0][j]){
            printSolution(0,j);
            return 0;
        }
        if (distanceA[n-1][j] < distanceM[n-1][j]){
            printSolution(n-1,j);
            return 0;
        }
    }
    printf("NO\n");
    return 0;
}