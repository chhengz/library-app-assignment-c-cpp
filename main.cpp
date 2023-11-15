#include "main.h"

int main()
{
	SetWinConsole();
	if (!IsRunAsAdmin())
	{
		system("title Please Run As Administrator");
		string line;
		ifstream art_file("data/artText/runadmin.txt");
		// Request admin privileges
		while (std::getline(art_file, line))
		{
			cout << line << "\n";
		}
		art_file.close();
		getch();
		// ShellExecute(NULL, "runas", "main.exe", NULL, NULL, SW_SHOWNORMAL);
		return 0;
	}
	system("cls & title Library Program - %USERNAME% - %DATE%");
	Person objP[MAX], objPtmp;
	BookData objB[MAX], objBtmp;
	ReaderData objR[MAX], objRtmp;
	BorrowerData objBR[MAX], objBRtmp;

	objP->Login_form();
	Loading();

	do
	{
		foreColor(8);
		header_menu();
		switch (op)
		{
			// *===================================================
			// *             CASE BOOK
			// *===================================================
		case '1':
		{
			do
			{
				string str = "Book";
				case__header(str);
				gotoxy(36, 11);
				bop = getch();
				switch (bop)
				{
				case '1':
				{
					clrscr();
					int index;
					foreColor(8);
					cout << "\n\t=======>>> INPUT BOOK INFORMATION <<<=======" << endl
						 << endl;
					if (n > 0)
					{
						foreColor(2);
						cout << "\nEnter number of book : ";
						cin >> k;
						cout << endl;
						for (i = n; i < k + n; i++)
						{
							index++;
							foreColor(3);
							cout << "\n\t-- Book " << index << " --" << endl;
							foreColor(7);
							objB[i].input_book();
						}
						n = n + k;
					}
					else
					{
						foreColor(2);
						cout << "\nEnter number of book : ";
						cin >> n;
						cout << endl;
						for (i = 0; i < n; i++)
						{
							foreColor(3);
							cout << "\n\t-- Book " << i + 1 << " --" << endl;
							foreColor(7);
							objB[i].input_book();
						}
					}
				}
				break;
				case '2':
				{
					clrscr();
					objB->show_book_list(objB, n);
					getch();
				}
				break;
				case '3':
				{
					objB->searchBook(objB, n);
				}
				break;
				case '4':
				{
					objB->sortBook(objB, n);
				}
				break;
				case '5':
				{
					objB->updateBook(objB, n);
				}
				break;
				case '6':
				{
					objB->deleteBook(objB, n);
				}
				break;
				default:
					break;
				}
			} while (bop != '0');
		}
		break;
			// *===================================================
			// *             CASE READER
			// *===================================================
		case '2':
		{
			do
			{
				string str = "Reader";
				case__header(str);
				gotoxy(36, 11);
				rop = getch();
				switch (rop)
				{
				case '1':
				{
					clrscr();
					int index;
					foreColor(8);
					cout << "\n\t=======>>> INPUT READER INFORMATION <<<=======" << endl
						 << endl;
					if (r > 0)
					{
						foreColor(2);
						cout << "\nEnter number of reader : ";
						cin >> r;
						cout << endl;
						for (i = r; i < k + r; i++)
						{
							index++;
							foreColor(3);
							cout << "\n\t-- Reader " << index << " --" << endl;
							foreColor(7);
							objR[i].input_reader();
						}
						r = r + k;
					}
					else
					{
						foreColor(2);
						cout << "\nEnter number of reader : ";
						cin >> r;
						cout << endl;
						for (i = 0; i < r; i++)
						{
							foreColor(3);
							cout << "\n\t-- Reader " << i + 1 << " --" << endl;
							foreColor(7);
							objR[i].input_reader();
						}
					}
				}
				break;
				case '2':
				{
					clrscr();
					objR->show_reader_list(objR, r);
					getch();
				}
				break;
				case '3':
				{
					objR->searchReader(objR, r);
				}
				break;
				case '4':
				{
					objR->sortReader(objR, r);
				}
				break;
				case '5':
				{
					objR->updateReder(objR, r);
				}
				break;
				case '6':
				{
					objR->deleteReader(objR, r);
				}
				break;
				default:
					break;
				}
			} while (rop != '0');
		}
		break;
			// *===================================================
			// *             CASE BORROWER
			// *===================================================
		case '3':
		{
			do
			{
				string str = "Borrower";
				case__header(str);
				gotoxy(36, 11);
				brop = getch();
				switch (brop)
				{
				case '1':
				{
					//
				}
				break;
				case '2':
				{
					//
				}
				break;
				case '3':
				{
					//
				}
				break;
				case '4':
				{
					//
				}
				break;
				case '5':
				{
					//
				}
				break;

				default:
					break;
				}
			} while (brop != '0');
		}
		break;
		default:
			break;
		}
	} while (op != '0');
}
