// Section 20
// Challenge 1
// Identifying palindrome strings using a deque
#include <cctype>
#include <deque>
#include <iostream>
#include <string>
#include <vector>
#include <iomanip>

bool is_palindrome(const std::string& s)
{
    // You must implement this function.
    // Since we are learning the STL - use a deque to solve the problem.
    std::deque<char> temp{std::begin(s), std::end(s)};
    char first = '\0';
    char last = '\0';
    while (!temp.empty())
    {
        if (!std::isalpha(temp.front()))
            temp.pop_front();
        else if (!std::isalpha(temp.back()))
            temp.pop_back();
        else
        {
            if (std::toupper(temp.front()) != std::toupper(temp.back()))
                return false;
            else
                if (temp.size() == 1)
                    temp.pop_back();
                else
                {
                    temp.pop_back();
                    temp.pop_front();
                }
        }
    }
    return true;
}

int main()
{
    std::vector<std::string> test_strings{ "a", "aa", "aba", "abba", "abbcbba", "ab", "abc", "radar", "bob", "ana",
        "avid diva", "Amore, Roma", "A Toyota's a toyota", "A Santa at NASA", "C++",
        "A man, a plan, a cat, a ham, a yak, a yam, a hat, a canal-Panama!", "This is a palindrome", "palindrome" };
   
    std::cout << std::boolalpha;
    std::cout << std::setw(8) << std::left << "Result" << "String" << std::endl;
    for(const auto& s : test_strings) {
        std::cout << std::setw(8) << std::left << is_palindrome(s)  << s << std::endl;
    }
    std::cout << std::endl;
    return 0;
}