#include <iostream>
#include <vector>
#include <limits>

using namespace std;

struct Book {
    string title;
    string author;
    string ISBN;
    bool isAvailable = true;
};

vector<Book> books;

// Function to add a book to the database
void addBook(string title, string author, string ISBN) {
    books.push_back({ title, author, ISBN, true });
    cout << "Book added successfully!\n";
}

// Function to search for a book
void searchBook(string query) {
    bool found = false;
    cout << "Search results:\n";
    for (const auto& book : books) {
        if (book.title == query || book.author == query || book.ISBN == query) {
            cout << "Title: " << book.title << ", Author: " << book.author
                << ", ISBN: " << book.ISBN << ", Available: "
                << (book.isAvailable ? "Yes" : "No") << endl;
            found = true;
        }
    }
    if (!found) cout << "No matching book found.\n";
}

// Function to check out a book
void checkoutBook(string ISBN) {
    for (auto& book : books) {
        if (book.ISBN == ISBN && book.isAvailable) {
            book.isAvailable = false;
            cout << "Book checked out successfully!\n";
            return;
        }
    }
    cout << "Book not found or already checked out.\n";
}

// Function to return a book
void returnBook(string ISBN, int overdueDays) {
    for (auto& book : books) {
        if (book.ISBN == ISBN && !book.isAvailable) {
            book.isAvailable = true;
            cout << "Book returned successfully!\n";

            if (overdueDays > 0) {
                int fine = overdueDays * 10;  // Assuming fine is ₹10 per day
                cout << "Late return fine: ₹" << fine << endl;
            }
            return;
        }
    }
    cout << "Book not found or already returned.\n";
}

// Main program loop
int main() {
    int choice;
    string title, author, ISBN;
    int overdueDays;

    while (true) {
        cout << "\nLibrary Management System\n";
        cout << "1. Add Book\n2. Search Book\n3. Check Out Book\n4. Return Book\n5. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Clear input buffer

        switch (choice) {
        case 1:
            cout << "Enter title: ";
            getline(cin, title);
            cout << "Enter author: ";
            getline(cin, author);
            cout << "Enter ISBN: ";
            getline(cin, ISBN);
            addBook(title, author, ISBN);
            break;
        case 2:
            cout << "Enter title, author, or ISBN to search: ";
            getline(cin, title);
            searchBook(title);
            break;
        case 3:
            cout << "Enter ISBN to check out: ";
            cin >> ISBN;
            checkoutBook(ISBN);
            break;
        case 4:
            cout << "Enter ISBN to return: ";
            cin >> ISBN;
            cout << "Enter overdue days: ";
            cin >> overdueDays;
            returnBook(ISBN, overdueDays);
            break;
        case 5:
            cout << "Goodbye!\n";
            return 0;
        default:
            cout << "Invalid choice. Please try again.\n";
        }
    }
}