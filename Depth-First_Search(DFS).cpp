#include <iostream>
#include <vector>
using namespace std;

vector<int> visited(1000, 0);
vector<vector<int>> adj;

void dfs(int node) {
    visited[node] = 1;
    cout << node << " ";

    for (int x : adj[node]) {
        if (!visited[x]) {
            dfs(x);
        }
    }
}

int main() {
    int n, e;
    cout << "Enter number of nodes: ";
    cin >> n;
    cout << "Enter number of edges: ";
    cin >> e;

    adj.assign(n, vector<int>());

    cout << "Enter edges (u v):" << endl;
    for (int i = 0; i < e; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    int start;
    cout << "Enter start node: ";
    cin >> start;

    cout << "DFS Traversal: ";
    dfs(start);
    cout << endl;

    return 0;
}
