#include <bits/stdc++.h>
using namespace std;

vector<int> dijkstra(int n, int start, vector<vector<pair<int, int>>>& adj) {
    vector<int> dist(n, 1e9);
    dist[start] = 0;

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({ 0, start });

    while (!pq.empty()) {
        auto [d, u] = pq.top();
        pq.pop();

        if (d != dist[u]) continue;

        for (auto& p : adj[u]) {
            int v = p.first;
            int w = p.second;
            if (dist[v] > d + w) {
                dist[v] = d + w;
                pq.push({ dist[v], v });
            }
        }
    }
    return dist;
}

int main() {
    int n = 5;
    vector<vector<pair<int, int>>> adj(n);

    // adj[u].push_back({v, w});
    // adj[v].push_back({u, w}); // nếu đồ thị vô hướng

    return 0;
}