#include <iostream>
#include <string>

#include <cmath>

using namespace std;

int main()
{   
    cout << "Quadratic equation solver:" << endl;
    float a, b, c;
    char y_or_n;
    bool repetition;
    bool valid_input = false;

    do
    {
        //determinie a
        while (!valid_input)
        {   
            cout << "Enter a: ";
            if (cin >> a && !(a == 0))
            {
                valid_input = true;
            }else if (a = 0) //error XD
            {
                cout << "Invalid input. a can not be 0 \n" <<
                "Please enter non-zero number 'a' (ex. 4.2)\n";
                cin.clear();
                cin.ignore(1000, '\n');
            }else
            {
                cout << "Invalid input.\n" <<
                "Please enter number (ex. 4.2)\n";
                cin.clear();
                cin.ignore(1000, '\n');
            }
            
            
        }
        valid_input = false;

        //determinie b
        while (!valid_input)
        {   
            cout << "Enter b: ";
            if (cin >> b){
                valid_input = true;
            }else
            {
                cout << "Invalid input.\n" <<
                "Please enter number (ex. 4.2)\n";
                cin.clear();
                cin.ignore(1000, '\n');
            }
            
        }
        valid_input = false;

        //determinie c
        while (!valid_input)
        {   
            cout << "Enter c: ";
            if (cin >> c){
                valid_input = true;
            }else
            {
                cout << "Invalid input.\n" <<
                "Please enter number (ex. 4.2)\n";
                cin.clear();
                cin.ignore(1000, '\n');
            }
            
        }
        valid_input = false;

        // calculatung 
        float first_root, second_root, discriminant;

        discriminant = (b*b - 4*a*c);

        first_root  = (-b + sqrt(b*b - 4.0*a*c))/(2.0*a);
        second_root = (-b - sqrt(b*b - 4.0*a*c))/(2.0*a);

        if(discriminant > 0)
        {
            cout << "There are two real solutions: " 
            << first_root << " and " << second_root << endl;
        }

        if (discriminant == 0)
        {
            cout << "There is one real solution: " 
            << first_root << endl;
        }
        
        if (discriminant < 0)
        {
            cout << "There are two complex solutions: " 
            << -b/(2*a) << "+" << sqrt(fabs(b*b-4*a*c))/(2*a) << "i and "
            << -b/(2*a) << "-" << sqrt(fabs(b*b-4*a*c))/(2*a) << "i\n";
        }
        

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
                cin.ignore(100000,'\n');
            }
        } while(true);
    
    } while (repetition);
    
}