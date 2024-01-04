#include <iostream>
using namespace std;

int countOnes(const string& str) {
    int groups = 0;
    int counterForOnes = 0;

    for (char ch: str) {
        if (ch != '0' && ch != '1') {cout << "[Error] Sting must contain only 1 or 0" << endl; return 0;}
        if (ch == '1') {
            counterForOnes++;
            if (counterForOnes == 5) {
                groups++;
            } else if (counterForOnes > 5) {
                groups--;
            }
        } else {
            counterForOnes = 0;
        }
    }
    cout << "Number of groups of ones is: " << groups << endl;
    return groups;
}

int main() {
    cout << "************************* Lab 7 var 7 **************************" << endl;
    string inputString;
    cout << "Enter sting that's consist of 1 or 0: " << endl;
    cin >> inputString;
    countOnes(inputString);
    cout << "****************************************************************" << endl;
    return 0;
}
