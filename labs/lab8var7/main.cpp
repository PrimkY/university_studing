#include <iostream>
#include <cstring>
#include <algorithm>
#include <iomanip>

using namespace std;

struct Book {
    char title[50];
    char author[30];
    int year;
    int pages;
};

bool compareBooks(const Book& book1, const Book& book2) {
    return strcmp(book1.title, book2.title) < 0;
}

int main() {
    int amount;
    cout << "************************* Lab 8 var 7 **************************" << endl;
    cout << "Enter amount of books: " << endl;
    cin >> amount;

    Book* books = new Book[amount];

    for (int i = 0; i < amount; ++i) {
        cout << "Enter info about book#" << i + 1 << ":\n";
        cout << "Title: ";
        cin.ignore();
        cin.getline(books[i].title, sizeof(books[i].title));
        cout << "Author: ";
        cin.getline(books[i].author, sizeof(books[i].author));
        cout << "Year: ";
        cin >> books[i].year;
        cout << "Number of pages: ";
        cin >> books[i].pages;
    }

    sort(books, books + amount, compareBooks);

    cout << "\n Books that have been published before 1990, ASC" << endl;
    for (int i = 0; i < amount; ++i) {
        if (books[i].year < 1990) {
            cout << setw(20) << books[i].title << setw(20) << books[i].author << setw(7) << books[i].year << setw(7) << books[i].pages << endl;
        }
    }

    delete[] books;
    cout << "****************************************************************" << endl;
    return 0;
}
