#include <iostream>
#include <vector>

using namespace std;

void findSolutions(int n, int C, vector<int>& solution, int index, int current_sum) {
    if (index == n) {
        if (current_sum == C) {
            for (int i = 0; i < n; ++i) {
                cout << solution[i] << (i == n-1 ? "\n" : " ");
            }
        }
        return;
    }

    for (int val = 0; val <= C - current_sum; ++val) {
        solution[index] = val;
        findSolutions(n, C, solution, index + 1, current_sum + val);
    }
}

int main() {
    int n, C;
    cout << "Enter number of variables (n): ";
    cin >> n;
    cout << "Enter constant C (<= 10): ";
    cin >> C;

    if (C > 10) {
        cout << "C should be less than or equal to 10.\n";
        return 1;
    }

    vector<int> solution(n, 0);
    cout << "Solutions to x1 + x2 + ... + x" << n << " = " << C << ":\n";
    findSolutions(n, C, solution, 0, 0);

    return 0;
}
