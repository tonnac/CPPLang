#include <iostream>
#include <cstring>

using namespace std;

class Book
{
public:
	Book(const char * _title, const char * _isbn, int _price) : price(_price)
	{
		title = new char[strlen(_title) + 1];
		isbn = new char[strlen(_isbn) + 1];
		strcpy_s(title, strlen(_title) + 1, _title);
		strcpy_s(isbn, strlen(_isbn) + 1, _isbn);
	}
	~Book()
	{
		delete[]title;
		delete[]isbn;
	}
	void ShowBookInfo()  const
	{
		cout << "����: " << title << endl;
		cout << "ISBN: " << isbn << endl;
		cout << "����: " << price << endl;
	}
private:
	char * title;
	char * isbn;
	int price;
};

class EBook : public Book
{
public:
	EBook(const char * _title, const char * _isbn, int _price, const char * _DRMKey) : Book(_title, _isbn, _price)
	{
		DRMKey = new char[strlen(_DRMKey) + 1];
		strcpy_s(DRMKey, strlen(_DRMKey) + 1, _DRMKey);
	}
	void ShowEBookInfo() const
	{
		ShowBookInfo();
		cout << "����Ű: " << DRMKey << endl;
	}
private:
	char * DRMKey;
};

int main()
{
	Book book("���� C++", "555-12345-890-0", 20000);
	book.ShowBookInfo();
	cout << endl;
	EBook ebook("���� C++ ebook", "555-12345-890-1", 10000, "fdx9w0i8kiw");
	ebook.ShowEBookInfo();
}