#include <iostream>
using namespace std;

int countOnes(const char* str) {
    int groups = 0;
    int counterForOnes = 0;

    for (int i = 0; str[i] != '\0'; ++i) {
        if (str[i] == '1') {
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
    char str[40];
    cout << "Enter sting that's consist of 1 or 0: " << endl;
    gets(str);
    countOnes(str);
    cout << "****************************************************************" << endl;
    return 0;
}
