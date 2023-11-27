#include <iostream>
#include <cmath>
using namespace std;

double resolver(double x, double y) {
    if (x/y == 0) {
        cout << "x/y = 0 variant" << endl;
        return pow(exp(1.0), x-y) + cbrt(x);
    }
    if (-5 < x/y && x/y < 0) {
        cout << "-5 < x/y < 0" << endl;
        return (x * x - log( y * y + x));
    }
        cout << "else variants" << endl;
        return 2* pow(tan(x),2) -y;
    }

int main() {
    double x,y;
    cout << "***************** Resolving lab 2 ******************" << endl;
    cout << "Enter x:";
    cin >> x;
    cout << "Enter y:";
    cin >> y;
    cout << "Answer for " << resolver(x,y) << endl;
    cout << "********************************************************";
    return 0;
}