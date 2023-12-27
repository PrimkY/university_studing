#include <iostream>
#include <vector>
#include <algorithm>
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

bool compare(int a, int b) {return (a>b);}

int sumOfDifferences(vector<int>) {

};

int main() {
    int size, elem;
    cout << "Enter size of the array:";
    cin >> size;
    int array[30] = {};
    for (int i = 0; i < size; i++) {
        cout << "Enter " << i + 1 << " element of array"<< endl;
        cin >> elem;
        array[i] = elem;
    }
    vector<int> sort_int_vector(array,array+30);
    sort(sort_int_vector.begin(), sort_int_vector.end(), compare);
    return 0;
}
