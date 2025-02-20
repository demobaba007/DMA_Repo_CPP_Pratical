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
        cout << "Displaying SET : \n\n" << "{ ";
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
        return new_array;
    }

    // Perform Is member function
    bool Is_member(int Input_num, int *arrC, int len_C) {
        bool flag;
        for (int i = 0; i < len_C; i++){
            if (arrC[i] == Input_num){
                flag = 1;
                break;
            }else {
                flag = 0;
                continue;
            }
        }
        return flag;
    }

    // Perform Union function
    void Union(int *arrA, int len_A, int *arrB, int len_B){
        vector<int> new_array3;
        int i = 0;
        new_array3.push_back(arrA[i]);
        for (int i = 1; i < len_A; i++){
            auto it = find(new_array3.begin(), new_array3.end(), arrA[i]);
            if (it != new_array3.end()){
                continue;
            }else{
                new_array3.push_back(arrA[i]);
            }
        }
        for (int j = 0; j < len_B; j++){
            auto it = find(new_array3.begin(), new_array3.end(), arrB[j]);
            if (it != new_array3.end()){
                continue;
            }else{
                new_array3.push_back(arrB[j]);
            }
        }
        int len_C = new_array3.size();
        cout << "Displaying Union of sets : \n\n" << "{ ";
        for (i = 0; i < len_C; i++)
        cout << new_array3[i] << " ";
        cout << "}\n";
        cout <<endl;
        
    }
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
    cout << "1. Output function \t\t\t 2. Unique function\n\n3. Is-member function \t\t\t 4. Union function\n\n5. Intersection function \t\t\t 6. \n\n";
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
            // Cardinality of set
            cout << "Cardinality of Set : " << new_array1.size() << endl;
            for (int i = 0;i < 70; i++) cout << "_ "; cout << "\n\n";
            vector<int> new_array2 = obj.Unique(arrB, len_B);
            // Cardinality of set
            cout << "Cardinality of Set : " << new_array2.size() << endl;
            for (int i = 0;i < 70; i++) cout << "_ "; cout << "\n\n";
            break;

            // Perform Is Member function
        }else if (user_input == 3){
            for (int i = 0;i < 70; i++) cout << "_ "; cout << "\n\n";
            int Input_num;
            cout << "Please enter the number you want to search : ";
            cin >> Input_num;
            int result = obj.Is_member(Input_num, arrA, len_A);
            if (result == 1){
                cout << Input_num << " is belongs to set\n";
            }else{
                cout << Input_num << " is not belongs to set\n";
            }
            for (int i = 0;i < 70; i++) cout << "_ "; cout << "\n\n";
            break;

            // Perform Union function
        }else if (user_input == 4){
            for (int i = 0;i < 70; i++) cout << "_ "; cout << "\n\n";
            obj.Union(arrA, len_A, arrB, len_B);
            for (int i = 0;i < 70; i++) cout << "_ "; cout << "\n\n";
            break;
        }

    }



    return 0;
}