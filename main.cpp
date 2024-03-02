#include <iostream>
#include <string>
#include <fstream>

using namespace std;

void login();
void showCompanyDetails();
void mainMenu();
void addbook();
void available_book_list();
void searchBooks();
void updateBook();
void deleteBook();

struct Book
{
	int bookID;
	string bookName;
    string bookAuthor;
	int quantity;
	double unitPrice;
};

Book books[15];

int main() 
{   
    books[0].bookID = 1;
	books[0].bookName = "Clean Code";
	books[0].bookAuthor = "Uncle bob";
	books[0].quantity = 10;
    books[0].unitPrice = 12.99;

    books[1].bookID = 2;
	books[1].bookName = "Cracking the Coding Interview 189 Programming Questions and Solutions";
	books[1].bookAuthor = "Gayle Laakmann McDowell";
	books[1].quantity = 7;
    books[1].unitPrice = 41.99;

    books[2].bookID = 3;
	books[2].bookName = "C++ Primer";
	books[2].bookAuthor = "Barbara E. Moo";
	books[2].quantity = 11;
    books[2].unitPrice = 15.99;

    login();
    return 0;
} 

void addbook(){
	
	for (int i = 3; i < 15; ++i)
	{
		books[i].bookID = i+1;

		cout << "Enter Book name: ";
		cin >>books[i].bookName;

		cout << "Enter Author name: ";
		cin >>books[i].bookAuthor;

		cout << "Enter book quantity: ";
		cin >>books[i].quantity;

		cout << "Enter book price: ";
		cin >>books[i].unitPrice;

		string addrecode;
		cout << "you want to add more recode yes/no: ";
		cin >> addrecode;
		if(addrecode == "no"){
			break;
		}
	}
	mainMenu();

}

void available_book_list() {
    for (Book book : books) {
        cout << book.bookID << endl;
        cout << book.bookName << endl;
        cout << book.bookAuthor << endl;
        cout << book.quantity << endl;
        cout << book.unitPrice << "\n\n" << endl;
    }
}

void searchBooks() {
    int bookid;
	cout <<"Enter Book id: ";
	cin >> bookid;

	for (int i = 0; i < 15; i++) {
		if (bookid == books[i].bookID) {
			cout << "\nBook id is: " << books[i].bookID << endl;
            cout << "Book name is: " << books[i].bookName << endl;
            cout << "Book Author is " << books[i].bookAuthor << endl;
            cout << "Book quantity is "<< books[i].quantity << endl;
            cout << "UnitPrice is  " << books[i].unitPrice << "\n" << endl; 
			break;
		}
        
	}
	mainMenu();
}

void updateBook() {
    int bookId;
	cout << "Enter Book Id: ";
	cin >> bookId;

    for (Book book : books) {
        if (book.bookID == bookId) {
            cout <<"\nEnter new Book Name: ";
			cin >> book.bookName;
            cout <<"Enter new Book Author: ";
			cin >> book.bookAuthor;
            cout <<"Enter new Book quantity: ";
			cin >> book.quantity;
            cout <<"Enter new Book price: ";
			cin >> book.unitPrice;
            break;
        }
    }
    mainMenu();
}

void deleteBook() {
    int bookId;
	cout << "Enter Book Id: ";
	cin >> bookId;

    for (Book book : books) {
        if (book.bookID == bookId) {
			book.bookName = "";
			book.bookAuthor = "";
			book.quantity = 0;
			book.unitPrice = 0;
            break;
        }
    }
    mainMenu();
}

void login() {
    cout << "____________________________________________________\n";
    cout << "                Login to Bookshop                 \n" << endl;
    while (true)
    {
        string userName, password, id, pass;
        cout << "Please enter your username: "; // Username is Laksahan
        cin >> userName;

        cout << "Please enter your password: "; // Password is 1234
        cin >> password;

        ifstream input("usesrnames_and_passwords.txt");

        while (input>>id>>pass)
        {
            if (userName == id && password == pass) {
                cout << "\nYou are now logged in now with a password \n";
                mainMenu();
            } else {
                cout << "\nLOGIN ERROR Please check your username and password \n\n";
                break;
            }
        }
        input.close();

    }
}


void mainMenu() {
    int choice;

    cout << "1 : Search books: " << endl;
    cout << "2 : Add book: " << endl;
    cout << "3 : Update book: " << endl;
    cout << "4 : Delete book: " << endl;
    cout << "5 : Available stock: " << endl;
    cout << "6 : View company details: " << endl;
    cout << "7 : Logout: " << endl;
    cout << "8 : Exit: " << endl;
    cout << "\nPlease enter your choice : ";
    cin >> choice;

    switch (choice) {
        case 1:
            searchBooks();
            break;
        case 2:
            addbook();
            break;
        case 3:
            updateBook();
            break;
        case 4:
            deleteBook();
            break;
        case 5:
            available_book_list();
            mainMenu();
            break;
        case 6:
            showCompanyDetails();
            break;
        case 7:
            system("cls");
            main();
            break;
        case 8:
            cout << "Thank you \n" << endl; 
            system("cls");
            main();
            break;
        default:
            system("cls");
            cout << "Please select from the options given above \n" << endl;
            mainMenu();
    }

}

void showCompanyDetails() {
    cout << "\nGenius Book shop" << endl;
    cout << "Adress: No: 186, Nawala road, Nugegoda." << endl;
    cout << "Contact Number: 011-2867592" << endl;
    cout << "Website: www.geniusbooks.com\n" << endl;
    mainMenu();

}
    