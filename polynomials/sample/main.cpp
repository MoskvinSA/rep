#include "polynomial.h"
#include <list>

int main()
{
    cout << "enter polinomial f1: ";
    string str1;
    getline(cin, str1);

    cout << "enter polinomial f2: ";
    string str2;
    getline(cin,str2);

    Polynom f1(str1);
    Polynom f2(str2), f3, f4, f5;

    cout << "f1 = " << f1 << endl;
    cout << "f2 = " << f2 << endl;

    cout << "result f1(1, 1, 1) = " << f1.calculate_result(1, 1, 1) << endl;
    cout << endl;

    f3 = f1 + f2;
    f4 = f1 - f2;
    f5 = f1 * f2;

    cout << "f3 = f1 + f2 = " << f3 << endl;
    cout << "f4 = f1 - f2 = " << f4 << endl;
    cout << "f5 = f1 * f2 = " << f5 << endl;

    return 0;
}