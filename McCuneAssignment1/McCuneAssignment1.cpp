// McCuneAssignment1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
	double withdrawlArray[15];
	double depositArray[15];
	double checkArray[15];
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
	cout << setprecision(2) << fixed;
	
	

	cout << "Please enter account balance:" << endl;
	cin >> beginningBalance;
	runningBalance = beginningBalance;
	
	do {
		cout << "Enter transaction type (W)ithdrawl, (D)eposit, (C)heck, (Q)uit" << endl;
		cin >> transactionType;

		if (transactionType == 'W' || transactionType == 'w')
		{
				cout << "Enter amount to be withdrawn:" << endl;
				cin >> transaction;
				withdrawlArray[wcount] = transaction;
				++wcount;
				runningBalance -= transaction;

		}
		else if (transactionType == 'D' || transactionType == 'd')
		{
			cout << "Enter amount to be deposited:" << endl;
			cin >> transaction;
			depositArray[dcount] = transaction;
			++dcount;
			runningBalance += transaction;
		}
		else if (transactionType == 'C' || transactionType == 'c')
		{
			cout << "Enter check amount: " << endl;
			cin >> transaction;
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
	cout <<  "\tTransaction Summary:" << endl << "------------------------------------------" << endl;
	cout << "\tBeginning balance: " << setw(7) << "$" << beginningBalance << endl << endl;
	
	cout << "\t*Withdrawls: " << endl << endl;
	for (i = 0; i < wcount; i++)
	{
		cout << "\t$ " << withdrawlArray[i] << endl;
		withdrawlTotal += withdrawlArray[i];
	}
		cout  << "\t----------------------------------" << endl;
		cout  <<  "\tTotal withdrawls: " << setw(5) << "$" << withdrawlTotal << endl;
		cout  << "\t----------------------------------" << endl << endl;
		cout << "\t*Deposits:" << endl << endl;
	for (i = 0; i < dcount; i++)
	{
		cout << "\t$ " << depositArray[i] << endl;
		depositTotal += depositArray[i];
	}
	cout  << "\t----------------------------------" << endl;
	cout  << "\tTotal deposits: " << setw(5) << "$" << depositTotal << endl;
	cout  << "\t----------------------------------" << endl << endl;
	cout << "\t*Checks:" << endl;
	for (i = 0; i < ccount; i++)
	{
		cout << "\t$ " << checkArray[i] << endl;
		checkTotal += checkArray[i];
	}
	cout  << "\t----------------------------------" << endl;
	cout  << "\tTotal checks: " << setw(5) << "$" << checkTotal << endl << "------------------------------------------" << endl;
	cout << "\tRemaining balance: " <<setw(8) << "$"  << runningBalance << endl;
    return 0;
}

