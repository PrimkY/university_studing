#include <iostream>
using namespace std;

int main() {
    int size;
    cout << "Enter array size: ";
    cin >> size;

    double* arr = new double[size];

    cout << "Enter elements of array: " << endl;
    for (int i = 0; i < size; ++i) {
        cout << "Element " << i + 1 << ": ";
        cin >> arr[i];
    }

    int maxIndex = 0;
    for (int i = 0; i < size; ++i) {
        if (arr[i] > arr[maxIndex]) {
            maxIndex = i;
        }
    }
    double first = arr[maxIndex];
    for (int i = maxIndex; i > 0; --i) {
        arr[i] = arr[i-1];
    }
    arr[0]  = first;

    int minIndex = 0;
    for (int i = 0; i < size; ++i) {
        if (arr[i] < arr[minIndex]) {
            minIndex = i;
        }
    }
    double last = arr[minIndex];
    for (int i = minIndex; i < size-1; ++i) {
        arr[i] = arr[i+1];
    }
    arr[size-1] = last;

    cout << "Result:\n";
    for (int i = 0; i < size; ++i) {
        cout << arr[i] << " ";
    }

    delete[] arr;

    return 0;
}
