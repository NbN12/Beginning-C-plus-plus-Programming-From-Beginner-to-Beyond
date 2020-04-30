#pragma once

#include <iostream>
#include <string>
#include "Account.h"

class Checking_Account :
	public Account
{
private:
    static constexpr const char* def_name = "Unnamed Checking Account";
    static constexpr double def_balance = 0.0;
    static constexpr double per_check_fee = 1.5;
public:
    Checking_Account(std::string name = def_name, double balance = def_balance);
    virtual ~Checking_Account();

    // Inherited via Account
    virtual bool deposit(double amount) override;

    virtual bool withdraw(double amount) override;

    virtual void print(std::ostream& os) const override;
};

