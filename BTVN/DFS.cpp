//DFS dùng đệ quy

void DFS(int u, vector<vector<int>>& adj, vector<bool>& visited) {
	visited[u] = true;
	cout << u << " ";
	for (int v : adj[u]) {
		if (!visited[v]) {
			DFS(v, adj, visited);
		}
	}
}
edges.push_back(Edge(u, v));
};