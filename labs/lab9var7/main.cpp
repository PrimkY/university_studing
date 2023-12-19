#include <iostream>
#include <fstream>
#include <cstring>
#include <algorithm>

using namespace std;

struct Book {
    char title[100];
    char author[100];
    int year;
    int pages;
};

bool compareBooks(const Book& book1, const Book& book2) {
    return strcmp(book1.title, book2.title) < 0;
}

void createBinaryFile(const char* fileName, const Book* books, int n) {
    ofstream file(fileName, ios::binary | ios::trunc);
    if (file.is_open()) {
        file.write(reinterpret_cast<const char*>(&n), sizeof(int));
        file.write(reinterpret_cast<const char*>(books), n * sizeof(Book));
        file.close();
        cout << "Binary file created successfully.\n";
    } else {
        cerr << "Error opening file for writing.\n";
    }
}

void readBinaryFileAndPrint(const char* fileName) {
    ifstream file(fileName, ios::binary);
    if (file.is_open()) {
        int n;
        file.read(reinterpret_cast<char*>(&n), sizeof(int));

        Book* books = new Book[n];
        file.read(reinterpret_cast<char*>(books), n * sizeof(Book));

        sort(books, books + n, compareBooks);

        cout << "\nBooks published before 1990 in alphabetical order:\n";
        for (int i = 0; i < n; ++i) {
            if (books[i].year < 1990) {
                cout << "Title: " << books[i].title << ", Author: " << books[i].author
                     << ", Year of publication: " << books[i].year << ", Number of pages: " << books[i].pages << endl;
            }
        }

        delete[] books;
        file.close();
    } else {
        cerr << "Error opening file for reading.\n";
    }
}

void writeToFile(const char* binaryFileName, const char* textFileName) {
    ifstream binaryFile(binaryFileName, ios::binary);
    ofstream textFile(textFileName);

    if (binaryFile.is_open() && textFile.is_open()) {
        int n;
        binaryFile.read(reinterpret_cast<char*>(&n), sizeof(int));

        Book* books = new Book[n];
        binaryFile.read(reinterpret_cast<char*>(books), n * sizeof(Book));

        sort(books, books + n, compareBooks);

        textFile << "\nBooks published before 1990 in alphabetical order:\n";
        for (int i = 0; i < n; ++i) {
            if (books[i].year < 1990) {
                textFile << "Title: " << books[i].title << ", Author: " << books[i].author
                         << ", Year of publication: " << books[i].year << ", Number of pages: " << books[i].pages << endl;
            }
        }

        delete[] books;
        binaryFile.close();
        textFile.close();
        cout << "Data successfully written to the text file.\n";
    } else {
        cerr << "Error opening files for writing.\n";
    }
}

int main() {
    setlocale(LC_ALL, "");

    int choice;
    const char* binaryFileName = "books.dat";
    const char* textFileName = "result.txt";

    do {
        cout << "\nMenu:\n";
        cout << "1. Create a binary file with book data\n";
        cout << "2. Display book data from the binary file on the screen\n";
        cout << "3. Write book data from the binary file to a text file\n";
        cout << "0. Exit\n";
        cout << "Choose an action: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                int n;

                cout << "Enter the number of books: ";
                cin >> n;

                Book* books = new Book[n];

                for (int i = 0; i < n; ++i) {
                    cout << "Enter information about book #" << i + 1 << ":\n";
                    cout << "Title: ";
                    cin.ignore();
                    cin.getline(books[i].title, sizeof(books[i].title));
                    cout << "Author: ";
                    cin.getline(books[i].author, sizeof(books[i].author));
                    cout << "Year of publication: ";
                    cin >> books[i].year;
                    cout << "Number of pages: ";
                    cin >> books[i].pages;
                }

                createBinaryFile(binaryFileName, books, n);

                delete[] books;
                break;
            }
            case 2:
                readBinaryFileAndPrint(binaryFileName);
                break;
            case 3:
                writeToFile(binaryFileName, textFileName);
                break;
            case 0:
                cout << "Program terminated.\n";
                break;
            default:
                cout << "Invalid choice. Please choose an existing menu item.\n";
                break;
        }

    } while (choice != 0);

    return 0;
}
