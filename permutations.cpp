#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void permuteWithoutRepetition(vector<int>& digits, vector<int>& current, vector<bool>& used) {
    if (current.size() == digits.size()) {
        for (int d : current) {
            cout << d << " ";
        }
        cout << endl;
        return;
    }
    for (int i = 0; i < digits.size(); ++i) {
        if (used[i]) continue;
        used[i] = true;
        current.push_back(digits[i]);
        permuteWithoutRepetition(digits, current, used);
        current.pop_back();
        used[i] = false;
    }
}

void permuteWithRepetition(const vector<int>& digits, vector<int>& current, int length) {
    if (current.size() == length) {
        for (int d : current) {
            cout << d << " ";
        }
        cout << endl;
        return;
    }
    for (int i = 0; i < digits.size(); ++i) {
        current.push_back(digits[i]);
        permuteWithRepetition(digits, current, length);
        current.pop_back();
    }
}

int main() {
    int n, choice, length;
    cout << "Enter number of digits: ";
    cin >> n;
    vector<int> digits(n);
    cout << "Enter the digits:\n";
    for (int i = 0; i < n; ++i) {
        cin >> digits[i];
    }

    cout << "Choose permutation type:\n";
    cout << "1. Without repetition\n";
    cout << "2. With repetition\n";
    cout << "Enter choice: ";
    cin >> choice;

    if (choice == 1) {
        vector<int> current;
        vector<bool> used(n, false);
        cout << "Permutations without repetition:\n";
        permuteWithoutRepetition(digits, current, used);
    } else if (choice == 2) {
        cout << "Enter length of permutations: ";
        cin >> length;
        vector<int> current;
        cout << "Permutations with repetition:\n";
        permuteWithRepetition(digits, current, length);
    } else {
        cout << "Invalid choice.\n";
    }

    return 0;
}
