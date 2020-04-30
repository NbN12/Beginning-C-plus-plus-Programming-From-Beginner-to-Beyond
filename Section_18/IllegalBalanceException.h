#ifndef __ILLEGAL_BALANCE_EXCEPTION_H__
#define __ILLEGAL_BALANCE_EXCEPTION_H__

#include <stdexcept>

class IllegalBalanceException : public std::exception
{
public:
    IllegalBalanceException() noexcept = default;
    ~IllegalBalanceException() = default;
	virtual char const* what() const noexcept {
        return "Illegal balance exception";
    }
};

#endif // __ILLEGAL_BALANCE_EXCEPTION_H__
