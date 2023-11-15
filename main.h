#ifndef A6LIBRARY_MAIN_H
#define A6LIBRARY_MAIN_H

#include <time.h>
#include <math.h>
#include <string>
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
#include <iomanip>
#include <fstream>
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
char op_search, op_sort;
int i, j;
int r = 0, w = 0;
int n = 0, k = 0;
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
		string __username, __password;
		int check_number_count = 0, width = 0, height = 5, g = 3;
		ifstream art_file("data/artText/login.txt");
		string line;
	login_page:
		clrscr();
		while (getline(art_file, line))
		{
			gotoxy(20, g++);
			cout << line << "\n";
		}
		art_file.close();
		cout << endl;
		// user box
		DrawRectangle(50 + width, 5 + height, 20, 1);
		// pass box
		DrawRectangle(50 + width, 9 + height, 20, 1);
		gotoxy(40 + width, 6 + height);
		cout << "USERNAME";
		gotoxy(40 + width, 10 + height);
		cout << "PASSWORD";
		gotoxy(52 + width, 6 + height);
		cin >> __username;
		gotoxy(52 + width, 10 + height);
		cin >> __password;
		if (__username == "RUPP" && __password == "A6")
		{
			gotoxy(20, 12);
			cout << "[ Login Successfully ]";
			getch();
		}
		else
		{
			check_number_count++;
			if (__username == getUsername() && __password == getPassword())
			{
				gotoxy(20, 12);
				cout << "[ Login Successfully ]";
				getch();
			}
			else
			{
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
						cout << "THANK YOU " << (char)3;
						getch();
						exit(0);
					}
				}
				else
				{
					cout << "\nUsername or Password Worng!, Please login again..." << endl;
					getch();
					goto login_page;
				}
			}
		}
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
	void input_book()
	{
		fstream book_file;
		book_file.open("data/book_information.txt", ios::app);
		if (!book_file)
		{
			bop = '0';
		}

		cout << "Input Book Code   : ";
		cin >> book_code; // code
		cout << "Input Book Title  : ";
		cin.clear();
		cin.ignore();
		getline(cin, book_title); // title
		cout << "Input Book Author : ";
		cin >> book_author; // author
		cout << "Input Book Date   : ";
		cin >> book_date; // date 10/03/2023
		cout << "Input Book Qty    : ";
		cin >> book_qty; // qty
		book_file << book_code << "\t" << book_title << "\t" << book_author << "\t" << book_date << "\t" << book_qty << endl;
		book_file.close();
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
			 << setw(17) << "SRATUS" << endl;
	}
	void show_book()
	{
		foreColor(4);
		cout << left
			 << setw(10) << book_code
			 << setw(20) << book_title
			 << setw(17) << book_author
			 << setw(17) << book_date
			 << setw(17) << book_qty
			 << setw(17) << endl;
	}
	void readAndShowBook(fstream &book_file)
	{
		book_file >> book_code >> book_title >> book_author >> book_date >> book_qty;

		foreColor(4);
		cout << left
			 << setw(10) << book_code
			 << setw(20) << book_title
			 << setw(17) << book_author
			 << setw(17) << book_date
			 << setw(17) << book_qty
			 << setw(17) << endl;
	}
	void show_book_list(BookData obj[], int n)
	{
		fstream book_file;
		book_file.open("data/book_information.txt", ios::in);
		if (!book_file)
		{
			bop = '0';
		}
		int line = 0, i = 0;
		book_header();

		while (!book_file.eof())
		{
			// book_file.getline(obj[i].show_book(), n);
			gotoxy(10, 7 + i);
			obj[i].readAndShowBook(book_file);
			i++;
			line++;
		}
		book_file.close();
		drawBoxSingleLine(9, 6, 100, line);
	}
	// *===== SEARCH BOOK =====*
	void searchBook(BookData obj[], int n)
	{
		char op_search;
		string search;
		int line = 0, found;
		do
		{
			clrscr();
			cout << "\n----------------------------------" << endl;
			cout << "\t----> [SEARCH BOOK] <----" << endl;
			cout << "----------------------------------" << endl;
			cout << "\t[1] BY CODE" << endl
				 << "\t[2] BY AUTHOR" << endl
				 << "\t[0] Back" << endl;
			cout << "----------------------------------" << endl;
			cout << ">>> choose one option : ";
			op_search = getch();
			switch (op_search)
			{
			case '1':
			{
				cout << "\nInput Book Code to Search : ";
				cin >> search;
				found = 0;
				line = 0;
				for (int i = 0; i < n; i++)
				{
					if (search == obj[i].getCode())
					{
						found = 1;
						if (i <= 1)
						{
							clrscr();
							book_header();
						}
						line++;
						gotoxy(10, 7 + line);
						obj[i].show_book();
					}
				}
				if (found == 1)
				{
					drawBoxSingleLine(9, 6, 100, line);
					getch();
				}
				if (found == 0)
				{
					cout << "Error : NOT FOUND!" << endl;
					getch();
				}
			}
			break;
			case '2':
			{
				cout << "\nInput Book Author to Search : ";
				cin >> search;
				found = 0;
				line = 0;
				for (int i = 0; i < n; i++)
				{
					if (search == obj[i].getAuthor())
					{
						found = 1;
						if (i <= 1)
						{
							clrscr();
							book_header();
						}
						line++;
						gotoxy(10, 7 + line);
						obj[i].show_book();
					}
				}
				if (found == 1)
				{
					drawBoxSingleLine(9, 6, 100, line);
					getch();
				}
				if (found == 0)
				{
					cout << "Error : NOT FOUND!" << endl;
					getch();
				}
			}
			break;
			default:
				break;
			}
		} while (op_search != '0');
	}
	// *===== SORT BOOK =====*
	void sortBook(BookData obj[], int n)
	{
		BookData objBtmp;
		char op_sort;
		int found;
		do
		{
			clrscr();
			cout << "\n---------------------------------" << endl;
			cout << ">>> [SORT BOOK INFORMATION] <<<" << endl;
			cout << "---------------------------------" << endl;
			cout << "\t[1] Sort By Code" << endl
				 << "\t[2] Sort By Title" << endl
				 << "\t[3] Sort By Author" << endl
				 << "\t[4] Sort By Quantity" << endl
				 << "\t[0] Back" << endl;
			cout << "---------------------------------" << endl;
			cout << "--> Choose one opition : ";
			op_sort = getch();
			switch (op_sort)
			{
			case '1':
			{
				found = 0;
				for (int i = 0; i < n; i++)
				{
					for (int j = i + 1; j < n; j++)
					{
						if (obj[i].getCode() < obj[j].getCode())
						{
							objBtmp = obj[i];
							obj[i] = obj[j];
							obj[j] = objBtmp;
							found = 1;
						}
					}
				}
				if (found == 0)
				{
					cout << "Sort Not Success!" << endl;
					getch();
				}
				else
				{
					cout << "Sort Successfully!" << endl;
					getch();
				}
			}
			break;
			case '2':
			{
				found = 0;
				for (int i = 0; i < n; i++)
				{
					for (int j = i + 1; j < n; j++)
					{
						if (obj[i].getTitle() < obj[j].getTitle())
						{
							objBtmp = obj[i];
							obj[i] = obj[j];
							obj[j] = objBtmp;
							found = 1;
						}
					}
				}
				if (found == 0)
				{
					cout << "Sort Not Success!" << endl;
					getch();
				}
				else
				{
					cout << "Sort Successfully!" << endl;
					getch();
				}
			}
			break;
			case '3':
			{
				found = 0;
				for (int i = 0; i < n; i++)
				{
					for (int j = i + 1; j < n; j++)
					{
						if (obj[i].getAuthor() < obj[j].getAuthor())
						{
							objBtmp = obj[i];
							obj[i] = obj[j];
							obj[j] = objBtmp;
							found = 1;
						}
					}
				}
				if (found == 0)
				{
					cout << "Sort Not Success!" << endl;
					getch();
				}
				else
				{
					cout << "Sort Successfully!" << endl;
					getch();
				}
			}
			break;
			case '4':
			{
				found = 0;
				for (int i = 0; i < n; i++)
				{
					for (int j = i + 1; j < n; j++)
					{
						if (obj[i].getQty() < obj[j].getQty())
						{
							objBtmp = obj[i];
							obj[i] = obj[j];
							obj[j] = objBtmp;
							found = 1;
						}
					}
				}
				if (found == 0)
				{
					cout << "Sort Not Success!" << endl;
					getch();
				}
				else
				{
					cout << "Sort Successfully!" << endl;
					getch();
				}
			}
			break;
			default:
				break;
			}
		} while (op_sort != '0');
	}
	// *===== UPDATE BOOK =====*
	void updateBook(BookData obj[], int n)
	{
		char op_update;
		string search;
		int found, line, a;
		do
		{
			clrscr();
			foreColor(7);
			cout << "----------------------------------" << endl;
			cout << "\t[1] Update By Code" << endl
				 << "\t[2] Update By Author" << endl
				 << "\t[0] Back" << endl;
			cout << "----------------------------------" << endl;
			cout << "--> Choose one option : ";
			op_update = getch();
			switch (op_update)
			{
			case '1':
			{
				line = 0;
				// gotoxy(10, 15);
				cout << "\nInput Book Code to Update : ";
				cin >> search;
				found = 0;
				// Loading();
				for (int i = 0; i < n; i++)
				{
					drawBoxSingleLine(9, 6, 100, line);
					if (search == obj[i].getCode())
					{
						clrscr();
						line++;
						obj->book_header();
						gotoxy(10, 7 + a);
						obj[i].show_book();
						drawBoxSingleLine(9, 6, 100, line);
						found = 1;
						cout << "\n\tPress 'Enter' to Update or 'ESC' to Exit:: ";
						if (getch() == 13)
						{
							a++;
							do
							{
								cout << "\n---------------------------------" << endl
									 << "==== What you want to update ====" << endl
									 << "---------------------------------" << endl
									 << "\t[1] Code\t\t[4] Date" << endl
									 << "\t[2] Title\t\t[5] Qty" << endl
									 << "\t[3] Author\t\t[6] Update All" << endl
									 << "\t\t[0] Back" << endl
									 << "---------------------------------" << endl
									 << "--> Choose one option : ";
								op_update = getch();
								switch (op_update)
								{
								case '1':
								{
									cout << "\n--> Update Code [" << obj[i].getCode() << "] to : ";
									cin >> obj[i].book_code;
								}
								break;
								case '2':
								{
									cout << "\n--> Update Title [" << obj[i].getTitle() << "] to : ";
									cin.clear();
									cin.ignore();
									getline(cin, obj[i].book_title);
								}
								break;
								case '3':
								{
									cout << "\n--> Update Author [" << obj[i].getAuthor() << "] to : ";
									cin >> obj[i].book_author;
								}
								break;
								case '4':
								{
									cout << "\n--> Update Date [" << obj[i].getDate() << "] to : ";
									cin >> obj[i].book_date;
								}
								break;
								case '5':
								{
									cout << "\n--> Update Qty [" << obj[i].getQty() << "] to : ";
									cin >> obj[i].book_qty;
								}
								break;
								case '6':
								{
									cout << "\n--> UPDATE ALL BOOK INFORMATION [CODE:" << obj[i].getCode() << " ]" << endl;
									obj[i].input_book();
								}
								break;
								default:
									break;
								}
							} while (op_update != '0');
						}
						else if (getch() == 27)
						{
							break;
						}
					}
				}
				if (found == 0)
				{
					gotoxy(47, 15);
					cout << "\nError : NOT FOUND!" << endl;
					getch();
				}
			}
			break;
			case '2':
			{
				line = 0;
				cout << "\nInput Book Author to Update : ";
				cin >> search;
				found = 0;
				// Loading();
				for (int i = 0; i < n; i++)
				{
					drawBoxSingleLine(9, 6, 100, line);
					if (search == obj[i].getAuthor())
					{
						clrscr();
						line++;
						obj->book_header();
						gotoxy(10, 7 + a);
						obj[i].show_book();
						drawBoxSingleLine(9, 6, 100, line);
						found = 1;
						cout << "\n\tPress 'Enter' to Update or 'ESC' to Exit:: ";
						if (getch() == 13)
						{
							a++;
							do
							{
								cout << "\n---------------------------------" << endl
									 << "==== What you want to update ====" << endl
									 << "---------------------------------" << endl
									 << "\t[1] Code\t\t[4] Date" << endl
									 << "\t[2] Title\t\t[5] Qty" << endl
									 << "\t[3] Author\t\t[6] Update All" << endl
									 << "\t\t[0] Back" << endl
									 << "---------------------------------" << endl
									 << "--> Choose one option : ";
								op_update = getch();
								switch (op_update)
								{
								case '1':
								{
									cout << "\n--> Update Code [" << obj[i].getCode() << "] to : ";
									cin >> obj[i].book_code;
								}
								break;
								case '2':
								{
									cout << "\n--> Update Title [" << obj[i].getTitle() << "] to : ";
									cin.clear();
									cin.ignore();
									getline(cin, obj[i].book_title);
								}
								break;
								case '3':
								{
									cout << "\n--> Update Author [" << obj[i].getAuthor() << "] to : ";
									cin >> obj[i].book_author;
								}
								break;
								case '4':
								{
									cout << "\n--> Update Date [" << obj[i].getDate() << "] to : ";
									cin >> obj[i].book_date;
								}
								break;
								case '5':
								{
									cout << "\n--> Update Qty [" << obj[i].getQty() << "] to : ";
									cin >> obj[i].book_qty;
								}
								break;
								case '6':
								{
									cout << "\n--> UPDATE ALL BOOK INFORMATION [CODE:" << obj[i].getCode() << " ]" << endl;
									obj[i].input_book();
								}
								break;
								default:
									break;
								}
							} while (op_update != '0');
						}
						else if (getch() == 27)
						{
							break;
						}
					}
				}
				if (found == 0)
				{
					gotoxy(47, 15);
					cout << "Error : NOT FOUND!" << endl;
					getch();
				}
			}
			break;
			default:
				break;
			}
		} while (op_update != '0');
	}
	void deleteBook(BookData obj[], int n)
	{
		char delete_op;
		string del_code, del_title;
		int found;
		clrscr();
		cout << "\n---------------------------------" << endl;
		cout << ">>> [DELETE BOOK INFORMATION] <<<" << endl;
		cout << "---------------------------------" << endl;
		cout << "\t[1] Delete By Code" << endl
			 << "\t[2] Delete By Title" << endl
			 << "\t[0] Back" << endl;
		cout << "---------------------------------" << endl;
		cout << "--> Choose one opition : ";
		delete_op = getch();
		switch (delete_op)
		{
		case '1':
		{
			cout << "Enter Book Code to Delete : ";
			cin >> del_code;
			for (int i = 0; i < n; i++)
			{
				if (del_code == obj[i].getCode())
				{
					for (int j = i; j < n; j++)
					{
						obj[i] = obj[j + 1];
					}
					n--;
					found = 1;
				}
			}
			if (found == 0)
			{
				cout << "Delete Not Success!" << endl;
				getch();
			}
			else
			{
				cout << "Delete Successfully!" << endl;
				getch();
			}
		}
		break;
		case '2':
		{
			cout << "Enter Book Title to Delete : ";
			cin >> del_code;
			for (int i = 0; i < n; i++)
			{
				if (del_code == obj[i].getTitle())
				{
					for (int j = i; j < n; j++)
					{
						obj[i] = obj[j + 1];
					}
					n--;
					found = 1;
				}
			}
			if (found == 0)
			{
				cout << "Delete Not Success!" << endl;
				getch();
			}
			else
			{
				cout << "Delete Successfully!" << endl;
				getch();
			}
		}
		break;
		default:
			break;
		}
	}
};
// *===================================================
// *             *____ Reader ____*
// *===================================================
class ReaderData
{
protected:
	string rid, phone, name, date, type, status;

public:
	ReaderData()
	{
		rid = "Unknow";
		name = "Unknow";
		phone = "Unknow";
		date = "Unknow";
		type = "Unknow";
		status = "No Status";
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
	void input_reader()
	{
		cout << "Input Reader Id    : ";
		cin >> rid;
		cout << "Input Reader Name  : ";
		cin.clear();
		cin.ignore();
		getline(cin, name);
		cout << "Input Reader Phone : ";
		cin >> phone;
		cout << "Input Reader Type  : ";
		cin >> type;
		cout << "Input Reader Date  : ";
		cin >> date;
	}
	void reader_header()
	{
		foreColor(4);
		drawBoxSingleLine(9, 3, 100, 1);
		gotoxy(10, 4);
		foreColor(7);
		cout << "\t" << left
			 << setw(10) << "ID"
			 << setw(17) << "NAME"
			 << setw(20) << "PHONE NUMBER"
			 << setw(17) << "TYPE"
			 << setw(17) << "DATE"
			 << setw(17) << "SRATUS" << endl;
	}
	void show_reader()
	{
		foreColor(4);
		cout << left
			 << setw(17) << rid
			 << setw(17) << name
			 << setw(17) << phone
			 << setw(17) << type
			 << setw(17) << date
			 << setw(17) << endl;
	}
	void show_reader_list(ReaderData obj[], int r)
	{
		int line = 0;
		reader_header();
		for (int i = 0; i < r; i++)
		{
			gotoxy(10, 7 + i);
			obj[i].show_reader();
			line++;
		}
		drawBoxSingleLine(9, 6, 100, line);
	}
	// *===== SEARCH READER =====*
	void searchReader(ReaderData obj[], int r)
	{
		char op_search;
		string search;
		int line = 0, found;
		do
		{
			clrscr();
			cout << "\n----------------------------------" << endl;
			cout << "\t----> [SEARCH READER] <----" << endl;
			cout << "----------------------------------" << endl;
			cout << "\t[1] BY ID" << endl
				 << "\t[2] BY NAME" << endl
				 << "\t[0] Back" << endl;
			cout << "----------------------------------" << endl;
			cout << ">>> choose one option : ";
			op_search = getch();
			switch (op_search)
			{
			case '1':
			{
				cout << "\nInput Reader ID to Search : ";
				cin >> search;
				found = 0;
				line = 0;
				for (int i = 0; i < n; i++)
				{
					if (search == obj[i].getId())
					{
						found = 1;
						if (i <= 1)
						{
							clrscr();
							reader_header();
						}
						line++;
						gotoxy(10, 7 + line);
						obj[i].show_reader();
					}
				}
				if (found == 1)
				{
					drawBoxSingleLine(9, 6, 100, line);
					getch();
				}
				if (found == 0)
				{
					cout << "Error : NOT FOUND!" << endl;
					getch();
				}
			}
			break;
			case '2':
			{
				cout << "\nInput Reader NAME to Search : ";
				cin >> search;
				found = 0;
				line = 0;
				for (int i = 0; i < n; i++)
				{
					if (search == obj[i].getName())
					{
						found = 1;
						if (i <= 1)
						{
							clrscr();
							reader_header();
						}
						line++;
						gotoxy(10, 7 + line);
						obj[i].show_reader();
					}
				}
				if (found == 1)
				{
					drawBoxSingleLine(9, 6, 100, line);
					getch();
				}
				if (found == 0)
				{
					cout << "Error : NOT FOUND!" << endl;
					getch();
				}
			}
			break;
			default:
				break;
			}
		} while (op_search != '0');
	}
	// *===== SORT READER =====*
	void sortReader(ReaderData obj[], int r)
	{
		ReaderData objtmp;
		char op_sort;
		int found;
		do
		{
			clrscr();
			cout << "\n---------------------------------" << endl;
			cout << ">>> [SORT READER INFORMATION] <<<" << endl;
			cout << "---------------------------------" << endl;
			cout << "\t[1] Sort By ID" << endl
				 << "\t[2] Sort By NAME" << endl
				 << "\t[3] Sort By TYPE" << endl
				 << "\t[0] Back" << endl;
			cout << "---------------------------------" << endl;
			cout << "--> Choose one opition : ";
			op_sort = getch();
			switch (op_sort)
			{
			case '1':
			{
				found = 0;
				for (int i = 0; i < r; i++)
				{
					for (int j = i + 1; j < r; j++)
					{
						if (obj[i].getId() < obj[j].getId())
						{
							objtmp = obj[i];
							obj[i] = obj[j];
							obj[j] = objtmp;
							found = 1;
						}
					}
				}
				if (found == 0)
				{
					cout << "Sort Not Success!" << endl;
					getch();
				}
				else
				{
					cout << "Sort Successfully!" << endl;
					getch();
				}
			}
			break;
			case '2':
			{
				found = 0;
				for (int i = 0; i < r; i++)
				{
					for (int j = i + 1; j < r; j++)
					{
						if (obj[i].getName() < obj[j].getName())
						{
							objtmp = obj[i];
							obj[i] = obj[j];
							obj[j] = objtmp;
							found = 1;
						}
					}
				}
				if (found == 0)
				{
					cout << "Sort Not Success!" << endl;
					getch();
				}
				else
				{
					cout << "Sort Successfully!" << endl;
					getch();
				}
			}
			break;
			case '3':
			{
				found = 0;
				for (int i = 0; i < r; i++)
				{
					for (int j = i + 1; j < r; j++)
					{
						if (obj[i].getType() < obj[j].getType())
						{
							objtmp = obj[i];
							obj[i] = obj[j];
							obj[j] = objtmp;
							found = 1;
						}
					}
				}
				if (found == 0)
				{
					cout << "Sort Not Success!" << endl;
					getch();
				}
				else
				{
					cout << "Sort Successfully!" << endl;
					getch();
				}
			}
			break;
			default:
				break;
			}
		} while (op_sort != '0');
	}
	// *===== UPDATE READER =====*
	void updateReder(ReaderData obj[], int r)
	{
		char op_update;
		string search;
		int found, line, a = 0;
		do
		{
			clrscr();
			foreColor(7);
			cout << "----------------------------------" << endl;
			cout << "\t[1] Update By Code" << endl
				 << "\t[2] Update By Author" << endl
				 << "\t[0] Back" << endl;
			cout << "----------------------------------" << endl;
			cout << "--> Choose one option : ";
			op_update = getch();
			switch (op_update)
			{
			case '1':
			{
				line = 0;
				// gotoxy(10, 15);
				cout << "\nInput Reader ID to Update : ";
				cin >> search;
				found = 0;
				// Loading();
				for (int i = 0; i < n; i++)
				{
					drawBoxSingleLine(9, 6, 100, line);
					if (search == obj[i].getId())
					{
						clrscr();
						line++;
						obj->reader_header();
						gotoxy(10, 7 + a);
						obj[i].show_reader();
						drawBoxSingleLine(9, 6, 100, line);
						found = 1;
						cout << "\n\tPress 'Enter' to Update or 'ESC' to Exit:: ";
						if (getch() == 13)
						{
							a++;
							do
							{
								cout << "\n---------------------------------" << endl
									 << "==== What you want to update ====" << endl
									 << "---------------------------------" << endl
									 << "\t[1] Id\t\t[4] Type" << endl
									 << "\t[2] Name\t\t[5] Date" << endl
									 << "\t[3] Phone\t\t[6] Update All" << endl
									 << "\t\t[0] Back" << endl
									 << "---------------------------------" << endl
									 << "--> Choose one option : ";
								op_update = getch();
								switch (op_update)
								{
								case '1':
								{
									cout << "\n--> Update Id [" << obj[i].getId() << "] to : ";
									cin >> obj[i].rid;
								}
								break;
								case '2':
								{
									cout << "\n--> Update Name [" << obj[i].getName() << "] to : ";
									cin.clear();
									cin.ignore();
									getline(cin, obj[i].name);
								}
								break;
								case '3':
								{
									cout << "\n--> Update Phone [" << obj[i].getPhone() << "] to : ";
									cin >> obj[i].phone;
								}
								break;
								case '4':
								{
									cout << "\n--> Update Date [" << obj[i].getType() << "] to : ";
									cin >> obj[i].type;
								}
								break;
								case '5':
								{
									cout << "\n--> Update Qty [" << obj[i].getRDate() << "] to : ";
									cin >> obj[i].date;
								}
								break;
								case '6':
								{
									cout << "\n--> UPDATE ALL BOOK INFORMATION [CODE:" << obj[i].getId() << " ]" << endl;
									obj[i].input_reader();
								}
								break;

								default:
									break;
								}
							} while (op_update != '0');
						}
						else if (getch() == 27)
						{
							break;
						}
					}
				}
				if (found == 0)
				{
					gotoxy(47, 15);
					cout << "\nError : NOT FOUND!" << endl;
					getch();
				}
			}
			break;
			case '2':
			{
				line = 0;
				// gotoxy(10, 15);
				cout << "\nInput Reader Name to Update : ";
				cin >> search;
				found = 0;
				// Loading();
				for (int i = 0; i < n; i++)
				{
					drawBoxSingleLine(9, 6, 100, line);
					if (search == obj[i].getName())
					{
						clrscr();
						line++;
						obj->reader_header();
						gotoxy(10, 7 + a);
						obj[i].show_reader();
						drawBoxSingleLine(9, 6, 100, line);
						found = 1;
						cout << "\n\tPress 'Enter' to Update or 'ESC' to Exit:: ";
						if (getch() == 13)
						{
							a++;
							do
							{
								cout << "\n---------------------------------" << endl
									 << "==== What you want to update ====" << endl
									 << "---------------------------------" << endl
									 << "\t[1] Id\t\t[4] Type" << endl
									 << "\t[2] Name\t\t[5] Date" << endl
									 << "\t[3] Phone\t\t[6] Update All" << endl
									 << "\t\t[0] Back" << endl
									 << "---------------------------------" << endl
									 << "--> Choose one option : ";
								op_update = getch();
								switch (op_update)
								{
								case '1':
								{
									cout << "\n--> Update Id [" << obj[i].getId() << "] to : ";
									cin >> obj[i].rid;
								}
								break;
								case '2':
								{
									cout << "\n--> Update Name [" << obj[i].getName() << "] to : ";
									cin.clear();
									cin.ignore();
									getline(cin, obj[i].name);
								}
								break;
								case '3':
								{
									cout << "\n--> Update Phone [" << obj[i].getPhone() << "] to : ";
									cin >> obj[i].phone;
								}
								break;
								case '4':
								{
									cout << "\n--> Update Date [" << obj[i].getType() << "] to : ";
									cin >> obj[i].type;
								}
								break;
								case '5':
								{
									cout << "\n--> Update Qty [" << obj[i].getRDate() << "] to : ";
									cin >> obj[i].date;
								}
								break;
								case '6':
								{
									cout << "\n--> UPDATE ALL BOOK INFORMATION [CODE:" << obj[i].getId() << " ]" << endl;
									obj[i].input_reader();
								}
								break;

								default:
									break;
								}
							} while (op_update != '0');
						}
						else if (getch() == 27)
						{
							break;
						}
					}
				}
				if (found == 0)
				{
					gotoxy(47, 15);
					cout << "\nError : NOT FOUND!" << endl;
					getch();
				}
			}
			break;

			default:
				break;
			}
		} while (op_update != '0');
	}
	// *===== DELETE READER =====*
	void deleteReader(ReaderData obj[], int r)
	{
		char delete_op;
		string del_code, del_title;
		int found;
		clrscr();
		cout << "\n---------------------------------" << endl;
		cout << ">>> [DELETE READER INFORMATION] <<<" << endl;
		cout << "---------------------------------" << endl;
		cout << "\t[1] Delete By ID" << endl
			 << "\t[2] Delete By NAME" << endl
			 << "\t[0] Back" << endl;
		cout << "---------------------------------" << endl;
		cout << "--> Choose one opition : ";
		delete_op = getch();
		switch (delete_op)
		{
		case '1':
		{
			cout << "Enter Reader ID to Delete : ";
			cin >> del_code;
			for (int i = 0; i < n; i++)
			{
				if (del_code == obj[i].getId())
				{
					for (int j = i; j < r; j++)
					{
						obj[i] = obj[j + 1];
					}
					n--;
					found = 1;
				}
			}
			if (found == 0)
			{
				cout << "Delete Not Success!" << endl;
				getch();
			}
			else
			{
				cout << "Delete Successfully!" << endl;
				getch();
			}
		}
		break;
		case '2':
		{
			cout << "Enter Reader NAME to Delete : ";
			cin >> del_code;
			for (int i = 0; i < n; i++)
			{
				if (del_code == obj[i].getName())
				{
					for (int j = i; j < r; j++)
					{
						obj[i] = obj[j + 1];
					}
					n--;
					found = 1;
				}
			}
			if (found == 0)
			{
				cout << "Delete Not Success!" << endl;
				getch();
			}
			else
			{
				cout << "Delete Successfully!" << endl;
				getch();
			}
		}
		break;
		default:
			break;
		}
	}
};

// *===================================================
// *             *__Borrow_And_Return__*
// *===================================================
class BorrowerData : protected BookData, protected ReaderData
{
private:
	string brID, br_date, status;
	int qty;

public:
	BorrowerData()
	{
		brID = getId();
	}
	void input_borrow()
	{
		cout << "Add Borrow";
	}
	void show_borrow()
	{
		cout << "haha you\'re borrower" << endl;
	}
};
// *===================================================
// *             FUNCTION AND SUB-FUNCTION
// *===================================================
// ======== Loading ========
void Loading()
{
	int wWin = 0, hWin = 0;
	hideCursor();
	DrawRectangle(28 + wWin, 14, 54, 1, 1);
	gotoxy(30 + wWin, 15);
	for (int i = 0; i < 50; i++)
	{
		foreColor(7);
		printf("%c", 177);
	}
	gotoxy(30 + wWin, 15);
	for (int i = 0; i < 50; i++)
	{
		foreColor(3);
		printf("%c", 219);
		Sleep(100 - i * 1.8);
	}
	showCursor();
}
// ======== Header Menu ========
void header_menu()
{
	ifstream art_file("data/artText/header.txt");
	int wWin = 0, hWin = 10, g = 2;
	string line;
	clrscr();
	while (std::getline(art_file, line))
	{
		gotoxy(15, g++);
		std::cout << line << "\n";
	}
	cout << endl;
	art_file.close();
	DrawRectangle(10, 1, 98, 10, 7);
	// DrawRectangle(22, 5, 62, 4, 8);
	gotoxy(37 + wWin, 2 + hWin);
	foreColor(7);
	cout << "[ LIBRARY - Management System ]";
	gotoxy(23 + wWin, 6 + hWin);
	cout << "[1]  Book Information";
	gotoxy(60 + wWin, 6 + hWin);
	cout << "[2]  Reader Information";
	gotoxy(23 + wWin, 8 + hWin);
	cout << "[3]  Borrower Information";
	gotoxy(60 + wWin, 8 + hWin);
	cout << "[0]  Exit program";
	gotoxy(35 + wWin, 12 + hWin);
	cout << "Please choose one option : ";
	op = getch();
}
// ======== case header ========
void case__header(string str)
{
	clrscr();
	foreColor(2);
	DrawRectangle(5, 2, 85, 8);
	gotoxy(37, 2);
	foreColor(9);
	cout << "[ " << str << " Information ]";
	foreColor(6);
	gotoxy(10, 4);
	// cout << "[1] Input " << str << "\n\n";
	cout << "[1] Input " << str;
	gotoxy(40, 4);
	cout << "[2] Show " << str;
	gotoxy(70, 4);
	cout << "[3] Search " << str;
	gotoxy(10, 6);
	cout << "[4] Sort " << str;
	gotoxy(40, 6);
	cout << "[5] Update " << str;
	gotoxy(70, 6);
	cout << "[6] Delete " << str;
	gotoxy(40, 8);
	cout << "[0] Back to Home\n\n";
	DrawRectangle(9, 10, 32, 1);
	DrawRectangle(10, 10, 30, 1);
	gotoxy(10, 11);
	foreColor(5);
	cout << "Please choose one option:     ";
}
void clrscr()
{
	system("cls");
}
// ======== HIDE CURSOR ========
void hideCursor()
{
	HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO info;
	info.dwSize = 100;
	info.bVisible = FALSE;
	SetConsoleCursorInfo(consoleHandle, &info);
}
// ======== SHOW CURSOR ========
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

#endif