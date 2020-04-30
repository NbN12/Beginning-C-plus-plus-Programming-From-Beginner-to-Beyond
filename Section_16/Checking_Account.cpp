#include "Checking_Account.h"

using namespace std;

Checking_Account::Checking_Account(string name, double balance)
	: Account(name, balance)
{
}

Checking_Account::~Checking_Account()
{
}

bool Checking_Account::deposit(double amount)
{
	return Account::deposit(amount);
}

bool Checking_Account::withdraw(double amount)
{
	amount += per_check_fee;
	return Account::withdraw(amount);
}

void Checking_Account::print(std::ostream& os) const
{
	os.precision(2);
	os << fixed;
	os << "[Checking_Account: " << name << ": " << balance << "]";
}
