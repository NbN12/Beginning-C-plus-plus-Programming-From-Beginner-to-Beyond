// Section 8 Challenge
/*
	For this program I will be using US dollars and cents.
	
    Write a program that asks the user to enter the following:
	An integer representing the number of cents 
    	
	You may assume that the number of cents entered is greater than or equal to zero
    
	The program should then display how to provide that change to the user.
	
	In the US:
		1 dollar is 100 cents
		1 quarter is 25 cents
		1 dime is 10 cents
		1 nickel is 5 cents, and
		1 penny is 1 cent.
		
	Here is a sample run:
	
	Enter an amount in cents :  92
	
	You can provide this change as follows:
	dollars    : 0
	quarters : 3
	dimes     : 1
	nickels   : 1
	pennies  : 2
	
	Feel free to use your own currency system.
	Also, think of how you might solve the problem using the modulo operator.

	Have fun and test your program!!

*/
#include <iostream>

using std::cout;
using std::cin;
using std::endl;

int main() {
	
	// Declare exchange rate variables
	const int dollars_val{100};
	const int quarter_val{25};
	const int dime_val{10};
	const int nickel_val{5};
	
	int dollar{}, quarter{}, dime{}, nickel{};
	// Get amount of cents from user
	int amount_cent = 0;
	cout << "Enter an amount in cents : ";
	cin >> amount_cent;
	
	// Display results
	cout << "\nYou can provide this change as follows : " << endl;
	
	dollar = amount_cent / dollars_val;
	amount_cent = amount_cent - dollars_val * dollar;
	
	quarter = amount_cent / quarter_val;
	amount_cent = amount_cent - quarter_val * quarter;
	
	dime = amount_cent / dime_val;
	amount_cent = amount_cent - dime_val * dime;
	
	nickel = amount_cent / nickel_val;
	amount_cent = amount_cent - nickel_val * nickel;
    
	cout << "dollars  : " << dollar << endl;
    cout << "quarters : " << quarter << endl;
    cout << "dimes    : " << dime << endl;
    cout << "nickels  : " << nickel << endl;
    cout << "pennies  : " << amount_cent << endl;
	
    cout << endl;
    return 0;
}


