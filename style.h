#ifndef ANTHEADERPLUSPLUS_H
#define ANTHEADERPLUSPLUS_H

#include <windows.h>
#include <stdlib.h>
#include <iostream>
#include <sstream>
#include <string.h>
#include <ctype.h>
#include <time.h>
#include <stdio.h>
#include <conio.h>
#include <iomanip>
using namespace std;
/*void swap(int (*a)[2], int (*b)[2])
{
	int temp[sizeof(*a)/sizeof((*a)[0])];
	memcpy(temp,a,sizeof(temp));
	memcpy(a,b,sizeof(*a));
	memcpy(b,temp,sizeof(*b));
}*/

void delay(int milliseconds)
{
	long pause;
	clock_t now, then;

	pause = milliseconds * (CLOCKS_PER_SEC / 1000);
	now = then = clock();
	while ((now - then) < pause)
		now = clock();
}

void toLower(char str[])
{
	int n;
	char c;
	for (n = 0; str[n] != '\0'; n++)
	{
		c = str[n];
		putchar(tolower(c));
	}
}
void toUpper(char str[])
{
	int n;
	char c;
	for (n = 0; str[n] != '\0'; n++)
	{
		c = str[n];
		putchar(toupper(c));
	}
}

int is_number(char *pchar, int lnum)
{
	int i, is_num = 0;
	for (i = 0; i < lnum; i++)
	{
		if (!isalnum(*pchar)) // Loop until it a character is not alpha-numeric.
			break;
		// printf("%c - ",*pchar);
		if (!isdigit(*pchar))
		{
			is_num++;
			break;
		}
		pchar++;
	}
	// printf("\nis_num = %i\n",is_num);
	return is_num;
}

void gotoxy(int x, int y)
{
	HANDLE hConsoleOutput;
	COORD coord;
	hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(hConsoleOutput, coord);
}
void cls()
{
	system("cls");
}
void foreColor(int color)
{
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(handle, color | FOREGROUND_INTENSITY);
}
template <class T>
string int_string(T number)
{
	stringstream converter; // at sstream header
	converter << number;
	return converter.str();
}

int string_int(string str_number)
{
	stringstream converter(str_number);
	int result;
	return converter >> result ? result : 0;
}

bool is_number(float &num)
{
	cin >> num;
	if (cin.fail())
	{
		cin.clear();
		cin.ignore(80, '\n');
		return false;
	}
	return true;
}
bool is_number(int &num)
{
	cin >> num;
	if (cin.fail())
	{
		cin.clear();
		cin.ignore(80, '\n');
		return false;
	}
	return true;
}

void setcursor(bool visible, DWORD size)
{
	HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
	if (size == 0)
	{
		size = 20; // default cursor size Changing to numbers from 1 to 20, decreases cursor width
	}
	CONSOLE_CURSOR_INFO lpCursor;
	lpCursor.bVisible = visible;
	lpCursor.dwSize = size;
	SetConsoleCursorInfo(console, &lpCursor);
}
void drawRec(int x, int y, int w, int h, string s)
{
	gotoxy(x, y);
	cout << (char)218;
	for (int i = x + 1; i < (w * 2 + x) - 2; i++)
	{
		gotoxy(i, y);
		cout << (char)196;
	}
	cout << (char)191;
	//
	int x_s = (x * 2) - s.length() / 2;
	int y_s = y + (h / 2);
	gotoxy(x_s, y_s);
	cout << s;
	//
	for (int i = y + 1; i < h + y; i++)
	{
		gotoxy(x, i);
		cout << (char)179;
		gotoxy(x + (w * 2) - 2, i);
		cout << (char)179;
	}

	gotoxy(x, y + h);
	cout << (char)192;
	for (int i = x + 1; i < (w * 2 + x) - 2; i++)
	{
		gotoxy(i, y + h);
		cout << (char)196;
	}
	cout << (char)217;
}
void clrXY(int x, int y, int count)
{
	COORD topLeft = {(short)x, (short)y};
	HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_SCREEN_BUFFER_INFO screen;
	DWORD written;
	GetConsoleScreenBufferInfo(console, &screen);
	FillConsoleOutputCharacterA(console, '\0', count, topLeft, &written); // replace with count(ex:80 characters) NULL at this line
	FillConsoleOutputAttribute(console, FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_BLUE,
							   screen.dwSize.X * screen.dwSize.Y, topLeft, &written);
	SetConsoleCursorPosition(console, topLeft);
}
string ToLower(string s)
{
	string result = "";
	for (int i = 0; i < s.length(); i++)
	{
		result += tolower(s[i]);
	}
	return result;
}
string ToUpper(string s)
{
	string result = "";
	for (int i = 0; i < s.length(); i++)
	{
		result += toupper(s[i]);
	}
	return result;
}

void DrawRectangle(int x, int y, int w, int h, int c = 7)
{
	foreColor(c);
	for (int i = 0; i < w; i++)
	{
		gotoxy(x + i, y);
		cout << (char)205;
		gotoxy(x + i, y + h + 1);
		cout << (char)205;
	}
	for (int i = 0; i < h; i++)
	{
		gotoxy(x - 1, y + i + 1);
		cout << (char)186;
		gotoxy(x + w, y + i + 1);
		cout << (char)186;
	}
	// top-left
	gotoxy(x - 1, y);
	cout << (char)201;
	// top-right
	gotoxy(x + w, y);
	cout << (char)187;
	// bottom-left
	gotoxy(x - 1, y + h + 1);
	cout << (char)200;
	// bottom-right
	gotoxy(x + w, y + h + 1);
	cout << (char)188;
}

void ShowMenu(string menus[], int n, int index, int x, int y)
{
	for (int i = 0; i < n; i++)
	{
		clrXY(x - 4, y + i, menus[i].length() + 4);
		if (i != index)
		{
			gotoxy(x, y + i);
			foreColor(3);
			cout << menus[i];
		}
		else
		{
			gotoxy(x - 4, y + i);
			foreColor(3);
			cout << "==> " << menus[i];
		}
	}
}
void drawline(int x, int y, int w, int h, int a, int b) /*x,y,wight,hight,place to break ,Number of information-1*/
{
	foreColor(3);
	for (int i = 0; i < w; i++)
	{
		gotoxy(x + i, y);
		cout << (char)205;
		gotoxy(x + i, y + h + 1);
		cout << (char)205;
	}
	for (int i = 0; i < h; i++)
	{
		gotoxy(x - 1, y + i + 1);
		cout << (char)186;
		gotoxy(x + w, y + i + 1);
		cout << (char)186;
	}
	// top-left
	gotoxy(x - 1, y);
	cout << (char)201;
	// top-right
	gotoxy(x + w, y);
	cout << (char)187;
	// bottom-left
	gotoxy(x - 1, y + h + 1);
	cout << (char)200;
	// bottom-right
	gotoxy(x + w, y + h + 1);
	cout << (char)188;

	for (int i = 0; i < b * 15; i += 15)
	{
		gotoxy(a + i, y + 0);
		cout << (char)203;
		gotoxy(a + i, y + 1);
		cout << (char)186;
		gotoxy(a + i, y + 2);
		cout << (char)186;
		gotoxy(a + i, y + 3);
		cout << (char)202;
	}
}
//**************************************************************************
//						Add New function By Hinsy Lasong
//**************************************************************************
// 1.
void drawBoxSingleLine(int x, int y, int w, int h, int color = 7)
{
	int i, j;
	foreColor(color);
	// Width
	for (i = 0; i < w; i++)
	{
		// top
		gotoxy(x + i, y);
		printf("%c", 196);
		// bottom
		gotoxy(x + i, y + h + 1);
		printf("%c", 196);
	}
	// Height
	for (j = 0; j < h; j++)
	{
		// left
		gotoxy(x - 1, y + j + 1);
		printf("%c", 179);
		// right
		gotoxy(x + w, y + j + 1);
		printf("%c", 179);
	}
	// top left
	gotoxy(x - 1, y);
	printf("%c", 218);
	// top right
	gotoxy(x + w, y);
	printf("%c", 191);
	// bottom left
	gotoxy(x - 1, y + h + 1);
	printf("%c", 192);
	// bottom right
	gotoxy(x + w, y + h + 1);
	printf("%c", 217);
}
// 2.
void drawBoxSingleLineWithBG(int x, int y, int w, int h, int color)
{
	int i, j, r, c;
	foreColor(color);
	// Width
	for (i = 0; i < w; i++)
	{
		// top
		gotoxy(x + i, y);
		printf("%c", 196);
		// bottom
		gotoxy(x + i, y + h + 1);
		printf("%c", 196);
	}
	// Height
	for (j = 0; j < h; j++)
	{
		// left
		gotoxy(x - 1, y + j + 1);
		printf("%c", 179);
		// right
		gotoxy(x + w, y + j + 1);
		printf("%c", 179);
	}
	// top left
	gotoxy(x - 1, y);
	printf("%c", 218);
	// top right
	gotoxy(x + w, y);
	printf("%c", 191);
	// bottom left
	gotoxy(x - 1, y + h + 1);
	printf("%c", 192);
	// bottom right
	gotoxy(x + w, y + h + 1);
	printf("%c", 217);

	for (r = 0; r < h; r++)
	{
		for (c = 0; c < w; c++)
		{
			gotoxy(x + c, y + r + 1);
			printf(" ");
		}
	}
}
// 3.
void drawBoxDoubleLineWithBG(int x, int y, int w, int h, int color)
{
	int i, j, r, c;
	foreColor(color);
	// Width
	for (i = 0; i < w; i++)
	{
		// top
		gotoxy(x + i, y);
		printf("%c", 205);
		// bottom
		gotoxy(x + i, y + h + 1);
		printf("%c", 205);
	}
	// Height
	for (j = 0; j < h; j++)
	{
		// left
		gotoxy(x - 1, y + j + 1);
		printf("%c", 186);
		// right
		gotoxy(x + w, y + j + 1);
		printf("%c", 186);
	}
	// top left
	gotoxy(x - 1, y);
	printf("%c", 201);
	// top right
	gotoxy(x + w, y);
	printf("%c", 187);
	// bottom left
	gotoxy(x - 1, y + h + 1);
	printf("%c", 200);
	// bottom right
	gotoxy(x + w, y + h + 1);
	printf("%c", 188);

	for (r = 0; r < h; r++)
	{
		for (c = 0; c < w; c++)
		{
			gotoxy(x + c, y + r + 1);
			printf(" ");
		}
	}
}
// 4.
void HLine(int x, int y, int w, int color = 7, int line = 196) // widht
{
	foreColor(color);
	for (int i = 0; i < w; i++)
	{
		gotoxy(x + i, y);
		cout << (char)line;
	}
}
// 5.
void VLine(int x, int y, int h, int color = 7, int line = 179) // Height
{
	foreColor(color);
	for (int i = 0; i < h; i++)
	{
		gotoxy(x - 1, y + i + 1);
		cout << (char)line;
	}
}
// 6.
void clearBox(int x, int y, int w, int h, int color = 7)
{
	foreColor(color);
	for (int i = -1; i <= h; i++)
	{
		for (int j = -1; j <= w; j++)
		{
			gotoxy(x + j, y + i);
			cout << " ";
		}
	}
}
//**************************************************************************
//						Add New function on Tue - 08-01-18
//**************************************************************************
// 7.
string formatCurrency(const long double &currency, const unsigned int &precision = 6)
{
	ostringstream stm;
	stm << fixed << setprecision(precision) << currency;
	string money = stm.str();
	int i = money.find('.');
	if (i > 0)
	{
		i -= 3;
		while (i > 0)
		{
			money.insert(i, ",");
			i -= 3;
		}
	}
	return money;
}
// 8.
long double eraseFormatCurrency(const string &currency)
{
	string money = currency;
	int i = money.find('.');
	if (i > 0)
	{
		i -= 4;
		while (i > 0)
		{
			money.erase(i, 1);
			i -= 4;
		}
	}
	stringstream stm(money);
	long double tmp = 0;
	stm >> tmp;
	return tmp;
}
#endif
