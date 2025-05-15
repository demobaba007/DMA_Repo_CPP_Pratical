#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class SET {
private:
    vector<int> elements;

    bool contains(const vector<int>& vec, int val) const {
        for (int e : vec) {
            if (e == val) return true;
        }
        return false;
    }

public:
    SET(const vector<int>& elems) {
        for (int e : elems) {
            if (!contains(elements, e)) {
                elements.push_back(e);
            }
        }
    }

    bool ismember(int element) const {
        return contains(elements, element);
    }

    vector<vector<int>> powerset() const {
        vector<vector<int>> result;
        int n = elements.size();
        int power_set_size = 1 << n;

        for (int counter = 0; counter < power_set_size; ++counter) {
            vector<int> subset;
            for (int j = 0; j < n; ++j) {
                if (counter & (1 << j)) {
                    subset.push_back(elements[j]);
                }
            }
            result.push_back(subset);
        }
        return result;
    }

    bool subset(const SET& other) const {
        for (int e : elements) {
            if (!other.ismember(e)) {
                return false;
            }
        }
        return true;
    }

    vector<int> set_union(const SET& other) const {
        vector<int> result = elements;
        for (int e : other.elements) {
            if (!contains(result, e)) {
                result.push_back(e);
            }
        }
        return result;
    }

    vector<int> intersection(const SET& other) const {
        vector<int> result;
        for (int e : elements) {
            if (other.ismember(e)) {
                result.push_back(e);
            }
        }
        return result;
    }

    vector<int> complement(const vector<int>& universal_set) const {
        vector<int> result;
        for (int e : universal_set) {
            if (!ismember(e)) {
                result.push_back(e);
            }
        }
        return result;
    }

    vector<int> set_difference(const SET& other) const {
        vector<int> result;
        for (int e : elements) {
            if (!other.ismember(e)) {
                result.push_back(e);
            }
        }
        return result;
    }

    vector<int> symmetric_difference(const SET& other) const {
        vector<int> result;
        for (int e : elements) {
            if (!other.ismember(e)) {
                result.push_back(e);
            }
        }
        for (int e : other.elements) {
            if (!ismember(e)) {
                result.push_back(e);
            }
        }
        return result;
    }

    vector<pair<int, int>> cartesian_product(const SET& other) const {
        vector<pair<int, int>> result;
        for (int a : elements) {
            for (int b : other.elements) {
                result.push_back(make_pair(a, b));
            }
        }
        return result;
    }

    void print_vector(const vector<int>& vec) const {
        cout << "{ ";
        for (int e : vec) {
            cout << e << " ";
        }
        cout << "}";
    }

    void print_cartesian_product(const vector<pair<int, int>>& vec) const {
        cout << "{ ";
        for (auto p : vec) {
            cout << "(" << p.first << "," << p.second << ") ";
        }
        cout << "}";
    }
};

int main() {
    vector<int> elemsA, elemsB, universalSet;
    int n, choice, element;
    cout << "Enter number of elements in Set A: ";
    cin >> n;
    cout << "Enter elements of Set A:\n";
    for (int i = 0; i < n; ++i) {
        cin >> element;
        elemsA.push_back(element);
    }

    cout << "Enter number of elements in Set B: ";
    cin >> n;
    cout << "Enter elements of Set B:\n";
    for (int i = 0; i < n; ++i) {
        cin >> element;
        elemsB.push_back(element);
    }

    cout << "Enter number of elements in Universal Set: ";
    cin >> n;
    cout << "Enter elements of Universal Set:\n";
    for (int i = 0; i < n; ++i) {
        cin >> element;
        universalSet.push_back(element);
    }

    SET A(elemsA);
    SET B(elemsB);

    do {
        cout << "\nMenu:\n";
        cout << "1. Check if element is in Set A\n";
        cout << "2. Power set of Set A\n";
        cout << "3. Check if Set A is subset of Set B\n";
        cout << "4. Union of Set A and Set B\n";
        cout << "5. Intersection of Set A and Set B\n";
        cout << "6. Complement of Set A with respect to Universal Set\n";
        cout << "7. Set difference A - B\n";
        cout << "8. Symmetric difference of Set A and Set B\n";
        cout << "9. Cartesian product of Set A and Set B\n";
        cout << "10. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter element to check: ";
                cin >> element;
                cout << (A.ismember(element) ? "Element is in Set A\n" : "Element is not in Set A\n");
                break;
            case 2: {
                cout << "Power set of Set A:\n";
                vector<vector<int>> pset = A.powerset();
                for (auto& subset : pset) {
                    cout << "{ ";
                    for (int e : subset) {
                        cout << e << " ";
                    }
                    cout << "}\n";
                }
                break;
            }
            case 3:
                cout << (A.subset(B) ? "Set A is a subset of Set B\n" : "Set A is not a subset of Set B\n");
                break;
            case 4:
                cout << "Union of Set A and Set B: ";
                A.print_vector(A.set_union(B));
                cout << endl;
                break;
            case 5:
                cout << "Intersection of Set A and Set B: ";
                A.print_vector(A.intersection(B));
                cout << endl;
                break;
            case 6:
                cout << "Complement of Set A with respect to Universal Set: ";
                A.print_vector(A.complement(universalSet));
                cout << endl;
                break;
            case 7:
                cout << "Set difference A - B: ";
                A.print_vector(A.set_difference(B));
                cout << endl;
                break;
            case 8:
                cout << "Symmetric difference of Set A and Set B: ";
                A.print_vector(A.symmetric_difference(B));
                cout << endl;
                break;
            case 9:
                cout << "Cartesian product of Set A and Set B: ";
                A.print_cartesian_product(A.cartesian_product(B));
                cout << endl;
                break;
            case 10:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 10);

    return 0;
}
