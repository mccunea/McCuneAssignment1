// McCuneAssignment1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
using namespace std;

int main()
{
	double balance;
	double transaction;
	char transactionType;

	cout << "Please enter account balance:" << endl;
	cin >> balance;
	
	do {
		cout << "Enter transaction type (W)ithdrawl, (D)eposit, (C)heck, (Q)uit" << endl;
		cin >> transactionType;

		if (transactionType == 'W' || transactionType == 'w')
		{
			cout << "Enter amount to be withdrawn:" << endl;
				cin >> transaction;
				balance -= transaction;

		}
		else if (transactionType == 'D' || transactionType == 'd')
		{
			cout << "Enter amount to be deposited:" << endl;
			cin >> transaction;
			balance += transaction;
		}
		else if (transactionType == 'C' || transactionType == 'c')
		{
			cout << "Enter check amount: " << endl;
			cin >> transaction;
			balance -= transaction;
		}

	} while (transactionType != 'Q' || transactionType != 'q');

	cout << "Your balance is: " << balance << endl;
	
    return 0;
}

