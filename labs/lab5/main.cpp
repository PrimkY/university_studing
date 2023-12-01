#include <iostream>
using namespace std;

int main() {
    int rows, cols;

    // Ввод количества строк и столбцов
    cout << "Enter number of rows:";
    cin >> rows;

    cout << "Enter number of columns:";
    cin >> cols;

    // Выделение памяти под двумерный массив
    int** matrix = new int*[rows];
    for (int i = 0; i < rows; ++i) {
        matrix[i] = new int[cols];
    }

    // Ввод элементов матрицы
    cout << "Enter element of matrix:\n";
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            cout << "Element[" << i + 1 << "][" << j + 1 << "]:";
            cin >> matrix[i][j];
        }
    }

    // Определение количества "особых" элементов
    int specialCount = 0;
    for (int j = 0; j < cols; ++j) {
        int colSum = 0;
        for (int i = 0; i < rows; ++i) {
            colSum += matrix[i][j];
        }

        for (int i = 0; i < rows; ++i) {
            if (matrix[i][j] > colSum - matrix[i][j]) {
                ++specialCount;
            }
        }
    }

    // Вывод результата
    cout << "Number of 'strange' elements: " << specialCount << endl;

    // Освобождение выделенной памяти
    for (int i = 0; i < rows; ++i) {
        delete[] matrix[i];
    }
    delete[] matrix;

    return 0;
}
