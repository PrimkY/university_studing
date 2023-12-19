#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

double calculateY(double &x) {
    return cos(sin(x));
}

double calculateSx(double &x, double &e) {
    double result = 1, result_sum=1;
    for (int j = 1; abs(result) > e ; j++) {
        result *= -1 * sin(x) * sin(x) / (2 * j * (2 * j - 1)) ;
        result_sum += result;
    }
    return result_sum;
}

int main() {
    cout << "************************* Lab 6 var 7 **************************" << endl;
    double a = -0.5;
    double b = 0.5;
    double e = 1e-4;
    double h = (b-a) / 10;
    cout << "x" << setw(9) << "\t\t" << setw(9) << "y(x)" << "\t\t" << setw(9) << "s(x, e)" <<"\n";

    for (double x = a; x <= b; x += h) {
        if (x < e && x > -e) { x = 0;}
        cout << x << setw(9) << "\t\t" << setw(9) << calculateY(x) << "\t\t" << setw(9) << calculateSx(x,e) <<"\n";
    }
    cout << "****************************************************************" << endl;
    return 0;
}


