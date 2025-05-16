
#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct Book {
    int id;
    string title;
    string author;
    bool available;
};

vector<Book> library;

void addBook() {
    Book b;
    cout << "Enter Book ID: ";
    cin >> b.id;
    cout << "Enter Title: ";
    cin.ignore();
    getline(cin, b.title);
    cout << "Enter Author: ";
    getline(cin, b.author);
    b.available = true;
    library.push_back(b);
    cout << "Book Added.\n";
}

void displayBooks() {
    for (const Book& b : library) {
        cout << "ID: " << b.id << ", Title: " << b.title << ", Author: " << b.author;
        cout << ", Available: " << (b.available ? "Yes" : "No") << endl;
    }
}

void searchBook(int id) {
    for (const Book& b : library) {
        if (b.id == id) {
            cout << "Title: " << b.title << ", Author: " << b.author;
            cout << ", Available: " << (b.available ? "Yes" : "No") << endl;
            return;
        }
    }
    cout << "Book Not Found.\n";
}

int main() {
    int choice, id;
    do {
        cout << "\n--- Library Menu ---\n";
        cout << "1. Add Book\n2. Display All\n3. Search Book\n4. Exit\nChoose: ";
        cin >> choice;
        switch (choice) {
            case 1: addBook(); break;
            case 2: displayBooks(); break;
            case 3: cout << "Enter Book ID: "; cin >> id; searchBook(id); break;
            case 4: cout << "Goodbye!\n"; break;
            default: cout << "Invalid Choice.\n";
        }
    } while (choice != 4);
    return 0;
}
