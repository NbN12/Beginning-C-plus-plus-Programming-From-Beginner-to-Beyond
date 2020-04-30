#include "Savings_Account.h"

using namespace std;

Savings_Account::Savings_Account(string name, double balance, double int_rate)
	: Account{name, balance}, int_rate{int_rate}
{}

Savings_Account::~Savings_Account()
{
}

bool Savings_Account::deposit(double amount)
{
	amount += amount * (int_rate / 100);
	return Account::deposit(amount);
}

bool Savings_Account::withdraw(double amount)
{
	return Account::withdraw(amount);
}

void Savings_Account::print(std::ostream& os) const
{
	os.precision(2);
	os << fixed;
	os << "[Savings_Account: " << name << ": " << balance << ", " << int_rate << "]";
}
