#include <bits/stdc++.h>
using namespace std;

int kruskal(int n, vector<tuple<int, int, int>>& edges) {
	// Sort edges by weight
	sort(edges.begin(), edges.end());
	// Disjoint Set Union (DSU) structure
	vector<int> parent(n), rank(n, 0);
	for (int i = 0; i < n; i++) parent[i] = i;
	function<int(int)> find = [&](int u) {
		if (parent[u] != u) parent[u] = find(parent[u]);
		return parent[u];
		};
	auto unionSets = [&](int u, int v) {
		int rootU = find(u);
		int rootV = find(v);
		if (rootU != rootV) {
			if (rank[rootU] < rank[rootV]) {
				parent[rootU] = rootV;
			}
			else if (rank[rootU] > rank[rootV]) {
				parent[rootV] = rootU;
			}
			else {
				parent[rootV] = rootU;
				rank[rootU]++;
			}
			return true;
		}
		return false;
		};
	int totalWeight = 0;
	for (auto& [w, u, v] : edges) {
		if (unionSets(u, v)) {
			totalWeight += w;
		}
	}
	return totalWeight;
}