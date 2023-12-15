#ifndef A6LIBRARY_MAIN_H
#define A6LIBRARY_MAIN_H

#include <time.h>
#include <math.h>
#include <string>
#include <fstream>
#include <iomanip>
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <windows.h>
#include "style.h"

#define MAX 1000
using namespace std;

void SetWinConsole();
void clrscr();
void hideCursor();
void showCursor();
void Loading();

char op, bop, rop, brop;
int i, j, id;
int r = 0, w = 0;
int n = 0, k = 0;
int bw = 0, p = 0;
int count_number_account = 0;

//*__Main Class Person__*
class Person
{
protected:
	int id, status;
	string name, sex;
	string username, password;

public:
	string getUsername()
	{
		return username;
	}
	string getPassword()
	{
		return password;
	}
	void show()
	{
		cout << "Person test" << endl;
	}
	void MAKEAccount()
	{
		cout << "\n[--> RESET USERNAME AND PASSWORD <--]" << endl;
		cout << "INPUT NEW USERNAME :: ";
		cin >> username;
		cout << "INPUT NEW PASSWORD :: ";
		cin >> password;
		count_number_account++;
	}
	// ======== Login ========
	void Login_form()
	{
		string __username, __password, line;
		int check_number_count = 0, width = 0, height = 5, g=0;
	login_page:
		clrscr();
		g = 3;
		ifstream art_file("data/artText/login.txt");
		while (getline(art_file, line))
		{
			gotoxy(30, g++);
			cout << line << "\n";
		}
		cout << endl;
		// user box
		DrawRectangle(50 + width, 5 + height, 20, 1);
		// pass box
		DrawRectangle(50 + width, 9 + height, 20, 1);
		gotoxy(40 + width, 6 + height); cout << "USERNAME";
		gotoxy(40 + width, 10 + height); cout << "PASSWORD";
		gotoxy(52 + width, 6 + height); cin >> __username;
		gotoxy(52 + width, 10 + height); cin >> __password;
		if (__username == "RUPP" && __password == "A6" || __username == getUsername() && __password == getPassword())
		{
			clrscr();
			Loading();
		}
		else
		{
			check_number_count++;
			if (check_number_count == 2)
			{
				cout << "\n>>> Forget Username and Password? <<<\n--> Press 'Enter' to RESET the Username and Password  OR 'ESC' to EXIT :: ";
				if (getch() == 13)
				{
					MAKEAccount();
					goto login_page;
				}
				else if (getch() == 27)
				{
					cout << "\n\n\t\tTHANK YOU " << (char)3;
					getch();
					exit(300);
				}
			}
			else
			{
				cout << "\nUsername or Password Worng!, Please login again..." << endl;
				getch();
				goto login_page;
			}
		}
		art_file.close();
	}
};
// *===================================================
// *             *____ Book ____*
// *===================================================
class BookData
{
protected:
	int book_qty;
	string book_code, book_title, book_author, book_date, book_status;

public:
	BookData()
	{
		book_code = "Unknow";
		book_title = "Unknow";
		book_author = "Unknow";
		book_date = "Unknow";
		book_status = "Unknow";
		book_qty = 0;
	}
	string getCode()
	{
		return book_code;
	}
	string getTitle()
	{
		return book_title;
	}
	string getAuthor()
	{
		return book_author;
	}
	string getDate()
	{
		return book_date;
	}
	int getQty()
	{
		return book_qty;
	}
	void setCode(string code)
	{
		this->book_code = code;
	}
	void setTitle(string title)
	{
		this->book_title = title;
	}
	void setAuthor(string author)
	{
		this->book_author = author;
	}
	void setDate(string date)
	{
		this->book_date = date;
	}
	void setQty(int qty)
	{
		this->book_qty = qty;
	}

	int count_string(string s)
	{
		int ss;
		ss = s.length();
		return ss;
	}

	string Check_Book_Staus(int t)
	{
		if (t >= 1)
		{
			foreColor(2);
			book_status = "Remaining";
		}
		if (t == 0)
		{
			foreColor(4);
			book_status = "Does not exist";
		}
		return book_status;
	}

	void book_header()
	{
		foreColor(4);
		drawBoxSingleLine(9, 3, 100, 1);
		gotoxy(10, 4);
		foreColor(7);
		cout << left
			 << setw(10) << "CODE"
			 << setw(20) << "TITLE"
			 << setw(17) << "AUTHOR"
			 << setw(17) << "DATE"
			 << setw(17) << "QUANTITY"
			 << setw(17) << "SRATUS";
	}

	void input_book()
	{
		string new_book_code;
		foreColor(7); cout << "Input Book Code      : "; foreColor(6); cin >> new_book_code;

		ifstream check_file("data/book_information.txt");
		string existing_book_code;
		bool code_exists = false;

		while (getline(check_file, existing_book_code))
		{
			if (existing_book_code == new_book_code)
			{
				code_exists = true;
				break;
			}
		}
		check_file.close();

		if (code_exists)
		{
			foreColor(4);
			cout << "This CODE is already exists."; getch();
			return;
		}
		foreColor(7); cout << "Input Book Title  	: "; foreColor(6); cin.clear(); cin.ignore(); getline(cin, book_title);
		foreColor(7); cout << "Input Book Author    : "; foreColor(6); cin >> book_author;
		foreColor(7); cout << "Input Book Date   	: "; foreColor(6); cin >> book_date;
		foreColor(7); cout << "Input Book Qty    	: "; foreColor(6); cin >> book_qty;
		id++;

		ofstream book_file("data/book_information.txt", ios::app);
		book_file << endl << new_book_code << "\n" << book_title << "\n" << book_author << "\n" << book_date << "\n" << book_qty;
		book_file.close();

		book_file.open("data/ID_book.txt");
		book_file << id;
		book_file.close();

		cout << "SAVE COMPLITE!";
	}

	// =============== SHOW BOOK ===============
	void show_book(BookData b)
	{
		int i;
		drawBoxSingleLine(9, 6 * i, 30 + book_title.length(), 7);
		foreColor(3); gotoxy(5, 7 * i + 2); cout << "Book Code          :  " ; foreColor(6);cout << b.book_code << endl;
		foreColor(3); gotoxy(5, 7 * i + 3); cout << "Book Title         :  " ; foreColor(1);cout <<b.book_title << endl;
		foreColor(3); gotoxy(5, 7 * i + 4); cout << "Book Author        :  " ; foreColor(1);cout <<b.book_author << endl;
		foreColor(3); gotoxy(5, 7 * i + 5); cout << "Book Date          :  " ; foreColor(1);cout <<b.book_date << endl;
		foreColor(3); gotoxy(5, 7 * i + 6); cout << "Book Quantity      :  " ; foreColor(1);cout <<b.book_qty << endl;
		foreColor(3); gotoxy(5, 7 * i + 7); cout << "Book Status        :  " ; foreColor(1);cout << Check_Book_Staus(b.book_qty) << endl;
	}

	void show_book(BookData b, int i)
	{
		foreColor(3); gotoxy(8, 8 * i  + 3); cout << "Book Code          :  " ; foreColor(6);cout << b.book_code << endl;
		foreColor(3); gotoxy(8, 8 * i  + 4); cout << "Book Title         :  " ; foreColor(1);cout <<b.book_title << endl;
		foreColor(3); gotoxy(8, 8 * i  + 5); cout << "Book Author        :  " ; foreColor(1);cout <<b.book_author << endl;
		foreColor(3); gotoxy(8, 8 * i  + 6); cout << "Book Date          :  " ; foreColor(1);cout <<b.book_date << endl;
		foreColor(3); gotoxy(8, 8 * i  + 7); cout << "Book Quantity      :  " ; foreColor(1);cout <<b.book_qty << endl;
		foreColor(3); gotoxy(8, 8 * i  + 8); cout << "Book Status        :  " ; foreColor(1);cout << Check_Book_Staus(b.book_qty) << endl;

		// drawBoxSingleLine(3, (7 * i) + (2*i), 100, 7);
	}

	// =============== SHOW BOOK LIST ===============
	void show_book_list()
	{
		BookData book;
		int line = 0, index = 0;
		ifstream book_file;
		book_file.open("data/book_information.txt");

		while (!book_file.eof())
		{
			book_file >> book.book_code;
			book_file.ignore(); getline(book_file, book.book_title);
			book_file >> book.book_author >> book.book_date >> book.book_qty;

			index++;

			foreColor(6);
			gotoxy(10, 8 * index + 2);
			cout << "No. " << index << endl;
			show_book(book, index);
		}
			book_file.close();
		
	}

	// =============== SEARCH BOOK ===============
	string searchBook()
	{
		BookData book;
		string search;
		int found = 0, index = 0;;

		drawBoxSingleLine(38, 4, 10, 1);
		gotoxy(22, 5);
		cout << "Input Book Code";
		gotoxy(39, 5);
		cin >> search;

		ifstream book_file;
		book_file.open("data/book_information.txt");

		while (!book_file.eof())
		{
			book_file >> book.book_code;
			book_file.ignore();
			getline(book_file, book.book_title);
			book_file >> book.book_author >> book.book_date >> book.book_qty;

			// Compare the book code with the search input
			if (book.book_code == search)
			{
				index++;

				foreColor(6);
				gotoxy(10, 7 * index + 1);
				cout << "No. " << index << endl;

				show_book(book, index);
				found = 1;
				break;
			}

			// Move to the next line in the file
			book_file.ignore(1000, '\n');
		}

		book_file.close();

		if (found == 0)
		{
			foreColor(4);
			gotoxy(30, 7);
			cout << "Book Not Found!" << endl;
		}

		return search;
	}
	// =============== SORT BOOK [QTY] ===============
	void sortBookByQTY()
	{
		int n=0, found = 0;
		BookData B[MAX], objBtmp;
		ofstream Book_Tmp;
		Book_Tmp.open("data/temp.txt");
		ifstream book_file;
		book_file.open("data/book_information.txt");

		while (!book_file.eof())
		{

			book_file >> B[n].book_code;
			book_file.ignore(); getline(book_file, B[n].book_title);
			book_file >> B[n].book_author >> B[n].book_date >> B[n].book_qty;
			n++;

		}
		for (int i = 0; i < n; i++)
		{
			for (int j = i + 1; j < n; j++)
			{
				if ( B[i].book_qty < B[j].book_qty )
				{
					objBtmp = B[i];
					B[i] = B[j];
					B[j] = objBtmp;
					found = 1;
				}
			}
		}
		for(int i = 0; i < n; i++)
		{
			Book_Tmp << "\n" << B[i].book_code 
					<< "\n" << B[i].book_title 
					<< "\n" << B[i].book_author 
					<< "\n" << B[i].book_date 
					<< "\n" << B[i].book_qty;
		}
			book_file.close();
			Book_Tmp.close();
			remove("data/book_information.txt");
			rename("data/temp.txt", "data/book_information.txt");

		if(found == 1) { foreColor(2); cout << "\n\t[SORT COMPLETED!]"; } else { foreColor(4); cout << "\n\t[SORT NOT COMPLETE!]"; }
	}
	// =============== SORT BOOK [CODE] ===============
	void sortBookByCODE()
	{
		int n=0, found = 0;
		BookData B[MAX], objBtmp;
		ofstream Book_Tmp;
		Book_Tmp.open("data/temp.txt");
		ifstream book_file;
		book_file.open("data/book_information.txt");

		while (!book_file.eof())
		{

			book_file >> B[n].book_code;
			book_file.ignore(); getline(book_file, B[n].book_title);
			book_file >> B[n].book_author >> B[n].book_date >> B[n].book_qty;
			n++;

		}
		for (int i = 0; i < n; i++)
		{
			for (int j = i + 1; j < n; j++)
			{
				if ( B[i].book_code > B[j].book_code )
				{
					objBtmp = B[i];
					B[i] = B[j];
					B[j] = objBtmp;
					found = 1;
				}
			}
		}
		for(int i = 0; i < n; i++)
		{
			Book_Tmp << "\n" << B[i].book_code 
					<< "\n" << B[i].book_title 
					<< "\n" << B[i].book_author 
					<< "\n" << B[i].book_date 
					<< "\n" << B[i].book_qty;
		}
			book_file.close();
			Book_Tmp.close();
			remove("data/book_information.txt");
			rename("data/temp.txt", "data/book_information.txt");

		if(found == 1) { foreColor(2); cout << "\n\t[SORT COMPLETED!]"; } else { foreColor(4); cout << "\n\t[SORT NOT COMPLETE!]"; }
	}
	
	// =============== UPDATE BOOK ===============
	void updateBook()
	{
		
		string code = searchBook();
		char update_op;
		cout << "\n\tYou want to update this Book Data (y/n) : "; cin >> update_op;
		if(update_op == 'y' || update_op == 'Y')
		{
			BookData NewBook;
			cout << "\tInput Book Title  	: "; cin.clear(); cin.ignore(); getline(cin, NewBook.book_title);
			cout << "\tInput Book Author    : "; cin.clear(); cin.ignore(); getline(cin, NewBook.book_author);
			cout << "\tInput Book Date   	: "; cin >> NewBook.book_date;
			cout << "\tInput Book Qty    	: "; cin >> NewBook.book_qty;
			BookData book;
			ofstream Book_Tmp;
			Book_Tmp.open("data/temp.txt");
			ifstream book_file;
			book_file.open("data/book_information.txt");

			while(!book_file.eof())
			{
				book_file >> book.book_code;
				book_file.ignore();
				getline(book_file, book.book_title);
				book_file >> book.book_author >> book.book_date >> book.book_qty;

				NewBook.book_code = book.book_code;

				if(book.book_code != code)
				{
				
					Book_Tmp<< "\n" << book.book_code 
							<< "\n" << book.book_title 
							<< "\n" << book.book_author 
							<< "\n" << book.book_date 
							<< "\n" << book.book_qty;
				}
				else
				{
					Book_Tmp << "\n" << NewBook.book_code 
							<< "\n" << NewBook.book_title 
							<< "\n" << NewBook.book_author 
							<< "\n" << NewBook.book_date 
							<< "\n" << NewBook.book_qty;
					
				}
			}
			book_file.close();
			Book_Tmp.close();
			remove("data/book_information.txt");
			rename("data/temp.txt", "data/book_information.txt");
			foreColor(2);
			cout << "\n\t[UPDATE COMPLETED!]";
		}
		else
		{
			foreColor(4);
			cout << "\n\t[UPDATE NOT COMPLETED!]";
		}
	}

	// =============== DELETE BOOK ===============
	void deleteBook()
	{
		char del_op;
		string code = searchBook();
		cout << "\n\tYou want to delete this Book Data (y/n) : "; cin >> del_op;
		if(del_op == 'y' || del_op == 'Y')
		{
			BookData book;
			ofstream Book_Tmp;
			Book_Tmp.open("data/temp.txt");
			ifstream book_file;
			book_file.open("data/book_information.txt");
			while(!book_file.eof())
			{
				book_file >> book.book_code;
				book_file.ignore();
				getline(book_file, book.book_title);
				book_file >> book.book_author >> book.book_date >> book.book_qty;
				
				if(code != book.book_code)
				{
					Book_Tmp << "\n" << book.book_code 
							<< "\n" << book.book_title 
							<< "\n" << book.book_author
							<< "\n" << book.book_date
							<< "\n" << book.book_qty;
				}
			}
			book_file.close();
			Book_Tmp.close();
			remove("data/book_information.txt");
			rename("data/temp.txt", "data/book_information.txt");
			foreColor(2);
			cout << "\n\t[DELETE COMPLETED!]";
		}
		else
		{
			foreColor(4);
			cout << "\n\t[DELETE NOT COMPLETED!]";
		}
	}

};
// *===================================================
// *             *____ Reader ____*
// *===================================================
class ReaderData
{
protected:
	int borrow_count;
	string rid, phone, name, date, type, status;

public:
	ReaderData()
	{
		borrow_count = 0;
		rid = "Unknow";
		name = "Unknow";
		phone = "Unknow";
		date = "Unknow";
		type = "Unknow";
		status = "...";
	}
	string getId()
	{
		return rid;
	}
	string getName()
	{
		return name;
	}
	string getPhone()
	{
		return phone;
	}
	string getType()
	{
		return type;
	}
	string getRDate()
	{
		return date;
	}
	string getStatus()
	{
		return status;
	}
	void setID(string id)
	{
		this->rid = id;
	}
	void setNAME(string name)
	{
		this->name = name;
	}
	void setPHONE(string phone)
	{
		this->phone = phone;
	}
	void setTYPE(string type)
	{
		this->type = type;
	}
	void setRDATE(string date)
	{
		this->date = date;
	}
	string Check_Reader_Staus(int t)
	{
		if (t == 0)
		{
			foreColor(4);
			status = "Not Borrow";
		}
		if (t > 0)
		{
			foreColor(2);
			status = "Borrower";
		}
		return status;
	}
	void input_reader()
	{
		string new_reader_id;
	check_id:
		foreColor(7); cout << "Input Reader ID    : "; foreColor(6); cin >> new_reader_id;
		ifstream check_file("data/reader_information.txt");
		string existing_reader_id;
		bool code_exists = false;
		while (getline(check_file, existing_reader_id))
		{
			if (existing_reader_id == new_reader_id)
			{
				code_exists = true;
				break;
			}
		}
		check_file.close();
		if (code_exists)
		{
			foreColor(4);
			cout << "This ID is already exists."; getch();
			goto check_id;
			return;
		}
		foreColor(7); cout << "Input Reader Name  : "; foreColor(6); cin.clear(); cin.ignore(); getline(cin, name);
		foreColor(7); cout << "Input Reader Phone : "; foreColor(6); cin >> phone;
		foreColor(7); cout << "Input Reader Type  : "; foreColor(6); cin >> type;
		foreColor(7); cout << "Input Reader Date  : "; foreColor(6); cin >> date;
		id++;
		ofstream reader_file("data/reader_information.txt", ios::app);
		reader_file << endl << new_reader_id
					<< "\t" << name 
					<< "\t" << phone 
					<< "\t" << type 
					<< "\t" << date;
		reader_file.close();
		reader_file.open("data/ID_reader.txt");
		reader_file << id;
		reader_file.close();
		cout << "SAVE COMPLITE!";
	}
	// =============== HEADER ===============
	void reader_header()
	{
		foreColor(4);
		drawBoxSingleLine(9, 3, 100, 1);
		gotoxy(10, 4);
		foreColor(7);
		cout << left
			 << setw(10) << "ID"
			 << setw(17) << "NAME"
			 << setw(20) << "PHONE NUMBER"
			 << setw(17) << "TYPE"
			 << setw(17) << "DATE"
			 << setw(17) << "SRATUS";
	}
	// =============== SHOW READER (RETURN DATA) ===============
	void show_reader(ReaderData r, int i)
	{
		foreColor(6);
		gotoxy(10, 7 + i);
		cout << left 
				<< setw(10) << r.rid 
				<< setw(17) << r.name 
				<< setw(20) << r.phone 
				<< setw(17) << r.type 
				<< setw(17) << r.date
				<< setw(17) << Check_Reader_Staus(r.borrow_count);
	}
	// =============== SHOW READER LIST ===============
	void show_reader_list()
	{
		ReaderData reader;
		int index = 0;
		ifstream reader_file;
		reader_file.open("data/reader_information.txt");
		reader_header();
		while (!reader_file.eof())
		{
			reader_file >> reader.rid >> reader.name >> reader.phone >> reader.type >> reader.date;
			foreColor(6);
			show_reader(reader, index);
			index++;
		}
		reader_file.close();
		drawBoxSingleLine(9, 6, 100, index);
	}
	// =============== SEARCH READER ===============
	string searchReader()
	{
		ReaderData reader;
		string search;
		int found = 0, index = 0;;
		drawBoxSingleLine(38, 4, 10, 1);
		gotoxy(22, 5); cout << "Input Reader ID";
		gotoxy(39, 5); cin >> search;
		ifstream reader_file;
		reader_file.open("data/reader_information.txt");

		reader_header();
		while (!reader_file.eof())
		{
			reader_file >> reader.rid >> reader.name >> reader.phone >> reader.type >> reader.date;
			if (reader.rid == search)
			{
				found = 1;
				foreColor(6);
				show_reader(reader, index);
				index++;
			}
			drawBoxSingleLine(9, 6, 100, index);
			// reader_file.ignore(1000, '\n');
		}
		reader_file.close();
		if (found == 0)
		{
			foreColor(4);
			gotoxy(30, 7);
			cout << "Reader Not Found!" << endl;
		}
		return search;
	}
	// =============== SORT READER [ID]===============
	void sortReaderByID()
	{
		int n=0, found = 0;
		ReaderData R[MAX], objRtmp;
		ofstream Reader_Tmp;
		Reader_Tmp.open("data/temp.txt");
		ifstream reader_file;
		reader_file.open("data/reader_information.txt");

		while (!reader_file.eof())
		{

			reader_file >> R[n].rid >> R[n].name >> R[n].phone >> R[n].type >> R[n].date;
			n++;

		}
		for (int i = 0; i < n; i++)
		{
			for (int j = i + 1; j < n; j++)
			{
				if ( R[i].rid > R[j].rid )
				{
					objRtmp = R[i];
					R[i] = R[j];
					R[j] = objRtmp;
					found = 1;
				}
			}
		}

		for(int i = 0; i < n; i++)
		{
			Reader_Tmp << "\n" << R[i].rid
					<< "\n" << R[i].name
					<< "\n" << R[i].phone
					<< "\n" << R[i].type
					<< "\n" << R[i].date;
		}
			reader_file.close();
			Reader_Tmp.close();
			remove("data/reader_information.txt");
			rename("data/temp.txt", "data/reader_information.txt");

		if(found == 1) { foreColor(2); cout << "\n\t[SORT COMPLETED!]"; } else { foreColor(4); cout << "\n\t[SORT NOT COMPLETE!]"; }
	}
	// =============== SORT READER [NAME] ===============
	
	void sortReaderByNAME()
	{
		int n=0, found = 0;
		ReaderData R[MAX], objRtmp;
		ofstream Reader_Tmp;
		Reader_Tmp.open("data/temp.txt");
		ifstream reader_file;
		reader_file.open("data/reader_information.txt");

		while (!reader_file.eof())
		{

			reader_file >> R[n].rid >> R[n].name >> R[n].phone >> R[n].type >> R[n].date;
			n++;

		}
		for (int i = 0; i < n; i++)
		{
			for (int j = i + 1; j < n; j++)
			{
				if ( R[i].rid > R[j].rid )
				{
					objRtmp = R[i];
					R[i] = R[j];
					R[j] = objRtmp;
					found = 1;
				}
			}
		}

		for(int i = 0; i < n; i++)
		{
			Reader_Tmp << "\n" << R[i].rid
					<< "\n" << R[i].name
					<< "\n" << R[i].phone
					<< "\n" << R[i].type
					<< "\n" << R[i].date;
		}
			reader_file.close();
			Reader_Tmp.close();
			remove("data/reader_information.txt");
			rename("data/temp.txt", "data/reader_information.txt");

		if(found == 1) { foreColor(2); cout << "\n\t[SORT COMPLETED!]"; } else { foreColor(4); cout << "\n\t[SORT NOT COMPLETE!]"; }
	}
	// =============== UPDATE READER ===============
	void updateReader()
	{
		char update_op;
		string R_id = searchReader();
		
		cout << "\n\tYou want to update this Reader Data (y/n) : "; cin >> update_op;
		if(update_op == 'y' || update_op == 'Y')
		{
			ReaderData NewReader;;
			foreColor(7); cout << "Input Reader Name  : "; foreColor(6); cin.clear(); cin.ignore(); getline(cin, NewReader.name);
			foreColor(7); cout << "Input Reader Phone : "; foreColor(6); cin >> NewReader.phone;
			foreColor(7); cout << "Input Reader Type  : "; foreColor(6); cin >> NewReader.type;
			foreColor(7); cout << "Input Reader Date  : "; foreColor(6); cin >> NewReader.date;

			ReaderData reader;
			ofstream Reader_Tmp;
			Reader_Tmp.open("data/temp.txt");
			ifstream reader_file;
			reader_file.open("data/reader_information.txt");

			while(!reader_file.eof())
			{
				reader_file >> reader.rid >> reader.name >> reader.phone >> reader.type >> reader.date;

				NewReader.rid = reader.rid;
				
				if(R_id != reader.rid)
				{
					Reader_Tmp << endl << reader.rid
								<< "\t" << reader.name 
								<< "\t" << reader.phone 
								<< "\t" << reader.type 
								<< "\t" << reader.date;
				}
				else
				{
					Reader_Tmp << endl << NewReader.rid
								<< "\t" << NewReader.name 
								<< "\t" << NewReader.phone 
								<< "\t" << NewReader.type 
								<< "\t" << NewReader.date;
				}
			}

			 
			reader_file.close();
			Reader_Tmp.close();
			remove("data/reader_information.txt");
			rename("data/temp.txt", "data/reader_information.txt");
			foreColor(2);
			cout << "\n\t[UPDATE COMPLETED!]";
		}
		else
		{
			foreColor(4);
			cout << "\n\t[UPDATE NOT COMPLETED!]";
		}
	}
	// =============== DELETE READER ===============
	void deleteReader()
	{
		char del_op;
		string R_id = searchReader();
		cout << "\n\tYou want to delete this Reader Data (y/n) : "; cin >> del_op;
		if(del_op == 'y' || del_op == 'Y')
		{
			ReaderData reader;
			ofstream Reader_Tmp;
			Reader_Tmp.open("data/temp.txt");
			ifstream reader_file;
			reader_file.open("data/reader_information.txt");
			while(!reader_file.eof())
			{
				reader_file >> reader.rid >> reader.name >> reader.phone >> reader.type >> reader.date;
				
				if(R_id != reader.rid)
				{
					Reader_Tmp << endl << reader.rid
								<< "\t" << reader.name 
								<< "\t" << reader.phone 
								<< "\t" << reader.type 
								<< "\t" << reader.date;
				}
			}
			reader_file.close();
			Reader_Tmp.close();
			remove("data/reader_information.txt");
			rename("data/temp.txt", "data/reader_information.txt");
			foreColor(2);
			cout << "\n\t[DELETE COMPLETED!]";
		}
		else
		{
			foreColor(4);
			cout << "\n\t[DELETE NOT COMPLETED!]";
		}
	}
};
// *===================================================
// *             *__Borrow_And_Return__*
// *===================================================

class BorrowerData : protected BookData, ReaderData
{
private:
	string br_id, br_date, br_status;
	string reader_id, book_code;
	int qty;

public:
	BorrowerData()
	{
		br_id = "NULL";
		br_date = "NULL";
	}
	void check_borrower_status();
	void borrow_header()
	{
		foreColor(4);
		drawBoxSingleLine(9, 3, 100, 1);
		gotoxy(10, 4);
		foreColor(7);
		cout << left
			 << setw(10) << "ID"
			 << setw(25) << "READER ID"
			 << setw(17) << "BOOK CODE"
			 << setw(17) << "DATE"
			 << setw(17) << "QUNATITY"
			 << "STATUS";
	}
	void input_borrower()
	{
		char br_op;
		string new_borrower_id;
		clrscr();

		foreColor(8); drawBoxSingleLine(43, 1, 35, 3); gotoxy(45, 3); cout << "[ INPUT BORROWER INFORMATION ]";

		string reader_id = searchReader(); getch();
		cout << "\n\tThis Reader want to Borrow? (y/n) : "; cin >> br_op;
		if(br_op == 'y' || br_op == 'Y')
		{
			clrscr();
			foreColor(8); drawBoxSingleLine(43, 1, 35, 3); gotoxy(45, 3); cout << "[ INPUT BORROWER INFORMATION ]";

			string book_code = searchBook(); getch();

		check_id:
			foreColor(7); cout << "Input Borrower ID    : "; foreColor(6); cin >> new_borrower_id;
			ifstream check_file("data/borrower_information.txt");

			string existing_borrower_id;
			bool code_exists = false;
			while (getline(check_file, existing_borrower_id))
			{
				if (existing_borrower_id == new_borrower_id)
				{
					code_exists = true;
					break;
				}
			}

			check_file.close();

			if (code_exists)
			{
				foreColor(4);
				cout << "This ID is already exists."; getch();
				goto check_id;
				return;
			}

			foreColor(7); cout << "Input Date        : "; foreColor(6); cin >> br_date;
			foreColor(7); cout << "Input QTY of Book : "; foreColor(6); cin >> qty;
			ofstream borrower_file("data/borrower_information.txt", ios::app);

			borrower_file << endl << new_borrower_id
						<< "\t" << reader_id 
						<< "\t" << book_code 
						<< "\t" << br_date 
						<< "\t" << qty;
			borrower_file.close();

			foreColor(2); cout << "SAVE COMPLITE!";
		}
		else 
		{
			foreColor(4); cout << "CANCELED!";
		}
	}
	void show_borrower(BorrowerData br, int i)
	{
		foreColor(6);
		gotoxy(10, 7 + i);
		cout << left 
				<< setw(10) << br.br_id 
				<< setw(25) << br.reader_id 
				<< setw(17) << br.book_code 
				<< setw(17) << br.br_date 
				<< setw(17) << br.qty
				<< setw(17) << br.br_status
				<< endl;
	}
	void show_borrower_list()
	{
		BorrowerData borrower;
		int index = 0;
		ifstream borrower_file;
		borrower_file.open("data/borrower_information.txt");
		borrow_header();
		while (!borrower_file.eof())
		{
			borrower_file  >> borrower.br_id  >> borrower.reader_id  >> borrower.book_code   >> borrower.br_date   >> borrower.qty;
			foreColor(6);
			show_borrower(borrower, index);
			index++;
		}
		borrower_file.close();
		drawBoxSingleLine(9, 6, 100, index);
	}

	string searchBorrower()
	{
		BorrowerData borrower;
		string search;
		int found = 0, index = 0;;
		drawBoxSingleLine(41, 4, 10, 1);
		gotoxy(22, 5); cout << "Input Borrower ID"; gotoxy(43, 5); cin >> search;
		ifstream borrower_file;
		borrower_file.open("data/borrower_information.txt");

		reader_header();
		while (!borrower_file.eof())
		{
			borrower_file  >> borrower.br_id  >> borrower.reader_id  >> borrower.book_code   >> borrower.br_date   >> borrower.qty;
			if (borrower.br_id == search)
			{
				found = 1;
				foreColor(6);
				show_borrower(borrower, index);
				index++;
			}
			drawBoxSingleLine(9, 6, 100, index);
			// reader_file.ignore(1000, '\n');
		}
		borrower_file.close();
		if (found == 0)
		{
			foreColor(4);
			gotoxy(30, 7);
			cout << "Reader Not Found!" << endl;
		}
		return search;
	}
	// =============== SORT READER [ID] ===============
	
	void sortBorrowerByID()
	{
		int n=0, found = 0;
		BorrowerData BR[MAX], objBRtmp;
		ofstream borrower_Tmp;
		borrower_Tmp.open("data/temp.txt");
		ifstream borrower_file;
		borrower_file.open("data/reader_information.txt");

		while (!borrower_file.eof())
		{

			borrower_file >> BR[n].br_id  >> BR[n].reader_id  >> BR[n].book_code   >> BR[n].br_date   >> BR[n].qty;
			n++;

		}
		for (int i = 0; i < n; i++)
		{
			for (int j = i + 1; j < n; j++)
			{
				if ( BR[i].br_id > BR[j].br_id )
				{
					objBRtmp = BR[i];
					BR[i] = BR[j];
					BR[j] = objBRtmp;
					found = 1;
				}
			}
		}

		for(int i = 0; i < n; i++)
		{
			borrower_Tmp << endl << BR[i].br_id
								<< "\t" << BR[i].reader_id
								<< "\t" << BR[i].book_code
								<< "\t" << BR[i].br_date
								<< "\t" << BR[i].qty;
		}
			borrower_file.close();
			borrower_Tmp.close();
			remove("data/borrower_information.txt");
			rename("data/temp.txt", "data/borrower_information.txt");

		if(found == 1) { foreColor(2); cout << "\n\t[SORT COMPLETED!]"; } else { foreColor(4); cout << "\n\t[SORT NOT COMPLETE!]"; }
	}
	// =============== SORT READER [READER DATE] ===============
	void sortBorrowerByDATE()
	{
		int n=0, found = 0;
		BorrowerData BR[MAX], objBRtmp;
		ofstream borrower_Tmp;
		borrower_Tmp.open("data/temp.txt");
		ifstream borrower_file;
		borrower_file.open("data/reader_information.txt");

		while (!borrower_file.eof())
		{

			borrower_file >> BR[n].br_id  >> BR[n].reader_id  >> BR[n].book_code   >> BR[n].br_date   >> BR[n].qty;
			n++;

		}
		for (int i = 0; i < n; i++)
		{
			for (int j = i + 1; j < n; j++)
			{
				if ( BR[i].br_date > BR[j].br_date )
				{
					objBRtmp = BR[i];
					BR[i] = BR[j];
					BR[j] = objBRtmp;
					found = 1;
				}
			}
		}

		for(int i = 0; i < n; i++)
		{
			borrower_Tmp << endl << BR[i].br_id
								<< "\t" << BR[i].reader_id
								<< "\t" << BR[i].book_code
								<< "\t" << BR[i].br_date
								<< "\t" << BR[i].qty;
		}
			borrower_file.close();
			borrower_Tmp.close();
			remove("data/borrower_information.txt");
			rename("data/temp.txt", "data/borrower_information.txt");

		if(found == 1) { foreColor(2); cout << "\n\t[SORT COMPLETED!]"; } else { foreColor(4); cout << "\n\t[SORT NOT COMPLETE!]"; }
	}

	void updateBorrower()
	{
		char update_op;
		string Br_id = searchBorrower();
		cout << "\n\tYou want to delete this Borrower Data (y/n) : "; cin >> update_op;

		if(update_op == 'y' || update_op == 'Y')
		{
			BorrowerData NewBR;
			foreColor(7); cout << "Input New Borrower DATE  : "; foreColor(6); cin >> NewBR.br_date;
			foreColor(7); cout << "Input New Borrower QTY   : "; foreColor(6); cin >> NewBR.qty;

			BorrowerData borrower;
			ofstream borrower_Tmp;
			borrower_Tmp.open("data/temp.txt");
			ifstream borrower_file;
			borrower_file.open("data/reader_information.txt");

			while(!borrower_file.eof())
			{
				borrower_file  >> borrower.br_id  >> borrower.reader_id  >> borrower.book_code   >> borrower.br_date   >> borrower.qty;

				NewBR.br_id = borrower.br_id;
				NewBR.reader_id = borrower.reader_id;
				NewBR.book_code = borrower.book_code;
				
				if(Br_id != borrower.br_id)
				{
					
					borrower_Tmp << endl << borrower.br_id
								<< "\t" << borrower.reader_id
								<< "\t" << borrower.book_code
								<< "\t" << borrower.br_date
								<< "\t" << borrower.qty;
				}
				else
				{
					borrower_Tmp << endl << NewBR.br_id
								<< "\t" << NewBR.reader_id
								<< "\t" << NewBR.book_code
								<< "\t" << NewBR.br_date
								<< "\t" << NewBR.qty;
				}
			}

			borrower_file.close();
			borrower_Tmp.close();
			remove("data/borrower_information.txt");
			rename("data/temp.txt", "data/borrower_information.txt");
			foreColor(2);
			cout << "\n\t[UPDATE COMPLETED!]";
		}
		else
		{
			foreColor(4);
			cout << "\n\t[UPDATE NOT COMPLETED!]";
		}
	}
	void deleteBorrower()
	{
		char del_op;
		string Br_id = searchBorrower();
		cout << "\n\tYou want to delete this Borrower Data (y/n) : "; cin >> del_op;
		if(del_op == 'y' || del_op == 'Y')
		{
			BorrowerData borrower;
			ofstream borrower_Tmp;
			borrower_Tmp.open("data/temp.txt");

			ifstream borrower_file;
			borrower_file.open("data/borrower_information.txt");
			while(!borrower_file.eof())
			{
				borrower_file  >> borrower.br_id  >> borrower.reader_id  >> borrower.book_code   >> borrower.br_date   >> borrower.qty;
				
				if(Br_id != borrower.br_id)
				{
					borrower_Tmp << endl << borrower.br_id
								<< "\t" << borrower.reader_id
								<< "\t" << borrower.book_code
								<< "\t" << borrower.br_date
								<< "\t" << borrower.qty;
				}
			}
			borrower_file.close();
			borrower_Tmp.close();
			remove("data/borrower_information.txt");
			rename("data/temp.txt", "data/borrower_information.txt");
			foreColor(2);
			cout << "\n\t[DELETE COMPLETED!]";
		}
		else
		{
			foreColor(4);
			cout << "\n\t[DELETE NOT COMPLETED!]";
		} 
	}
};
// *===================================================
// *             FUNCTION AND SUBFUNCTION
// *===================================================
// =============== Loading ===============
void Loading()
{
	clrscr();
	hideCursor();
	string line;
	
	ifstream loading_file("data/artText/loading.txt");
	int LDPosX = 3, LDPosY = 3, g = 5;
	while (getline(loading_file, line))
	{
		foreColor(2);
		gotoxy(30, g++);
		cout << line << "\n";
	}
	gotoxy(30 + LDPosX, 10 + LDPosY);
	foreColor(4);
	for (int i = 0; i < 50; i++)
	{
		cout << (char)177;
	}
	gotoxy(30 + LDPosX, 10 + LDPosY);
	foreColor(2);
	for (int i = 0; i < 50; i++)
	{
		cout << (char)219;
		if (i < 8)
		{
			Sleep(5);
		}
		else if (i < 20)
		{
			Sleep(80);
		}
		else
		{
			Sleep(5);
		}
	}
	loading_file.close();
	showCursor();
}
// =============== Header Menu ===============
void header_menu()
{
	ifstream art_file("data/artText/header.txt");
	int HWinPosX = 5, HWinPosY = 10, g = 2;
	string line;
	clrscr();
	foreColor(2);
	while (getline(art_file, line))
	{
		gotoxy(15, g++);
		cout << line << "\n";
	}
	cout << endl;
	art_file.close();
	foreColor(9); DrawRectangle(10, 1, 98, 9, 7);
	foreColor(6);
	gotoxy(37 + HWinPosX, 3 + HWinPosY); cout << "[ LIBRARY - Management System ]";
	gotoxy(23 + HWinPosX, 6 + HWinPosY); cout << "[1]  Book Information";
	gotoxy(60 + HWinPosX, 6 + HWinPosY); cout << "[2]  Reader Information";
	gotoxy(23 + HWinPosX, 8 + HWinPosY); cout << "[3]  Borrower Information";
	gotoxy(60 + HWinPosX, 8 + HWinPosY); cout << "[0]  Exit program";
	foreColor(3); gotoxy(45 + HWinPosX, 10 + HWinPosY); cout << "[R] About";
	foreColor(4); gotoxy(37 + HWinPosX, 12 + HWinPosY); cout << "Please choose one option : "; foreColor(2); cin >> op;
}
// =============== case header ===============
void case__header(string str)
{
	int chPosY = 0, chPosX = 12;
	clrscr();
	foreColor(2);
	DrawRectangle(5 + chPosX, 2 + chPosY, 86, 8);
	foreColor(2);
	gotoxy(37 + chPosX, 2 + chPosY); cout << "[ " << str << " Information ]";
	foreColor(6);
	gotoxy(10 + chPosX, 4 + chPosY); cout << "[1] Input " << str;
	gotoxy(40 + chPosX, 4 + chPosY); cout << "[2] Show " << str;
	gotoxy(70 + chPosX, 4 + chPosY); cout << "[3] Search " << str;
	gotoxy(10 + chPosX, 6 + chPosY); cout << "[4] Sort " << str;
	gotoxy(40 + chPosX, 6 + chPosY); cout << "[5] Update " << str;
	gotoxy(70 + chPosX, 6 + chPosY); cout << "[6] Delete " << str;
	gotoxy(40 + chPosX, 8 + chPosY); cout << "[0] Back to Home\n\n";
	
	DrawRectangle(10 + chPosX, 10 + chPosY, 32, 1);
	foreColor(9);
	gotoxy(10 + chPosX, 11 + chPosY); cout << "Please choose one option:       ";
	gotoxy(36 + chPosX, 11 + chPosY);
}
void clrscr()
{
	system("cls");
}
// =============== HIDE CURSOR ===============
void hideCursor()
{
	HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO info;
	info.dwSize = 100;
	info.bVisible = FALSE;
	SetConsoleCursorInfo(consoleHandle, &info);
}
// =============== SHOW CURSOR ===============
void showCursor()
{
	HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO info;
	info.dwSize = 100;
	info.bVisible = TRUE;
	SetConsoleCursorInfo(consoleHandle, &info);
}
void SetWinConsole()
{
	SetConsoleCP(437);
	SetConsoleOutputCP(437);
	// Get the handle to the console window
	HWND consoleWindow = GetConsoleWindow();
	// Get the current window style
	LONG style = GetWindowLong(consoleWindow, GWL_STYLE);
	// Disable the resize feature by removing the WS_THICKFRAME style
	style = style & ~WS_THICKFRAME;
	// Disable the maximize button by removing the WS_MAXIMIZEBOX style
	style = style & ~WS_MAXIMIZEBOX;
	// Apply the new window style
	SetWindowLong(consoleWindow, GWL_STYLE, style);
	// Get the console screen buffer info
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
	// Set the console window size to the current screen buffer size
	SMALL_RECT sr;
	sr.Left = 0;
	sr.Top = 0;
	sr.Right = csbi.dwSize.X - 1;
	sr.Bottom = csbi.dwSize.Y - 1;
	SetConsoleWindowInfo(GetStdHandle(STD_OUTPUT_HANDLE), TRUE, &sr);
}
bool IsRunAsAdmin()
{
	bool fIsRunAsAdmin = false;
	HANDLE hToken = NULL;
	if (OpenProcessToken(GetCurrentProcess(), TOKEN_QUERY, &hToken))
	{
		TOKEN_ELEVATION elevation;
		DWORD cbSize = sizeof(TOKEN_ELEVATION);
		if (GetTokenInformation(hToken, TokenElevation, &elevation, sizeof(elevation), &cbSize))
		{
			fIsRunAsAdmin = elevation.TokenIsElevated;
		}
	}
	if (hToken)
	{
		CloseHandle(hToken);
	}
	return fIsRunAsAdmin;
}
void SetUpWindowConsole_App()
{
	system("cls & title Library Program - %USERNAME% - %DATE%");
	SetWinConsole();
	if (!IsRunAsAdmin())
	{
		system("title Please Run As Administrator");
		string line;
		ifstream art_file("data/artText/runadmin.txt");
		// Request admin privileges
		foreColor(2);
		while (getline(art_file, line))
		{
			cout << line << "\n";
		}
		art_file.close();
		if (!art_file.eof())
		{
			cout << "Hello User! Please Run As Administrator... ";
		}
		getch();
		//		ShellExecute(NULL, "runas", "main.exe", NULL, NULL, SW_SHOWNORMAL);
				ShellExecute(NULL, "runas", "app.exe", NULL, NULL, SW_SHOWNORMAL);
		exit(0);
	}
}

#endif