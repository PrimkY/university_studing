#include <iostream>
#include <cmath>
#include <iomanip>
using namespace ::std;

int factorial(int n) {
    if (n == 0 || n == 1) {
        return 1;
    } else {
        return n * factorial(n-1);
    }
}

double resolver(double x, int n) {
    double result = 0.0;
    for (int i = 0; i < n; ++i) {
        if (i < 12) {
            result += (pow(x, 2 * i + 1) / factorial(2 * i + 1));
        } else {
            result += (pow(x, 2 * i + 1) / factorial(12));
        }
    }
    return result;
}



int main() {
    double a = 0.1;
    double b = 1;
    int k = 80;
    double h = (b-a)/10;
    cout << "x" << "\t\t" << setw(9) << "s(x)" << "\t\t" << setw(9) << "y(x)\n";

    for (double x = a; x <= b; x += h) {
        double y = sinh(x);
        double s = resolver(x,k);

        cout << x << "\t\t" << setw(9) << s << "\t\t" << setw(9) << y << "\n";
    }

    return 0;
}
