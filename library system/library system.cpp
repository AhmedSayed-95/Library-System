
#include <iostream>
#include<vector>
#include<string>
using namespace std;







// BOOK CLASS THAT CONTAINS BOOK DETAILS WITH SETTERS AND GETTERS..
class book {
private:
	int id;
	string title, author;
	bool avail;
public:
	book() {}


	book(int id, string title, string author) {
		this->id = id;
		this->title = title;
		this->author = author;
		avail = true;
	}


	void setID(int id) {
		this->id = id;
	}


	int getID() {
		return id;
	}


	void setTitle(string title) {
		this->title = title;
	}


	string getTitle() {
		return title;
	}


	void setAuthor(string author) {
		this->author = author;
	}


	string getAuthor() {
		return author;
	}


	void setAvail(bool avail) {
		this->avail = avail;
	}


	bool getAvail() {
		return avail;
	}

};











//BOOK LIST THAT CONTAINS THE LIST WITH THIER FUNCTIONS..
class booklist {


private:
	vector<book>b;


public:

	bool isEmpty() {
		return(b.size() == 0);
	}


	void addNew() {
		int book_id;
		string book_title, book_author;
		cout << "Enter book id" << endl;
		cin >> book_id;

		for (int i = 0; i < b.size(); i++)
		{
			if (b[i].getID() == book_id) {
				cout << "\n    ID already exist   " << endl;
				return;
			}
		}
		cout << "Enter book Title" << endl;
		cin >> book_title;
		cout << "Enter book author name" << endl;
		cin >> book_author;
		b.push_back(book(book_id, book_title, book_author));
		cout << "\n \n ======================\n";
		cout << "Book ID : " << "\"" << book_id << "\"" << endl;
		cout << "Book Title : " << "\"" << book_title << "\"" << endl;
		cout << "Book Author : " << "\"" << book_author << "\"" << endl;
		cout << "--- " << " added successfully" << " --- " << endl;
	}


	void remove() {
		if (isEmpty())
		{
			cout << "Sorry there is no book to Remove";
			return;
		}
		int book_id;
		cout << "Enter book id" << endl;
		cin >> book_id;
		for (int i = 0; i < b.size(); i++)
		{
			if (b[i].getID() == book_id) {

				b.erase(b.begin() + i);
				cout << "--- " << " removed successfully" << " --- " << endl;

			}
		}
	}


	int numOfBooks() {
		return b.size();
	}


	void update() {
		if (isEmpty())
		{
			cout << "Sorry there is no book to Update";
			return;
		}
		int book_id;
		cout << "Enter book id" << endl;
		cin >> book_id;
		string title, author;
		cout << "Enter new title\n";
		cin >> title;
		cout << "Enter author name\n";
		cin >> author;
		for (int i = 0; i < b.size(); i++)
		{
			if (b[i].getID() == book_id) {
				b[i].setTitle(title);
				b[i].setAuthor(author);
				cout << "--- " << "\"" << " updated successfully" << " --- " << endl;
			}
		}
	}



	void borrow() {
		if (isEmpty())
		{
			cout << "Sorry there is no book to Borrow";
			return;
		}
		int book_id;
		cout << "Enter book id" << endl;
		cin >> book_id;
		for (int i = 0; i < b.size(); i++)
		{
			if (b[i].getID() == book_id)
			{
				if (b[i].getAvail() == false)
				{
					cout << "Sorry book is not available right now..(borrowed)\n";
					return;
				}
				b[i].setAvail(false);
				cout << "--- " << " Borrowing successfully" << " --- " << endl;
				return;
			}
		}
		cout << "Doesn't Exist";
	}


	void returnBook() {
		if (isEmpty())
		{
			cout << "there is no books in list" << endl;
			return;
		}
		int count = 0;
		for (int i = 0; i < b.size(); i++)
		{
			if (b[i].getAvail() == true)
			{
				count++;
			}
			if (count == b.size())
			{
				cout << "there is no Borrowed books" << endl;
				return;
			}
		}
		int book_id;
		cout << "Enter book id" << endl;
		cin >> book_id;
		for (int i = 0; i < b.size(); i++)
		{
			if (b[i].getID() == book_id)
			{
				if (b[i].getAvail() == false)
				{
					b[i].setAvail(true);
					cout << "--- " << " Returning successfully" << " --- " << endl;
					return;
				}
				else
				{
					cout << "--- " << " Book was not borrowing.. please insert right ID." << " --- " << endl;
					return;
				}
			}

		}
		cout << "--- " << " Sorry is not exist" << " --- " << endl;
	}


	void displayAvailble() {
		if (isEmpty())
		{
			cout << "Sorry there is no book to Display";
			return;
		}

		for (int i = 0; i < b.size(); i++)
		{
			if (b[i].getAvail() == true)
			{
				cout << "\n \n ======================\n";
				cout << "Book ID : " << "\"" << b[i].getID() << "\"" << endl;
				cout << "Book Title : " << "\"" << b[i].getTitle() << "\"" << endl;
				cout << "Book Author : " << "\"" << b[i].getAuthor() << "\"" << endl;
				cout << "Book Status :  Available";
			}
		}
	}


	void displayAll() {
		if (isEmpty())
		{
			cout << "Sorry there is no book to Display";
			return;
		}

		for (int i = 0; i < b.size(); i++)
		{
			if (b[i].getAvail() == true)
			{
				cout << "\n \n ======================\n";
				cout << "Book ID : " << "\"" << b[i].getID() << "\"" << endl;
				cout << "Book Title : " << "\"" << b[i].getTitle() << "\"" << endl;
				cout << "Book Author : " << "\"" << b[i].getAuthor() << "\"" << endl;
				cout << "Book Status :  Available";

			}
			else {
				cout << "\n \n ======================\n";
				cout << "Book ID : " << "\"" << b[i].getID() << "\"" << endl;
				cout << "Book Title : " << "\"" << b[i].getTitle() << "\"" << endl;
				cout << "Book Author : " << "\"" << b[i].getAuthor() << "\"" << endl;
				cout << "Book Status :  book is not available right now..(borrowed)\n";
			}
		}
	}


	void search() {
		if (isEmpty())
		{
			cout << "Sorry there is no book to Search";
			return;
		}
		int book_id;
		cout << "Enter book id" << endl;
		cin >> book_id;

		for (int i = 0; i < b.size(); i++)
		{
			if (b[i].getID() == book_id)
			{
				if (b[i].getAvail() == true)
				{
					cout << "\n \n ======================\n";
					cout << "Book ID : " << "\"" << b[i].getID() << "\"" << endl;
					cout << "Book Title : " << "\"" << b[i].getTitle() << "\"" << endl;
					cout << "Book Author : " << "\"" << b[i].getAuthor() << "\"" << endl;
					cout << "Book Status :  Available";
					return;
				}
				else {
					cout << "\n \n ======================\n";
					cout << "Book ID : " << "\"" << b[i].getID() << "\"" << endl;
					cout << "Book Title : " << "\"" << b[i].getTitle() << "\"" << endl;
					cout << "Book Author : " << "\"" << b[i].getAuthor() << "\"" << endl;
					cout << "Book Status :  book is not available right now..(borrowed)\n";
					return;
				}
			}
		}
		cout << "Doesn't Exist";
	}


};






int main() {
	booklist bk;
	int selector;
	string name;
	cout << "Hello, please enter your name:\n";
	//cin >> name;
	getline(cin, name);
	do
	{
		cout << "\n \n Welcome " << name << " TO ALEX LIBRARY" << endl;
		cout << "========================\n" << endl;
		cout << "1 - Add new book" << endl;
		cout << "2 - Remove book" << endl;
		cout << "3 - Update book" << endl;
		cout << "4 - Borrow book" << endl;
		cout << "5 - Return book" << endl;
		cout << "6 - Available books" << endl;
		cout << "7 - All books" << endl;
		cout << "8 - Search" << endl;
		cout << "9 - Exit" << endl;
		cin >> selector;


		if (selector == 1)
		{
			cout << "********* ADDING NEW BOOK *********" << endl;


			bk.addNew();

		}
		else if (selector == 2)
		{
			cout << "********* REMOVING BOOK *********" << endl;
			bk.remove();
		}
		else if (selector == 3)
		{
			cout << "********* UPDATING BOOK *********" << endl;
			bk.update();
		}
		else if (selector == 4)
		{
			cout << "********* BORROWING BOOK *********" << endl;

			bk.borrow();
		}
		else if (selector == 5)
		{
			cout << "********* RETURNING BOOK *********" << endl;
			bk.returnBook();
		}
		else if (selector == 6)
		{
			cout << "********* AVAILABLE BOOKS *********" << endl;
			bk.displayAvailble();
		}
		else if (selector == 7)
		{
			cout << "********* ALL BOOKS *********" << endl;
			bk.displayAll();
		}
		else if (selector == 8)
		{
			cout << "********* Search *********" << endl;
			bk.search();
		}
		else if (selector == 9)
		{
			cout << "********* Exit *********" << endl;
		}
		else
		{
			cout << "ERROR.. WRONG SELECTION" << endl;
		}
	} while (selector != 9);


	return 0;
}