#include <iostream>
#include <unordered_map>

using namespace std;

int main() {
    cout << "Enter array size: ";
    int size;
    cin >> size;

    int* array = new int[size];


    cout << "Enter elements of array:\n";
    for (int i = 0; i < size; ++i) {
        cout << "Element " << (i + 1) << ":";
        cin >> array[i];
    }

    unordered_map<int, int> frequencyMap;

    int newSize = 0;
    for (int i = 0; i < size; ++i) {
        if (frequencyMap[array[i]] == 0) {
            frequencyMap[array[i]] = 1;
            ++newSize;
        }
    }

    int* newArray = new int[newSize];

    int newIndex = 0;
    for (int i = 0; i < size; ++i) {
        if (frequencyMap[array[i]] == 1) {
            newArray[newIndex] = array[i];
            ++newIndex;
            frequencyMap[array[i]] = 0;
        }
    }

    cout << "Array after deleting garbage :\n";
    for (int i = 0; i < newSize; ++i) {
        cout << newArray[i] << " ";
    }

    delete[] array;
    delete[] newArray;

    return 0;
}
