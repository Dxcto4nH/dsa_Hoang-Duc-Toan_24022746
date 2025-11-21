#include <bits/stdc++.h>
using namespace std;

int prim(int n, vector<vector<pair<int, int>>>& adj) {
    vector<bool> used(n, false);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    pq.push({ 0, 0 }); // {weight, node}
    int total = 0;

    while (!pq.empty()) {
        auto [w, u] = pq.top();
        pq.pop();

        if (used[u]) continue;
        used[u] = true;
        total += w;

        for (auto& p : adj[u]) {
            int v = p.first;
            int weight = p.second;
            if (!used[v]) pq.push({ weight, v });
        }
    }
    return total;
}

int main() {
    int n = 5;
    vector<vector<pair<int, int>>> adj(n);

    // Example edges
    // adj[u].push_back({v, w});
    // adj[v].push_back({u, w});

    return 0;
}
