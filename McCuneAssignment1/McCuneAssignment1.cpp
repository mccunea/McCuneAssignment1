// McCuneAssignment1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
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

	} while (transactionType != 'Q' && transactionType != 'q');

	cout << "Your beginning balance was: " << beginningBalance << endl;
	cout << "Your balance is: " << runningBalance << endl;
	cout << "Your withdrawls: " << endl;
	for (i = 0; i < wcount; i++)
	{
		cout << withdrawlArray[i] << endl;
		withdrawlTotal += withdrawlArray[i];
	}

		cout << "total withdrawls: " << withdrawlTotal << endl;
	for (i = 0; i < dcount; i++)
	{
		cout << depositArray[i] << endl;
		depositTotal += depositArray[i];
	}
	cout << "total deposits: " << depositTotal << endl;

	for (i = 0; i < ccount; i++)
	{
		cout << checkArray[i] << endl;
		checkTotal += checkArray[i];
	}
	cout << "total checks: " << checkTotal << endl;

    return 0;
}

