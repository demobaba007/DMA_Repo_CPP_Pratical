#include <iostream>
#include <set>
using namespace std;

class sete {
    public:
    set<int> arrays = {1, 2, 3, 3, 3, 4, 5, 5, 5, 5, 6, 7, 8};

    void output() {
        for (int array : arrays) {
            cout << array << " ";
        }
        cout << "\n";
        cout << "Cardinality of set - array\n";
        cout <<"n(array) = " << arrays.size();
    }
};



int main() {
    sete object;
    cout << "Printing unique array" << "\n";
    object.output();
    return 0;
}