#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<int>;
using vvpill = vector<vector<pair<int,ll>>>;
using si = set<int>;
using pqplli = priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>>;

const ll INF = 1e18;
int n, m, a, b, city;
ll c, d;
vvpill routes;
vector<ll> distances; 
si visited;
pqplli nextc;

void dijkstra() {
    distances = vector<ll>(n+1, INF);
    distances[1] = 0;
    nextc.push({0, 1});

    while (visited.size() < n) {
        tie(d, city) = nextc.top(); nextc.pop(); 
        if (visited.find(city) != visited.end()) continue;
        visited.insert(city);

        for (auto &[b, c] : routes[city]) {
            if (visited.find(b) == visited.end() && c + distances[city] < distances[b]) {
                distances[b] = c + distances[city];
                nextc.push({distances[b], b});
            }
        }
    }
}

int main() {
    scanf("%d %d", &n, &m);
    routes.resize(n+1);

    for (int i = 0; i < m; i++) { 
        scanf("%d %d %lld", &a, &b, &c);
        routes[a].push_back({b, c});
    }
    dijkstra();
    for (int i = 1; i <= n; i++) {
        printf("%lld ", distances[i]); 
    }
    return 0;
}