	// McCuneAssignment1.cpp : Defines the entry point for the console application.
	//Comments are made at the first occurance of a data structure. Most things are repeated and are not double commented. 

#include "stdafx.h"
#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
	double withdrawlArray[50]; // used to track withdrawls
	double depositArray[50]; // used to track deposits
	double checkArray[50]; // used to track checks
	double overdraftArray[50]; // used to track overdrafts
	double beginningBalance; // used to set the beginning account balance
	double runningBalance; // used to keep track of a users balance
	double transaction; // used to track user input for all transactions
	double overdraft; // used to set an expense to be applied if a user overdrafts
	double withdrawlTotal = 0; // used to sum up withdrawls
	double depositTotal = 0; // used to sum up deposits
	double checkTotal = 0; // used to sum up checks
	double overdraftTotal = 0; // used to sum up overdrafts
	int wcount = 0; // used for indexing in the withdrawlArray
	int dcount = 0; // used for indexing in the depositArray
	int ccount = 0; // used for indexing in the checksArray
	int ocount = 0; // used for indexing in the overdraftArray
	int i; // used for iterating the arrays. 
	char transactionType; // user input which selects the transaction type
	char overdraftConfirm; // asks the user if they are sure they want to accept overdraft fees. 
	bool valid; // used for error checking
	bool didOverdraft = false; // if a user has not overdrafted, overdraft data will not display on their check.
	cout << setprecision(2) << fixed; // sets precision for the later output statements.

	// Lines 34 - 46 collect user input for the starting account balance and initalizes an additional variable (runningBalance) to track transactions.
	do {
		cout << "Please enter account balance:" << endl; 
		cin >> beginningBalance; // collects the beginning balance from the user. 
		valid = cin.fail(); // error checking. Sets valid bool equal to the result of cin.fail(). If an incorrect data type for transaction is entered this will == true.
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		if (valid == true) // will execute only if incorrect datatype is entered. 
		{
			cout << "Entry invalid. Only use numbers or decimals." << endl;
		}
		runningBalance = beginningBalance; // sets a running number equal to the starting balance for tracking purposes.
	} while (valid == true); // true while the wrong data type is present for the cin statement.

	/*Lines 47 - 184 collect transaction information from the user. They allow for the selection of W,D,C,Q and reject other inputs. Withdrawls and checks are subtracted from
	the running balance and an overdraft fee is applied if the user exceeds the amount of money currently held in runningBalance.(They are given the option to reject this 
	restart the current transaction.) Transaction information is tracked using an array for each transaction type. The array stores the current transaction and increments 
	its array to the next index. The bool valid is set by the result of the cin.fail function and the error catching if statements are executed only when cin.fail == true. 
	This ensures that users can only cin the same data type as the variable transaction. All of this is accomplished with a do while loop in which the user is asked for their
	transaction type. They select a type and the code for that type executes then they are returned to the question until they choose to quit. At that point
	their transactions are displayed for them to review.*/
	do {
		system("cls"); // clears any excess output.
		cout << "Enter transaction type (W)ithdrawl, (D)eposit, (C)heck, (Q)uit" << endl;
		cin >> transactionType; // collected for the if else conditional statements. This value will determine the code to be executed.

		if (transactionType == 'W' || transactionType == 'w') // if transactionType was set to W or w by the user. 
		{
			do {
				cout << "Enter amount to be withdrawn:" << endl;
				cin >> transaction; // collects user input and sets the value for variable transaction. Repeated throughout the program to acheive the same result. 

				valid = cin.fail(); // error checking. Sets valid bool equal to the result of cin.fail(). If an incorrect data type for transaction is entered this will == true.
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				if (valid == true) // will execute only if incorrect datatype is entered. 
				{
					cout << "Entry invalid. Only use numbers or decimals." << endl;
				}
			} while (valid == true); // true while the wrong data type is present for the cin statement. 
			
			/*an extra I added because I thought it would be cool... If a user trys to use more money than they have they are charged for it. 
			Works like almost everything else in the program and is repeated in check.*/
			if (transaction > runningBalance)
			{
				do {
					overdraft = (transaction * .05);
					cout << "WARNING " << transaction << " is more money than you have in your account. You have "
						<< runningBalance << " remaining." << "\n\n" <<
						"If you apply this withdrawl a 5% overdraft fee (" << overdraft << ") will be applied to your account. Would you like to continue? Y/N\n";
					cin >> overdraftConfirm;
					if (overdraftConfirm == 'Y' || overdraftConfirm == 'y')
					{
						withdrawlArray[wcount] = transaction;
						++wcount;
						runningBalance -= transaction;
						overdraftArray[ocount] = overdraft;
						++ocount;
						runningBalance -= overdraft;
						didOverdraft = true;


					}
					else if (overdraftConfirm == 'N' || overdraftConfirm == 'n') {

					}
					else {
						cout << "Please enter Y/N: " << endl;
					}
				} while (overdraftConfirm != 'Y' && overdraftConfirm != 'y' &&
					overdraftConfirm != 'N' && overdraftConfirm != 'n');

			}
			else {
				withdrawlArray[wcount] = transaction; //adds input form transaction to the withdrawlArray
				++wcount; // keeps a count of elements in the withdrawlArray
				runningBalance -= transaction; // subtracts the withdrawl from the current balance.
			}

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

			if (transaction > runningBalance)
			{
				do {
					overdraft = (transaction * .05);
					cout << "WARNING " << transaction << " is more money than you have in your account. You have "
						<< runningBalance << " remaining." << "\n\n" <<
						"If you apply this withdrawl a 5% overdraft fee (" << overdraft << ") will be applied to your account. Would you like to continue? Y/N\n";
					cin >> overdraftConfirm;
					if (overdraftConfirm == 'Y' || overdraftConfirm == 'y')
					{

						checkArray[ccount] = transaction;
						++ccount;
						runningBalance -= transaction;
						overdraftArray[ocount] = overdraft;
						++ocount;
						runningBalance -= overdraft;
						didOverdraft = true;

					}
					else if (overdraftConfirm == 'N' || overdraftConfirm == 'n') {

					}
					else {
						cout << "Please enter Y/N: " << endl;
					}
				} while (overdraftConfirm != 'Y' && overdraftConfirm != 'y' &&
					overdraftConfirm != 'N' && overdraftConfirm != 'n');

			}
			else {

				checkArray[ccount] = transaction;
				++ccount;
				runningBalance -= transaction;
			}
		}
		else if (transactionType == 'Q' || transactionType == 'q')
		{

		}
		else
		{
			cout << "Please enter a valid character." << endl;
		}

	} while (transactionType != 'Q' && transactionType != 'q'); // when the user inputs Q or q the do while statement will end.

	/*Lines 190 - 239 format and produce the output for the program. The transaction arrays are iterated through and summed up with total variables for later display. 
	0 is returned at the end of this block in order to let the program know that main() has finished.*/
	system("cls"); 
	cout << "\n\n";
	cout << "\tTransaction Summary:" << endl << "------------------------------------------" << endl;
	cout << "\tBeginning balance: " << setw(15) << beginningBalance << endl << endl;

	cout << "\t*Withdrawls: " << endl;
	for (i = 0; i < wcount; i++)
	{
		cout << "\t" << setw(34) << withdrawlArray[i] << endl;
		withdrawlTotal += withdrawlArray[i];
	}
	cout << "\t----------------------------------" << endl;
	cout << "\tTotal withdrawls: ";
	cout << setw(16) << withdrawlTotal << endl;
	cout << "\t----------------------------------" << endl << endl;
	cout << "\t*Deposits:" << endl;
	for (i = 0; i < dcount; i++)
	{
		cout << "\t" << setw(34) << depositArray[i] << endl;
		depositTotal += depositArray[i];
	}
	cout << "\t----------------------------------" << endl;
	cout << "\tTotal deposits: " << setw(18) << depositTotal << endl;
	cout << "\t----------------------------------" << endl << endl;
	cout << "\t*Checks:" << endl;
	for (i = 0; i < ccount; i++)
	{
		cout << "\t" << setw(34) << checkArray[i] << endl;
		checkTotal += checkArray[i];
	}

	cout << "\t----------------------------------" << endl;
	cout << "\tTotal checks: " << setw(20) << checkTotal << endl;
	cout << "------------------------------------------" << endl;
	if (didOverdraft == true)
	{
		cout << "\tOverdraft fees:" << endl;
		for (i = 0; i < ocount; i++)
		{
			cout << "\t" << setw(34) << overdraftArray[i] << endl;
			overdraftTotal += overdraftArray[i];
		}

		cout << "\t----------------------------------" << endl;
		cout << "\tTotal overdraft fees: " << setw(12) << overdraftTotal << endl;
		cout << "------------------------------------------" << endl;
	}
	cout << "\tRemaining balance: " << setw(15) << runningBalance << endl << "\n\n\n\n\n";
	return 0;
}
