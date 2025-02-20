#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class SET {
    private:
    int i, j;
    public:

    // Takes array and its lenght as parameter and returns normal set
    void Output(int *arrC, int len_C){
        cout << "Displaying SET : \n" << "{ ";
        for (i = 0; i < len_C; i++)
        cout << arrC[i] << " ";
        cout << "}\n";
    }

    // Unique function that remove all duplicate values and update the cardinality of set
    vector<int> Unique(int *arrC, int len_C){
        vector<int> new_array;
        int i = 0;
        new_array.push_back(arrC[i]);
        for (int i = 1; i < len_C; i++){
            auto it = find(new_array.begin(), new_array.end(), arrC[i]);
            if (it != new_array.end()){
                continue;
            }else{
                new_array.push_back(arrC[i]);
            }
        }
        // Display unique set
        cout << "Unique set : \n" << "{ ";
        for (int i = 0; i < new_array.size(); i++){
        cout << new_array[i] << " ";
    }
    cout << "}\n";

        // Cardinality of set
        cout << "Cardinality of Set : " << new_array.size() << endl;
        return new_array;
    }

    // Perform Is member function
};

int main() {
    // Initializing variables
    int i, len_A, len_B;
    cout << "Enter the lenght of SET A : ";

    cin >> len_A;
    // Initializing array
    int arrA[len_A];
    for (i = 0; i < len_A; i++){
    cout << "Enter the element : ";
    cin >> arrA[i];}

    cout << "Enter the lenght of SET B : ";
    cin >> len_B;

    // Initializing array
    int arrB[len_B];
    for (i = 0; i < len_B; i++){
    cout << "Enter the element : ";
    cin >> arrB[i];}

    // Declearing the object
    SET obj;
    for (int i = 0;i < 70; i++) cout << "_ ";
    cout << "\nWhat function do you want to perform in set : \n\n";
    cout << "1. Output function \t\t\t 2. Unique function\n\n3. \n\n";
    for (int i = 0; i < 70; i++) cout << "_ ";

    int user_input;
    cout << "\nPlease enter number whose function you want to perform : ";
    cin >> user_input;
    while (true) {
        if (user_input <= 0){
            cout << "\nPlease enter greater number given above : ";
            break;

            // Perform Output function 
        }else if (user_input == 1){
            for (int i = 0;i < 70; i++) cout << "_ "; cout << "\n\n";
            obj.Output(arrA, len_A);
            for (int i = 0;i < 70; i++) cout << "_ "; cout << "\n\n";
            obj.Output(arrB, len_B);
            for (int i = 0;i < 70; i++) cout << "_ "; cout << "\n\n";
            break;

            // Perform Unique function
        }else if (user_input == 2){
            for (int i = 0;i < 70; i++) cout << "_ "; cout << "\n\n";
            vector<int> new_array1 = obj.Unique(arrA, len_A);
            for (int i = 0;i < 70; i++) cout << "_ "; cout << "\n\n";
            vector<int> new_array2 = obj.Unique(arrB, len_B);
            for (int i = 0;i < 70; i++) cout << "_ "; cout << "\n\n";
        }
    }



    return 0;
}