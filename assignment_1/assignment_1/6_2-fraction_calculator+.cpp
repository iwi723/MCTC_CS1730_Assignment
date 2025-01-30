#include <iostream>
#include <string>

#include <limits>

using namespace std;

int GCD(int i, int j);
void simplify(int&, int&);

int main(int argc, char const *argv[])
{
    // f = first, s = second, d = denominator, n = numerator
    int f_d, s_d, f_n, s_n;
    char operator_;
    bool repetition = true;
    bool valid_input;
    char y_or_n;

    char slash;

    do
    {
        // Get first fraction
        while (!valid_input)
        {
            cout << "Enter first fraction (ex. 1/2): ";
            if (cin >> f_n >> slash >> f_d && slash == '/' && f_d != 0){
                valid_input = true;
            }else
            {
                cout << "Invalid input. Please enter a valid fraction\n" <<
                "(e.g., 1/2) with a non-zero denominator.\n";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
        }

        //get operator.
        cout << "Enter an operator (+, -, *, /): ";
        cin >> operator_;


        //resert conditon.
        valid_input = false;

        //get second fraction.
        while (!valid_input)
        {
            cout << "Enter second fraction (ex. 4/2): ";
            if (cin >> s_n >> slash >> s_d && slash == '/' && s_d != 0){
                valid_input = true;
            }else
            {
                cout << "Invalid input. Please enter a valid fraction\n" <<
                "(e.g., 1/2) with a non-zero denominator.\n";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
        }
        int numerator = 0, denominator = 1;


        int gcd;

        //resert conditon.
        valid_input = false;
        
        switch (operator_)
        {
        case '+':
            numerator = (f_n * s_d) + (s_n * f_d);
            denominator = s_d * f_d;
            simplify(numerator, denominator);

            cout << "sum: " << numerator << '/' << denominator << endl;
            break;
        
        case '-':
            numerator = f_n * s_d - s_n * f_d;
            denominator = s_d * f_d;
            simplify(numerator, denominator);
        
            cout << "Difference: " << numerator << '/' << denominator << endl;
            break;
        case '*':
            numerator = f_n * s_n;
            denominator =f_d * s_d;
            simplify(numerator, denominator);

            cout << "Product: " << numerator << '/' << denominator << endl;
            break;
        case '/':
            numerator = f_n * s_d;
            denominator =f_d * s_n; 
            simplify(numerator, denominator);

            cout << "division: " << numerator << '/' << denominator << endl;
            break;

        default:
            break;
        }


        //control the calculator repetition
        do
        {
            //Continue module starts
            cout << "Continue (y or n)? ";
            cin >> y_or_n;

            if (cin.fail())
            {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');

            }else if(y_or_n == 'y')
            {
                repetition = true;
                break;

            }else if(y_or_n == 'n')
            {
                repetition = false;
                break;

            }else if (y_or_n != 'y' && y_or_n != 'n')
            {
                cout << "\nplease enter \"y\" or \"n\"";
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
            } while (true);
        
        
        
        
    } while (repetition);

    return 0;
}

int GCD(int i, int j)
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

void simplify(int& numerator, int& denominator)
{
    int gcd = GCD(numerator, denominator);
    numerator   /= gcd;
    denominator /= gcd;
}
