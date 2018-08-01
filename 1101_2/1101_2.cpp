#include <iostream>
#include <cstring>

using namespace std;

class Book
{
public:
	Book() : title(NULL), isbn(NULL), price(0)
	{}
	Book(const char * _title, const char * _isbn, int _price) : price(_price)
	{
		title = new char[strlen(_title) + 1];
		isbn = new char[strlen(_isbn) + 1];
		strcpy_s(title, strlen(_title) + 1, _title);
		strcpy_s(isbn, strlen(_isbn) + 1, _isbn);
	}
	Book(const Book& ref)
	{
		title = new char[strlen(ref.title) + 1];
		isbn = new char[strlen(ref.isbn) + 1];
		strcpy_s(title, strlen(ref.title) + 1, ref.title);
		strcpy_s(isbn, strlen(ref.isbn) + 1, ref.isbn);
		price = ref.price;
	}
	Book& operator=(const Book& ref)
	{
		if (title && isbn)
		{
			delete[]title;
			delete[]isbn;	
		}
		title = new char[strlen(ref.title) + 1];
		isbn = new char[strlen(ref.isbn) + 1];
		strcpy_s(title, strlen(ref.title) + 1, ref.title);
		strcpy_s(isbn, strlen(ref.isbn) + 1, ref.isbn);
		price = ref.price;
		return *this;
	}
	~Book()
	{
		delete[]title;
		delete[]isbn;
	}
	void ShowBookInfo()  const
	{
		cout << "제목: " << title << endl;
		cout << "ISBN: " << isbn << endl;
		cout << "가격: " << price << endl;
	}
private:
	char * title;
	char * isbn;
	int price;
};

class EBook : public Book
{
public:
	EBook() : Book()
	{
		DRMKey = NULL;
	}
	EBook(const char * _title, const char * _isbn, int _price, const char * _DRMKey) : Book(_title, _isbn, _price)
	{
		DRMKey = new char[strlen(_DRMKey) + 1];
		strcpy_s(DRMKey, strlen(_DRMKey) + 1, _DRMKey);
	}
	EBook(const EBook &ref)
	{
		Book::operator=(ref);
		DRMKey = new char[strlen(ref.DRMKey) + 1];
		strcpy_s(DRMKey, strlen(ref.DRMKey) + 1, ref.DRMKey);
	}
	EBook& operator = (const EBook& ref)
	{
		Book::operator=(ref);
		if (DRMKey)
		{
			delete[]DRMKey;
		}
		DRMKey = new char[strlen(ref.DRMKey) + 1];
		strcpy_s(DRMKey, strlen(ref.DRMKey) + 1, ref.DRMKey);
		return *this;
	}
	void ShowEBookInfo() const
	{
		ShowBookInfo();
		cout << "인증키: " << DRMKey << endl;
	}
	~EBook()
	{
		delete[] DRMKey;
	}
private:
	char * DRMKey;
};

int main()
{
	Book book("좋은 C++", "555-12345-890-0", 20000);
	Book book1 = book;
	Book book2;
	book1.ShowBookInfo();
	cout << endl;
	EBook ebook("좋은 C++ ebook", "555-12345-890-1", 10000, "fdx9w0i8kiw");
	EBook ebook1("좋은 C++ ebook", "555-12345-110-0", 10000, "fdx9w0i8kiw");
	EBook qw;
	qw = ebook;
	ebook1 = ebook;

	qw.ShowEBookInfo();
}