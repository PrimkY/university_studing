#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    int rows, cols;
    cout << "Enter number of rows:";
    cin >> rows;

    cout << "Enter number of columns:";
    cin >> cols;

    int** matrix = new int*[rows];
    for (int i = 0; i < rows; ++i) {
        matrix[i] = new int[cols];
    }

    cout << "Enter element of matrix:\n";
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            cout << "Element[" << i + 1 << "][" << j + 1 << "]:";
            cin >> matrix[i][j];
        }
    }

    for (int i = 0; i < rows - 1; ++i) {
        for (int j = 0; j < rows - i - 1; ++j) {
            int sum1 = 0;
            for (int k = 0; k < cols; ++k) {
                sum1 += matrix[j][k];
            }

            int sum2 = 0;
            for (int k = 0; k < cols; ++k) {
                sum2 += matrix[j + 1][k];
            }

            if(sum1 > sum2) {
                swap(matrix[j], matrix[j+1]);
            }
        }
    }

    cout << "Result matrix will looks like this: " << endl;
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            cout << setw(5) << matrix[i][j] << " ";
        }
        cout << '\n';
    }

    for (int i = 0; i < rows; ++i) {
        delete[] matrix[i];
    }
    delete[] matrix;
    system("pause");
    return 0;
}