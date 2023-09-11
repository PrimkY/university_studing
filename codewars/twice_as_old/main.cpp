#include <iostream>
#include <cmath>
using namespace std;

bool test(int expected, int actual) {
    if (expected == actual) {
        cout << "PASSED!" << endl;
        return true;
    }
    else {
        cout << "FAILED! Try some another function" << endl;
        return false;
    }
}

int twice_as_old(int dad, int son) {
    int result = abs(dad - son * 2);

    return result;
};

int main() {
    cout << "**********HOW FAR DADS AGE FROM SONS TWICE AGE********************" << endl;
    int son, dad;
    cout << "Enter dads age:";
    cin >> dad;
    cout << "Enter sons age:";
    cin >> son;
    if(test(22, twice_as_old(36, 7))) cout << "first test works!" << endl;
    if(test(5, twice_as_old(55, 30))) cout << "second test works!" << endl;
    if(test(0, twice_as_old(42,21))) cout << "third test works!" << endl;
    if(test(29, twice_as_old(29,0))) cout << "fourth test works!" << endl;
    cout << "Answer is " <<twice_as_old(dad, son) << " years" << endl;
    cout << "*******************************************************************" << endl;
    return 0;
}
