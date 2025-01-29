#include <iostream>
#include <string>

#include <chrono>

using namespace std::chrono;

high_resolution_clock::time_point startTimer() {
    return high_resolution_clock::now();
}

duration<double> stopTimer(const high_resolution_clock::time_point& startTime) {
    auto endTime = high_resolution_clock::now();
    return duration_cast<duration<double>>(endTime - startTime);
}

using namespace std;

int main(int argc, char const *argv[])
{

    auto startTime = startTimer();

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
                cin.ignore(1000, '\n');
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
                cin.ignore(1000, '\n');
            }
        }
        int numerator = 0, denominator = 1;

        //resert conditon.
        valid_input = false;

        switch (operator_)
        {
        case '+':
            numerator = (f_n * s_d) + (s_n * f_d);
            denominator = s_d * f_d;

            cout << "sum: " << numerator << '/' << denominator << endl;
            break;
        
        case '-':
            numerator = f_n * s_d - s_n * f_d;
            denominator = s_d * f_d;
        
            cout << "Difference: " << numerator << '/' << denominator << endl;
            break;
        case '*':
            numerator = f_n * s_n;
            denominator =f_d * s_d; 

            cout << "Product: " << numerator << '/' << denominator << endl;
            break;
        case '/':
            numerator = f_n * s_d;
            denominator =f_d * s_n; 

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
                cin.ignore(100000,'\n');

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
                cin.ignore(100000);
            }
            } while (true);
        
        
        
        
    } while (repetition);
    auto elapsed = stopTimer(startTime);

    cout << "Process exited after " << elapsed.count() << "second" << endl;
    return 0;
}