#include <iostream>
#include <cmath>
using namespace std;

double resolver(double x, double y, double function) {
    if (x + abs(y) == 0) {
        cout << "x + |y| = 0 variant is: " ;
        return pow(sin(x), 2) - function;
    }
    if (x + abs(y) < 0) {
        cout << "x + |y| < 0 variant is: ";
        return cbrt(abs(x * y));
    }
    cout << "else variants is : ";
    return 3 * pow(function, 2);
}

int main() {
    double x,y, function;
    int variant;
    cout << "***************** Resolving lab 2 ******************" << endl;
    cout << "Enter x:";
    cin >> x;
    cout << "Enter y:";
    cin >> y;
    cout << "Choose f(x):" << endl;
    cout << "sh(x): 1" << endl;
    cout << "x^2: 2" << endl;
    cout << "e^x: 3" << endl;
    cin >> variant;
    switch (variant) {
      case 1:
          function = sinh(x);
          break;
      case 2:
          function = x * x;
          break;
      case 3:
          function = exp(x);
          break;
      default:
          function = x;
          cout << "Invalid choice. Please enter a number between 1 and 3. Or f(x) = x" << endl;
    }
    cout << "Answer for " << resolver(x,y, function) << endl;
    cout << "********************************************************";
    return 0;
}