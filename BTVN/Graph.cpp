// Dùng ma trận kề
#include <iostream>
#include <vector>
using namespace std;

class Graph {
    int n;
    vector<vector<int>> adj; // ma trận kề
public:
    Graph(int n) : n(n), adj(n, vector<int>(n, 0)) {}

    void addEdge(int u, int v) {
        adj[u][v] = 1;
		adj[v][u] = 1; // có hướng thì bỏ dòng này
    }

    void print() {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++)
                cout << adj[i][j] << " ";
            cout << endl;
        }
    }
};

//Dùng danh sách kề
class GraphList {
	int n;
	vector<vector<int>> adj; // danh sách kề
public:
	GraphList(int n) : n(n), adj(n) {}

	void addEdge(int u, int v) {
		adj[u].push_back(v);
		adj[v].push_back(u); // có hướng thì bỏ dòng này
	}

	void print() {
		for (int i = 0; i < n; i++) {
			cout << i << ": ";
			for (int v : adj[i])
				cout << v << " ";
			cout << endl;
		}
	}
};

//Dùng danh sách cạnh
class Edge {
public:
	int u, v;
	Edge(int u, int v) : u(u), v(v) {}
};
	
class GraphEdgeList {
	int n;
	vector<Edge> edges; // danh sách cạnh
public:
	GraphEdgeList(int n) : n(n) {}
	void addEdge(int u, int v) {
		edges.push_back(Edge(u, v));
	}
	void print() {
		for (Edge e : edges)
			cout << e.u << " -- " << e.v << endl;
	}
};