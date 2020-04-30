#ifndef _MYSTRING_H_
#define _MYSTRING_H_

class Mystring
{
    friend std::ostream &operator<<(std::ostream &os, const Mystring &rhs);
    friend std::istream &operator>>(std::istream &in, Mystring &rhs);

private:
    char *str;      // pointer to a char[] that holds a C-style string
public:
    Mystring();                                                         // No-args constructor
    Mystring(const char *s);                                     // Overloaded constructor
    Mystring(const Mystring &source);                    // Copy constructor
    Mystring( Mystring &&source);                         // Move constructor
    ~Mystring();                                                     // Destructor
    
    Mystring &operator=(const Mystring &rhs);     // Copy assignment
    Mystring &operator=(Mystring &&rhs);           // Move assignment
	
	bool operator ==(const Mystring& rhs) const; // compare operator < return true if lhs is equal rhs
	bool operator !=(const Mystring& rhs) const; // compare operator < return true if lhs is not equal to rhs
	bool operator < (const Mystring& rhs) const; // compare operator < return true if lhs is smaller than rhs
	bool operator > (const Mystring& rhs) const; // compare operator > return true if lhs is greater than rhs
    
	Mystring operator +(const Mystring& rhs) const;
	Mystring operator += (const Mystring& rhs);
	Mystring operator -() const;
	
	Mystring operator *(size_t repeat) const;
	Mystring operator *=(size_t repeat);
	
	Mystring &operator ++();
	Mystring operator ++(int);
	
    void display() const;
    
    int get_length() const;                                      // getters
    const char *get_str() const;
};

#endif // _MYSTRING_H_