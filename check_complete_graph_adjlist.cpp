#include <iostream>
#include <vector>

using namespace std;

bool isCompleteGraph(const vector<vector<int>>& adjList, int n) {
    for (int i = 0; i < n; ++i) {
        // In a complete graph, each vertex should be connected to n-1 other vertices
        if (adjList[i].size() != n - 1) {
            return false;
        }
    }
    return true;
}

int main() {
    int n, edges;
    cout << "Enter number of vertices: ";
    cin >> n;

    vector<vector<int>> adjList(n);
    cout << "Enter number of edges: ";
    cin >> edges;

    cout << "Enter edges (u v) - zero based indexing:\n";
    for (int i = 0; i < edges; ++i) {
        int u, v;
        cin >> u >> v;
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }

    if (isCompleteGraph(adjList, n)) {
        cout << "The graph is a complete graph.\n";
    } else {
        cout << "The graph is not a complete graph.\n";
    }

    return 0;
}
