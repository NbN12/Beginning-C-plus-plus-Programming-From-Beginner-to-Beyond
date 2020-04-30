// Section 9
// Challenge
/*    
    This challenge is about using a collection (list) of integers and allowing the user
    to select options from a menu to perform operations on the list.
    
    Your program should display a menu options to the user as follows:
    
    P - Print numbers
    A - Add a number
    M - Display mean of the numbers
    S - Display the smallest number
    L - Display the largest number
    Q - Quit

    Enter your choice:
    
The program should only accept valid choices from the user, both upper and lowercase selections should be allowed.
If an illegal choice is made, you should display, "Unknown selection, please try again" and the menu options should be
displayed again.


If the user enters 'P' or 'p', you should display all of the elements (ints) in the list.
If the list is empty you should display "[] - the list is empty"
If the list is not empty then all the list element should be displayed inside square brackets separated by a space. 
For example, [ 1 2 3 4 5 ]
      
If the user enters 'A' or 'a' then you should prompt the user for an integer to add to the list 
which you will add to the list and then display it was added. For example, if the user enters 5
You should display, "5 added".
Duplicate list entries are OK

If the user enters 'M' or 'm'  you should calculate the mean or average of the elements in the list and display it.
If the list is empty you should display, "Unable to calculate the mean - no data"

If the user enters 'S' or 's' you should display the smallest element in the list.
For example, if the list contains [2 4 5 1],  you should display, "The smallest number is 1"
If the list is empty you should display, "Unable to determine the smallest number - list is empty"

If the user enters 'L' or 'l' you should display the largest element in the list
For example, if the list contains [2 4 5 1], you should display, "The largest number is 5"
If the list is empty you should display, "Unable to determine the largest number - list is empty"

If the user enters 'Q' or 'q' then you should display 'Goodbye" and the program should terminate.

Before you begin. Write out the steps you need to take and decide in what order they should be done.
Think about what loops you should use as well as what you will use for your selection logic.

This exercise can be challenging! It may likely take a few attempts before you complete it -- that's OK!

Finally, be sure to test your program as you go and at the end.

Hint: Use a vector!

Additional functionality if you wish to extend this program.

- search for a number in the list and if found display the number of times it occurs in the list
- clearing out the list (make it empty again) (Hint: the vector class has a .clear() method)
- don't allow duplicate entries
- come up with your own ideas!

Good luck!

*/
#include <iostream>
#include <vector>
#include <cctype>
#include <algorithm>

using std::cout;
using std::cin;
using std::endl;
using std::vector;
using std::toupper;
using std::min;
using std::max;

int main() {
    
	vector<int> numbers;
	char selection = '\0';
	bool isDuplicate{true};
	do
	{
		// Display menu
		cout << "==========================================\n";
        cout << "\nP - Print numbers" << endl;
        cout << "A - Add a number" << endl;
        cout << "M - Display mean of the numbers" << endl;
        cout << "S - Display the smallest number" << endl;
        cout << "L - Display the largest number"<< endl;
		cout << "F - Search number in the list and its occurence"<< endl;
		cout << "C - Empty the list"<< endl;
		cout << "D - Turn on/off allowing duplicate entries(default is on)"<< endl;
        cout << "Q - Quit" << endl;
        cout << "\nEnter your choice: ";

		cin >> selection;
		selection = toupper(selection);
		
		// Print numbers with selection P
		if(selection == 'P')
		{
			if(numbers.size() == 0)
				cout << "[] - the list is empty\n";
			else
			{
				cout << "[ ";
				for(size_t i = 0; i < numbers.size(); ++i)
				{
					cout << numbers[i] << " ";
				}
				cout << "]\n";
			}
		}
		// Add a number to numbers
		else if(selection == 'A')
		{
			int number;
			cout << "Enter an integer to add to the list: ";
			cin >> number;
			cout << '\n';
			if(isDuplicate == false)
			{
				int cnt = 0;
				for(const auto& num : numbers)
					if(num == number)
					{
						++cnt;
						break;
					}
				if(cnt == 1)
				{
					cout << "Can not add number to the list because list does not allow duplicate\n";
				}
				else
				{
					numbers.push_back(number);
					cout << number << " added\n";
				}
			}
			else
			{
				numbers.push_back(number);
				cout << number << " added\n";
			}
		}
		// Display mean of the numbers vector
		else if(selection == 'M') 
		{
			if(numbers.size() == 0)
				cout << "Unable to calculate the mean - no data\n";
			else
			{
				int sum = 0;
				for(const auto& num : numbers)
					sum += num;
				cout << "The mean is : " << static_cast<double>(sum)/numbers.size() << endl;
			}
		}
		// Display the smallest number in numbers
		else if(selection == 'S')
		{
			if(numbers.size() == 0)
				cout << "Unable to determine the smallest number - list is empty\n";
			else
			{
				int smallest;
				for(size_t i = 0; i < numbers.size(); ++i)
				{
					if(i == 0)
						smallest = numbers[i];
					else
						smallest = min(smallest, numbers[i]);
				}
				cout << "The smallest number is " << smallest << "\n";
			}
		}		
		// Display the largest number in numbers
		else if(selection == 'L')
		{
			if(numbers.size() == 0)
				cout << "Unable to determine the largest number - list is empty\n";
			else
			{
				int largest;
				for(size_t i = 0; i < numbers.size(); ++i)
				{
					if(i == 0)
						largest = numbers[i];
					else
						largest = max(largest, numbers[i]);
				}
				cout << "The largest number is " << largest << "\n";
			}
		}
		// Search number in the list and its occurence
		else if(selection == 'F')
		{
			if(numbers.size() == 0)
				cout << "Unable to search the number - list is empty\n";
			else
			{
				int number{};
				cout << "Enter an integer to search in the list: ";
				cin >> number;
				cout << "\n";
				int occurs = 0;
				int index = -1;
				for(size_t i = 0; i < numbers.size(); ++i)
				{
					if(numbers[i] == number)
					{
						if(index == -1)
							index = i;
						++occurs;
					}
				}
				if(index != -1)
					cout << number << " is in " << index << " position of the list and occurs " << occurs << " time" << (occurs == 1 ? "" : "s") << "\n";
				else
					cout << number << " does not exist in the list\n";
			}
		}
		// Empty the list
		else if(selection == 'C')
		{
			char select{};
			cout << "Are you sure that you want to delete all elements in the list?(y/n)";
			cin >> select;
			cout << "\n";
			if(std::tolower(select) == 'y')
			{
				numbers.clear();
				cout << "Empty list successful\n";
			}
		}
		// Turn on/off allowing duplicate entries(default is on)
		else if(selection == 'D')
		{
			isDuplicate = !isDuplicate;
			if(isDuplicate == true)
				cout << "Allow duplicate turn on\n";
			else
				cout << "Allow duplicate turn off\n";
		}
		else if(selection != 'Q')
			cout << "Unknown selection, please try again\n";
	} while(selection != 'Q');

	cout << "==========================================\n";
	cout << "Goodbye" << endl;
	cout << "==========================================\n";

    return 0;
}

