#include <iostream>
#include <tuple>
using namespace std;

    bool test(tuple<int, int, int> expected, tuple<int, int, int> actual) {
        if (expected == actual) {
            cout << "PASSED!" << endl;
            return true;
        }
        else {
            cout << "FAILED! Try some another function" << endl;
            return false;
        }
    }

    tuple<int, int, int> quadratic(double x1, double x2) {
        return {1, -1 * (x1 + x2), x1*x2};
    };

    int main() {
    double x1, x2;
    cout << "********************FIND A B C FOR QUADRATIC EQUATION******************" << endl;
    cout << "Enter x1:";
    cin >> x1;
    cout << "Enter x2:";
    cin >> x2;
        if(test({1, -2, 1}, quadratic(1,1))) cout << "first test works!" << endl;
        if(test({1, 13, 36}, quadratic(-4,-9))) cout << "second test works!" << endl;
        if(test({1, 9, 20}, quadratic(-5,-4))) cout << "third test works!" << endl;
        if(test({1, 5, -36}, quadratic(4,-9))) cout << "fourth test works!" << endl;
    tuple<int, int, int> result = quadratic(x1, x2);
    cout << "A=" << get<0>(result) << " ";
    cout << "B=" << get<1>(result) << " ";
    cout << "C=" << get<2>(result) << " " << endl;
        cout << "***********************************************************************";
    return 0;
}
