#include <iostream>
#include <cmath>
#include <iomanip>
using namespace ::std;


double resolver(double x, int k) {
    double result = 1, result_sum = 1;

    for (int i = 1; i < k + 1; i++) {
        result *= -2 * exp(x) / i;
        //cout << "this is result: " << result << "this is i: "<< i <<endl;
        result_sum += result;
    }
    return result_sum;
}



int main() {
    double a = 0.1;
    double b = 1;
    int k = 120;
    double h = (b-a)/10;
    cout << "x" << "\t\t" << setw(9) << "s(x)" << "\t\t" << setw(9) << "y(x)\n";

    for (double x = a; x <= b; x += h) {
        double y = exp(-2 * exp(x));
        double s = resolver(x,k);

        cout << x << "\t\t" << setw(9) << s << "\t\t" << setw(9) << y << "\n";
    }

    return 0;
}