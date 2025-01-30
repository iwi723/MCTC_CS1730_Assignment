#include <iostream>
#include <string>
using namespace std;

int main()
{ 
    int old_pound_1, old_shilling_1, old_pence_1;
    int old_pound_2, old_shilling_2, old_pence_2;
    int decimal_pound, decimal_pences = 0;
    char dot = '.';

    int total_old_pence, total_new_pence;

    //initilaize first set of old-pound
    cout << "Enter first old-pound amount: ";
    cin >> old_pound_1 >> dot >> old_shilling_1 >> dot >> old_pence_1;

    //initilaize second set of old-pound
    cout << "Enter second old-pound amount: ";
    cin >> old_pound_2 >> dot >> old_shilling_2 >> dot >> old_pence_2;

    // Convert to pence (Old pounds to old pence)
    total_old_pence = (old_pound_1+old_pound_2) * 240 
    + (old_shilling_1+old_shilling_2) * 12 
    + old_pence_1 + old_pence_2;

    total_new_pence  = total_old_pence * 100 / 240;

    //indicate total old pound
    cout << "Old-pound total = " << total_old_pence/240
    << dot << total_old_pence%240/12
    << dot << total_old_pence%240%12;

    //indicate total decimal pound
    cout << "\nDecimal-pound total = " << total_new_pence / 100 << dot 
    << total_new_pence % 100 << endl;

    cout << "Press Enter To EXIT......" << endl;
    cin.ignore(100);
    cin.get();
    return 0;

}