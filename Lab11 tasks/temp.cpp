#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

class Book {
    int bookID;
    char title[50];
    float price;

public:
    Book(int id = 0, const char* t = "Unknown", float p = 0.0) : bookID(id), price(p) {
        strncpy(title, t, sizeof(title));
        title[sizeof(title) - 1] = '\0';
    }

    void input_book_details() {
        cout << "Enter Book ID: ";
        cin >> bookID;
        cin.ignore();
        cout << "Enter Title: ";
        cin.getline(title, 50);
        cout << "Enter Price: ";
        cin >> price;
    }

    void display_book_details() const {
        cout << "ID: " << bookID << ", Title: " << title << ", Price: $" << price << endl;
    }

    int getBookID() const { return bookID; }

    int storeBook();
    static void view_all_books();
    static void show_book(int id);
    static void delete_book(int id);
};

int Book::storeBook() {
    if (bookID == 0 || price == 0.0) {
        cout << "Book details are not valid.\n";
        return 0;
    }

    ofstream fout("library.dat", ios::app | ios::binary);
    if (!fout) {
        cout << "Error opening file.\n";
        return 0;
    }

    fout.write((char*)this, sizeof(*this));
    fout.close();
    return 1;
}

void Book::view_all_books() {
    ifstream fin("library.dat", ios::binary);
    if (!fin) {
        cout << "Error opening file.\n";
        return;
    }

    Book b;
    cout << "\nAll Books:\n";
    while (fin.read((char*)&b, sizeof(b))) {
        b.display_book_details();
    }

    fin.close();
}

void Book::show_book(int id) {
    ifstream fin("library.dat", ios::binary);
    if (!fin) {
        cout << "Error opening file.\n";
        return;
    }

    Book b;
    bool found = false;

    while (fin.read((char*)&b, sizeof(b))) {
        if (b.getBookID() == id) {
            cout << "\nBook Found:\n";
            b.display_book_details();
            found = true;
            break;
        }
    }

    if (!found) {
        cout << "Book with ID " << id << " not found.\n";
    }

    fin.close();
}

void Book::delete_book(int id) {
    ifstream fin("library.dat", ios::binary);
    ofstream fout("temp.dat", ios::binary);

    if (!fin || !fout) {
        cout << "Error opening file.\n";
        return;
    }

    Book b;
    bool deleted = false;

    while (fin.read((char*)&b, sizeof(b))) {
        if (b.getBookID() != id) {
            fout.write((char*)&b, sizeof(b));
        } else {
            deleted = true;
        }
    }

    fin.close();
    fout.close();

    remove("library.dat");
    rename("temp.dat", "library.dat");

    if (deleted)
        cout << "Book deleted successfully.\n";
    else
        cout << "Book with ID " << id << " not found.\n";
}

int main() {
    int choice, id;
    Book b;

    do {
        cout << "\n----- Library Menu -----\n";
        cout << "1. Input Book\n2. Store Book\n3. View All Books\n4. Show Book by ID\n5. Delete Book\n0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                b.input_book_details();
                break;
            case 2:
                b.storeBook();
                break;
            case 3:
                Book::view_all_books();
                break;
            case 4:
                cout << "Enter Book ID to search: ";
                cin >> id;
                Book::show_book(id);
                break;
            case 5:
                cout << "Enter Book ID to delete: ";
                cin >> id;
                Book::delete_book(id);
                break;
            case 0:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice.\n";
        }
    } while (choice != 0);

    return 0;
}

