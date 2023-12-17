#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

double calculateY(double x);
double calculateValues(double x, double* yResult, double* sResult, double e);
int factorial(int n);

int main() {
    double a = -0.9;
    double b = 0.9;
    double e = 1e-3;
    double h = (b - a) / 10.0;
    cout << "x" << setw(9) << "\t\t" << setw(9) << "y(x)" << "\t\t" << setw(9) << "s(x, e)" <<"\n";

    for (double x = a; x <= b; x += h) {
        if (x < 0.0001 && x > -0.0001) { x = 0;}
        double yResult, sResult;
        calculateValues(x, &yResult, &sResult, e);
        cout << x << setw(9) << "\t\t" << setw(9) << yResult << "\t\t" << setw(9) << sResult <<"\n";
    }
    return 0;
}

double calculateY(double x) {
    return cos(x - 4);
}

double calculateValues(double x, double* yResult, double* sResult, double e) {
    *yResult = calculateY(x);

    *sResult = 0.0;
    double term = 1.0;
    int n = 0;

    while (fabs(term) > e) {
        *sResult += term;
        n++;
        if (n > 5) {
            term = pow(-1, n) * pow(x - 4, 2 * n) / factorial(12);
        } else {
            term = pow(-1, n) * pow(x - 4, 2 * n) / factorial(2 * n);
        }
    }
    return term;
}

int factorial(int n) {
    int result = 1;
    for (int i = 2; i <= n; ++i) {
        result *= i;
    }
    return result;
}

