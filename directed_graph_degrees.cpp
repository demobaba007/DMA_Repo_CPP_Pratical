#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, edges;
    cout << "Enter number of vertices: ";
    cin >> n;

    cout << "Enter number of edges: ";
    cin >> edges;

    vector<vector<int>> adjList(n);
    vector<int> inDegree(n, 0);
    vector<int> outDegree(n, 0);

    cout << "Enter edges (u v) - directed edge from u to v, zero based indexing:\n";
    for (int i = 0; i < edges; ++i) {
        int u, v;
        cin >> u >> v;
        adjList[u].push_back(v);
        outDegree[u]++;
        inDegree[v]++;
    }

    cout << "Vertex\tIn-Degree\tOut-Degree\n";
    for (int i = 0; i < n; ++i) {
        cout << i << "\t" << inDegree[i] << "\t\t" << outDegree[i] << "\n";
    }

    return 0;
}
