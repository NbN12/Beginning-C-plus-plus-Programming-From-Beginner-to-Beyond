#ifndef __INSUFFICIENT_FUNDS_EXCEPTION_H__
#define __INSUFFICIENT_FUNDS_EXCEPTION_H__

#include <stdexcept>

class InsufficientFundsException : public std::exception
{
public:
	InsufficientFundsException() noexcept = default;
	~InsufficientFundsException() = default;
	virtual char const* what() const noexcept {
        return "Insufficent funds exception";
    }
};

#endif // __INSUFFICIENT_FUNDS_EXCEPTION_H__
