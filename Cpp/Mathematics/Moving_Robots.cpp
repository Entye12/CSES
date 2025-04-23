#include <bits/stdc++.h>
using namespace std;

using vd = vector<double>;
using vvdd = vector<vector<double>>;
using pii = pair<int, int>;
using vpii = vector<pii>;
using adj_map = map<pii, set<pii>>;

int k;
adj_map adj;
vvdd proba_empty(8, vd(8, 1));

adj_map adj_list() {
    adj_map adj;
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            for (auto [di, dj] : vpii{{-1, 0}, {1, 0}, {0, -1}, {0, 1}}) {
                int ni = i + di, nj = j + dj;
                if (0 <= ni && ni < 8 && 0 <= nj && nj < 8) {
                    adj[{i, j}].insert({ni, nj});
                }
            }
        }
    }
    return adj;
}

vvdd next_table(const vvdd &table) {
    vvdd next(8, vd(8, 0));
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            const auto &neighbors = adj[{i, j}];
            for (auto [x, y] : neighbors) {
                next[x][y] += table[i][j] / neighbors.size();
            }
        }
    }
    return next;
}

vvdd contribution_of_robot_starting(int i, int j) {
    vvdd table(8, vd(8, 0));
    table[i][j] = 1.0;
    for (int r = 1; r <= k; r++) {
        table = next_table(table);
    }
    return table;
}

void empty_starting_at(int i, int j) {
    vvdd proba_presence = contribution_of_robot_starting(i, j);
    for (int r = 0; r < 8; r++) {
        for (int t = 0; t < 8; t++) {
            proba_empty[r][t] *= (1 - proba_presence[r][t]);
        }
    }
}

int main() {
    scanf("%d", &k);
    adj = adj_list();

    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            empty_starting_at(i, j);
        }
    }

    double ans = 0;
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            ans += proba_empty[i][j];
        }
    }

    printf("%.6f\n", ans);
    return 0;
}