#pragma once

#include "Account.h"

class Savings_Account :
	public Account
{
private:
    static constexpr const char* def_name = "Unnamed Savings Account";
    static constexpr double def_balance = 0.0;
    static constexpr double def_int_rate = 0.0;
protected:
    double int_rate;
public:
    Savings_Account(std::string name = def_name, double balance = def_balance, double int_rate = def_int_rate);
    virtual ~Savings_Account();

    // Inherited via Account
    virtual bool deposit(double amount) override;
    virtual bool withdraw(double amount) override;

    // Inherited via I_Printable
    virtual void print(std::ostream& os) const override;
};

