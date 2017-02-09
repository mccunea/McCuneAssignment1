// McCuneAssignment1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
	double withdrawlArray[50];
	double depositArray[50];
	double checkArray[50];
	double beginningBalance;
	double runningBalance;
	double transaction;
	double withdrawlTotal = 0;
	double depositTotal = 0;
	double checkTotal = 0;
	int wcount = 0;
	int dcount = 0;
	int ccount = 0;
	int i;
	char transactionType;
	bool valid;
	cout << setprecision(2) << fixed;
	
	

	cout << "Please enter account balance:" << endl;
	cin >> beginningBalance;
	runningBalance = beginningBalance;
	
	do {
		system("cls");
		cout << "Enter transaction type (W)ithdrawl, (D)eposit, (C)heck, (Q)uit" << endl;
		cin >> transactionType;

		if (transactionType == 'W' || transactionType == 'w')
		{
			do {
				cout << "Enter amount to be withdrawn:" << endl;
				cin >> transaction;

				valid = cin.fail();
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				if (valid == true)
				{
					cout << "Entry invalid. Only use numbers or decimals." << endl;
				}
			} while (valid == true);
				withdrawlArray[wcount] = transaction;
				++wcount;
				runningBalance -= transaction;

		}
		else if (transactionType == 'D' || transactionType == 'd')
		{
			do {
				cout << "Enter amount to be deposited:" << endl;
				cin >> transaction;

				valid = cin.fail();
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				if (valid == true)
				{
					cout << "Entry invalid. Only use numbers or decimals." << endl;
				}
			} while (valid == true);

				depositArray[dcount] = transaction;
				++dcount;
				runningBalance += transaction;
		}
		else if (transactionType == 'C' || transactionType == 'c')
		{
			do {
				cout << "Enter check amount: " << endl;
				cin >> transaction;

				valid = cin.fail();
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				if (valid == true)
				{
					cout << "Entry invalid. Only use numbers or decimals." << endl;
				}
			} while (valid == true);

				checkArray[ccount] = transaction;
				++ccount;
				runningBalance -= transaction;
		}
		else if (transactionType == 'Q' || transactionType == 'q')
		{

		}
		else
		{
			cout << "Please enter a valid character." << endl;
		}

	} while (transactionType != 'Q' && transactionType != 'q');


	system("cls");
	cout << "\n\n";
	cout <<  "\tTransaction Summary:" << endl << "------------------------------------------" << endl;
	cout << "\tBeginning balance: " << setw(15) << beginningBalance << endl << endl;
	
	cout << "\t*Withdrawls: " << endl;
	for (i = 0; i < wcount; i++)
	{
		cout << "\t" << setw(34) << withdrawlArray[i] << endl;
		withdrawlTotal += withdrawlArray[i];
	}
		cout  << "\t----------------------------------" << endl;
		cout  <<  "\tTotal withdrawls: " << setw(16) << withdrawlTotal << endl;
		cout  << "\t----------------------------------" << endl << endl;
		cout << "\t*Deposits:" << endl;
	for (i = 0; i < dcount; i++)
	{
		cout << "\t" << setw(34) << depositArray[i] << endl;
		depositTotal += depositArray[i];
	}
	cout  << "\t----------------------------------" << endl;
	cout  << "\tTotal deposits: " << setw(18) << depositTotal << endl;
	cout  << "\t----------------------------------" << endl << endl;
	cout << "\t*Checks:" << endl;
	for (i = 0; i < ccount; i++)
	{
		cout  << "\t" << setw(34) << checkArray[i] << endl;
		checkTotal += checkArray[i];
	}
	cout  << "\t----------------------------------" << endl;
	cout  << "\tTotal checks: "  << setw(20) << checkTotal << endl << "------------------------------------------" << endl;
	cout << "\tRemaining balance: " << setw(15) << runningBalance << endl << "\n\n\n\n\n";
    return 0;
}

