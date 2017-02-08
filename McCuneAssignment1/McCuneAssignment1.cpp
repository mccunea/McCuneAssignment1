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

		if (transactionType = 'W')
		{
			cout << "Enter amount to be withdrawn:" << endl;
				cin >> transaction;
				balance -= transaction;

		}
		else if (transactionType = 'D')
		{
			cout << "Enter amount to be deposited:" << endl;
			cin >> transaction;
			balance += transaction;
		}
		else if (transactionType = 'C')
		{

		}

	} while (transactionType != 'Q');

		cout << balance;
	
    return 0;
}

