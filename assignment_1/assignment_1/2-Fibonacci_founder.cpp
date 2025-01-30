// MinHu Kim
// 1/25/2025

// Instructor name here
//class code here

#include <iostream>
#include <string>
#include <limits>

using namespace std;

int main()
{
    //wht not add elips timer

    //condition for continew
    bool exit_condition = false;
    char yOrNo = 'y';
    int n;

    do{// control the program repetition for finding more Fibonacci numbers.
        
        do{ //ensure that the user enters a positive value for n.
            cout << "Enter a positive integer n: ";
            cin >> n;

            //when invalid input is given, reset cin to further operation.
            if(cin.fail()){
                cout << "Invalid input! Please enter a positive integer.\n";
                cin.clear(); // Clear error mesage
                cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignores up to the newline character
                
                n = 0;
                exit_condition = true; // Set flag to true to continue input loop
            }
            else if (n <= 0) { // Ensure n is positive
                cout << "Invalid input! Please enter a positive integer.\n";
                exit_condition = true;
            }
            else {
                cout << "Valid input, conteue to calculation...\n";
                exit_condition = false; // Valid input, exit the loop
            }

        }while (exit_condition);

        cout << "Starting calculation..." << endl;

        // Using unsigned long long (ULL) for larger Fibonacci numbers.
        unsigned long long a = 0, b = 1; 

        for (int i = 0; i < n; i++) {
            a += b;
            if (i == n - 1) {
                cout << n << "th Fibonacci number: " << a << endl;
                break;
            }
            swap(a, b);
        }
            //calculation timer over
            
        // while loop for continue question.
        while (true){
            cout << "Continue (y or n)? ";
            cin >> yOrNo;
            if (cin.fail()){
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "\nInvalid input! Please enter y or n." << endl;
            }
            else if(yOrNo != 'y' && yOrNo != 'n'){
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "\nInvalid input! Please enter y or n." << endl;
            }
            else if(yOrNo == 'y'){
                break;;
            }
            else if (yOrNo == 'n')
            {
                break;
            }
        }// while loop for continue question.

    }while (yOrNo != 'n');

     cout << "Thank you for using the Fibonacci calculator!" << endl;
    //elips tilmer ends
    
    //print totla time spend.
    //print time take to calculate.
    return 0;

    

}

