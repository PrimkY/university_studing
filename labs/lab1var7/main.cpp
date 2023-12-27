#include <iostream>
#include <cmath>
using namespace std;

double resolver(double x, double y, double z) {
    double first = 5 * atan(x);
    double second = 0.25 * acos(x);
    double third = x + 3 * abs(x-y) + x * x ;
    double forth = abs(x-y) * z + x * x;
    return first - second * third / forth;
}

int main() {
    double x,y,z;
    cout << "***********************************************************************" << endl;
    x = 0.1722;
    y = 6.33;
    z = 3.25e-4;
    double s = -205.306;

    cout << "S =" << resolver(x,y,z) << endl << "expected S =" << s << endl;
    cout << "***********************************************************************" << endl;    system("pause");
    return 0;
}