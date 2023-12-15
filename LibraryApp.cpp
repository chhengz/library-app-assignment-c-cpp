#include "main.h"

int main()
{
	// SetUpWindowConsole_App();

	Person objP[MAX], objPtmp;
	BookData objB[MAX], objBtmp;
	ReaderData objR[MAX], objRtmp;
	BorrowerData objBR[MAX], objBRtmp;

	// objP->Login_form();

	do
	{
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
				foreColor(6);
				cin >> bop;
				switch (bop)
				{
				case '1':
				{
					clrscr();
					int index=0;
					foreColor(8);
					drawBoxSingleLine(45, 1, 30, 3);
					gotoxy(47, 3);
					cout << "[ INPUT BOOK INFORMATION ]";

					drawBoxSingleLine(21, 5, 10, 1, 1);
					foreColor(2);
					gotoxy(5, 6); cout << "Number of books";
					foreColor(6);
					gotoxy(22, 6); cin >> k;
					cout << endl;
					for (i = n; i < k + n; i++)
					{
						index++;
						foreColor(3);
						cout << "\n\t[No. -" << index << "-]" << endl;
						objB[i].input_book();
					}
					n = n + k;
				}
				break;
				case '2':
				{
					clrscr();
					foreColor(8);
					drawBoxSingleLine(44, 0, 31, 3);
					gotoxy(46, 2);
					cout << "[ OUTPUT BOOK INFORMATION ]";
					objB->show_book_list();
					getch();
				}
				break;
				case '3':
				{
					clrscr();
					drawBoxSingleLine(44, 0, 31, 1);
					gotoxy(46, 1);
					cout << "[ SEARCH BOOK INFORMATION ]";
					objB->searchBook();
					getch();
				}
				break;
				case '4':
				{
					char sort_op;
					clrscr();
					drawBoxSingleLine(44, 0, 31, 1);
					gotoxy(46, 1);
					cout << "[ DELETE BOOK INFORMATION ]";
					
					do{
						cout << "\n\n\n\t\t\t(1) SORT BY CODE\t\t(2) SORT BY QTY\t\t(0) BACK :: "; cin >> sort_op;
						switch (sort_op)
						{
							case '1':
							{
								objB->sortBookByCODE();
							}break;
							case '2':
							{
								objB->sortBookByQTY();
							}break;
							default:
								break;
						}
					}
					while (sort_op != '0');
					// getch();
				}
				break;
				case '5':
				{
					clrscr();
					drawBoxSingleLine(44, 0, 31, 1);
					gotoxy(46, 1);
					cout << "[ DELETE BOOK INFORMATION ]";
					objB->updateBook();
					getch();
				}
				break;
				case '6':
				{
					clrscr();
					drawBoxSingleLine(44, 0, 31, 1);
					gotoxy(46, 1);
					cout << "[ DELETE BOOK INFORMATION ]";
					objB->deleteBook();
					getch();
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
				foreColor(6); cin >> rop;
				switch (rop)
				{
				case '1':
				{
					clrscr();
					int index;

					foreColor(8);
					drawBoxSingleLine(45, 1, 33, 3);
					gotoxy(47, 3);
					cout << "[ INPUT READER INFORMATION ]";

					drawBoxSingleLine(23, 5, 10, 1, 1);
					foreColor(2);
					gotoxy(5, 6); cout << "Number of Readers";
					foreColor(6);
					gotoxy(24, 6); cin >> w;
					cout << endl;
					for (i = r; i < w + r; i++)
					{
						index++;
						foreColor(3);
						cout << "\n\t[No. -" << index << "-]" << endl;
						objR[i].input_reader();
					}
					r = r + w;
				}
				break;

				case '2':
				{
					clrscr();
					foreColor(8);
					drawBoxSingleLine(44, 0, 33, 1);
					gotoxy(46, 1);
					cout << "[ OUTPUT READER INFORMATION ]";
					objR->show_reader_list();
					getch();
				}
				break;
				case '3':
				{
					clrscr();
					drawBoxSingleLine(42, 0, 33, 1);
					gotoxy(44, 1);
					cout << "[ SEARCH READER INFORMATION ]";
					objR->searchReader();
					getch();
				}
				break;
				case '4':
				{
					char sort_op;
					clrscr();
					drawBoxSingleLine(44, 0, 31, 1);
					gotoxy(46, 1);
					cout << "[ SORT READER INFORMATION ]";
					
					do{
						cout << "\n\n\n\t\t\t(1) SORT BY ID\t\t(2) SORT BY NAME\t\t(0) BACK :: "; cin >> sort_op;
						switch (sort_op)
						{
							case '1':
							{
								objR->sortReaderByID();
							}break;
							case '2':
							{
								objR->sortReaderByNAME();
							}break;
							default:
								break;
						}
					}
					while (sort_op != '0');
				}
				break;
				case '5':
				{
					clrscr();
					drawBoxSingleLine(44, 0, 31, 1);
					gotoxy(46, 1);
					cout << "[ DELETE READER INFORMATION ]";
					objR->updateReader();
					getch();
				}
				break;
				case '6':
				{
					clrscr();
					drawBoxSingleLine(44, 0, 31, 1);
					gotoxy(46, 1);
					cout << "[ DELETE READER INFORMATION ]";
					objR->deleteReader();
					getch();
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
				foreColor(6); cin >> brop;
				switch (brop)
				{
				case '1':
				{
					clrscr();
					int index;

					foreColor(8);
					drawBoxSingleLine(43, 1, 35, 3);
					gotoxy(45, 3); cout << "[ INPUT BORROWER INFORMATION ]";

					drawBoxSingleLine(25, 5, 10, 1, 1);
					foreColor(2); gotoxy(5, 6); cout << "Number of Borrowers";
					foreColor(6); gotoxy(26, 6); cin >> p;
					cout << endl;
					for (i = bw; i < bw + p; i++)
					{
						index++;
						foreColor(3);
						cout << "\n\t[No. -" << index << "-]" << endl;
						objBR->input_borrower();
					}
					bw = bw + p;
				}break;

				case '2':
				{
					clrscr();
					foreColor(8);
					drawBoxSingleLine(43, 0, 34, 1);
					gotoxy(45, 1);
					cout << "[ OUTPUT BORROWER INFORMATION ]";
					objBR->show_borrower_list();
					getch();
				}break;

				case '3':
				{
					// 
				}break;

				case '4':
				{
					char sort_op;
					clrscr();
					drawBoxSingleLine(44, 0, 31, 1);
					gotoxy(46, 1);
					cout << "[ SORT READER INFORMATION ]";
					
					do{
						cout << "\n\n\n\t\t\t(1) SORT BY ID\t\t(2) SORT BY DATE\t\t(0) BACK :: "; cin >> sort_op;
						switch (sort_op)
						{
							case '1':
							{
								objBR->sortBorrowerByID();
							}break;
							case '2':
							{
								objBR->sortBorrowerByDATE();
							}break;
							default:
								break;
						}
					}
					while (sort_op != '0');
				}break;

				case '5':
				{
					objBR->updateBorrower();
				}break;

				case '6':
				{
					objBR->deleteBorrower();
				}break;
				
				default: break;
				}
			} while (brop != '0');
			
		}break;

		case 'r':
		{
			clrscr();
			int g = 0;
			string line;
			ifstream readme("data/ReadMe.txt");
			foreColor(7);
			cout << endl;
			while (getline(readme, line))
			{
				g++;
				gotoxy(20, 2 + g);
				cout << line << endl;
				Sleep(20);
			}
			readme.close();
			getch();
		}
		break;
		case '0':
		{
			clrscr();
			cout << "\n\n\t\tTHANK YOU " << (char)3;
					getch();
					exit(300);
		}break;
		default:
			gotoxy(36+12, 11);
			cout << "WRONG CASE!" << (char)3; getch();
			break;
		}
	} while (op != '0');
}
