#include <iostream>
#include <string>

#include <math.h>

using namespace std;

double approximator(double n, double approx);

int main(/*int arg , char const *argv[]*/) /*used while compile(we dont needit now)*/
{
    bool valid_input = false;
    double n, approx;

    valid_input = false;
    do
    {
        cout << "Enter n: ";
        cin >> n;

        if (n < 0)
        {
            cout << "\nn Should be greather then 0.";
        }else if(cin.fail())
        {
            cout << "\nn Should be number.";
            cin.clear();
            cin.ignore(1000, '\n');
        }else
        {
            valid_input = true;
        }
        
    } while (!valid_input);


    valid_input = false;
    do
    {
        cout << "Enter first approximation: ";
        cin >> approx;

        if (approx < 0)
        {
            cout << "\napproximation Should be greater then 0.";
        }else if(cin.fail())
        {
            cout << "\napproximation Should be number.";
            cin.clear();
            cin.ignore(1000, '\n');
        }else
        {
            valid_input = true;
        }
    } while (!valid_input);
    cout << "All value correctly asinged!" << endl;
    cout << "start calculating......" << endl;

    approximator(n, approx);

    return 0;
}


double approximator(double n, double approx)
{
    double diff = 1.0;
    while (diff > 0.00001)
    {
        diff = (fabs(approx - sqrt(n)) / sqrt(n)) * 100;
        cout << "current aproximation: " << approx << '\n';
        cout << "current diffrence percentage: " << diff << '\n';
        approx = (approx + n / approx) / 2.0;
    }

    cout << "final aproximation        : " << approx << '\n';
    cout << "final diffrence percentage: " << diff << '\n';
    
    return approx;
}