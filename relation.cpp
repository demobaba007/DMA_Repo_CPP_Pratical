#include <iostream>
#include <vector>

using namespace std;

class RELATION {
private:
    vector<vector<bool>> matrix;
    int size;

public:
    RELATION(const vector<vector<bool>>& mat) {
        matrix = mat;
        size = mat.size();
    }

    bool isReflexive() {
        for (int i = 0; i < size; ++i) {
            if (!matrix[i][i]) {
                return false;
            }
        }
        return true;
    }

    bool isSymmetric() {
        for (int i = 0; i < size; ++i) {
            for (int j = 0; j < size; ++j) {
                if (matrix[i][j] != matrix[j][i]) {
                    return false;
                }
            }
        }
        return true;
    }

    bool isAntiSymmetric() {
        for (int i = 0; i < size; ++i) {
            for (int j = 0; j < size; ++j) {
                if (i != j && matrix[i][j] && matrix[j][i]) {
                    return false;
                }
            }
        }
        return true;
    }

    bool isTransitive() {
        for (int i = 0; i < size; ++i) {
            for (int j = 0; j < size; ++j) {
                if (matrix[i][j]) {
                    for (int k = 0; k < size; ++k) {
                        if (matrix[j][k] && !matrix[i][k]) {
                            return false;
                        }
                    }
                }
            }
        }
        return true;
    }

    string classifyRelation() {
        bool reflexive = isReflexive();
        bool symmetric = isSymmetric();
        bool antisymmetric = isAntiSymmetric();
        bool transitive = isTransitive();

        if (reflexive && symmetric && transitive) {
            return "Equivalence Relation";
        } else if (reflexive && antisymmetric && transitive) {
            return "Partial Order Relation";
        } else {
            return "None";
        }
    }

    void printMatrix() {
        cout << "Relation Matrix:\n";
        for (int i = 0; i < size; ++i) {
            for (int j = 0; j < size; ++j) {
                cout << matrix[i][j] << " ";
            }
            cout << "\n";
        }
    }
};

int main() {
    int n;
    cout << "Enter the size of the relation matrix: ";
    cin >> n;

    vector<vector<bool>> mat(n, vector<bool>(n));
    cout << "Enter the relation matrix (0 or 1) row-wise:\n";
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            int val;
            cin >> val;
            mat[i][j] = (val != 0);
        }
    }

    RELATION relation(mat);
    relation.printMatrix();

    cout << "Reflexive: " << (relation.isReflexive() ? "Yes" : "No") << endl;
    cout << "Symmetric: " << (relation.isSymmetric() ? "Yes" : "No") << endl;
    cout << "Anti-symmetric: " << (relation.isAntiSymmetric() ? "Yes" : "No") << endl;
    cout << "Transitive: " << (relation.isTransitive() ? "Yes" : "No") << endl;

    cout << "Classification: " << relation.classifyRelation() << endl;

    return 0;
}
