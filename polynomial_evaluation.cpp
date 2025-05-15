#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int evaluatePolynomial(const vector<int>& coeffs, int n) {
    int result = 0;
    int degree = coeffs.size() - 1;
    for (int i = 0; i <= degree; ++i) {
        result += coeffs[i] * pow(n, i);
    }
    return result;
}

int main() {
    int degree, n;
    cout << "Enter degree of polynomial: ";
    cin >> degree;

    vector<int> coeffs(degree + 1);
    cout << "Enter coefficients from constant term to highest degree term:\n";
    for (int i = 0; i <= degree; ++i) {
        cin >> coeffs[i];
    }

    cout << "Enter value of n: ";
    cin >> n;

    int value = evaluatePolynomial(coeffs, n);
    cout << "Value of polynomial at n = " << n << " is: " << value << endl;

    return 0;
}
