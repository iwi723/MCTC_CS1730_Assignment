#include <iostream>
#include <limits>

#include <cmath>

using namespace std;

int gcd(int, int);
bool is_valid_input(int);

int main()
{
    cout << "Welcome to GCD finder!" << endl;
    cout << "Please Insert Two positive integer" << endl;

    int a, b;
    bool valid_input = false;

    do
    {
        cout << "\nInsert first number: ";
        cin >> a;
    } while (!is_valid_input(a));

    valid_input = false;
    do
    {
        cout << "\nInsert second number: "<< endl;
        cin >> b;
    } while (!is_valid_input(b));

    cout << "\nall value are correctly assigned." << endl;
    cout << "Greatest Common Divisor of two number is: " <<gcd (a, b) << endl;

    return 0;
}

int gcd(int i, int j)
{
    int gcd;
    if(j > i) //make i to be allways bigger.
    {
        swap(i ,j);
    }


    while (j != 0)
    {
        int temp = i % j;   // remainder to store temporarily
        i = j;              // set i to the j
        j = temp; 
    }
    return i;
}

bool is_valid_input(int number)
{
    if (cin.fail() || number <= 0)
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            return false;
        }else
        {
            return true;
        }
}