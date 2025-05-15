#include <iostream>
#include <vector>

using namespace std;

bool isCompleteGraph(const vector<vector<int>>& adjMatrix) {
    int n = adjMatrix.size();
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (i != j && adjMatrix[i][j] == 0) {
                return false;
            }
        }
    }
    return true;
}

int main() {
    int n;
    cout << "Enter number of vertices: ";
    cin >> n;

    vector<vector<int>> adjMatrix(n, vector<int>(n));
    cout << "Enter adjacency matrix (row-wise):\n";
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> adjMatrix[i][j];
        }
    }

    if (isCompleteGraph(adjMatrix)) {
        cout << "The graph is a complete graph.\n";
    } else {
        cout << "The graph is not a complete graph.\n";
    }

    return 0;
}
