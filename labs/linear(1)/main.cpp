#include <iostream>
#include <cmath>
using namespace std;

double resolver(double x, double y, double z) {
      return (sqrt(10 * ((cbrt(x) + pow(x, y+2)))) * (pow(asin(z),2) - abs(x - y)));
    }

int main() {
    double x,y,z;
    cout << "*****************Resolving my linear with yours x-y-z******************" << endl;
    cout << "Enter x:";
    cin >> x;
    cout << "Enter y:";
    cin >> y;
    cout << "Enter z:";
    cin >> z;
    double s = -40.6307;

    cout << "S =" << resolver(x,y,z) << endl << "expected S =" << s << endl;
    cout << "***********************************************************************";
    return 0;
}
