// Section 19
// Challenge 4
// Copy Romeo and Juliet with line numbers
#include <iostream>
#include <fstream>
#include <string>

using std::cerr;
using std::cout;
using std::endl;
using std::getline;
using std::ifstream;
using std::ofstream;
using std::string;

int main()
{
    string in_file_name{"romeoandjuliet"};
    ifstream in_file{in_file_name};
    if (!in_file.is_open())
    {
        cerr << "Can not open" + in_file_name + " file\n";
        return 1;
    }

    string out_file_name{"romeo_and_juliet_with_line_number.txt"};
    ofstream out_file{out_file_name};

    if (!out_file.is_open())
    {
        cerr << "Can not open" + out_file_name + " file\n";
        return 2;
    }

    string temp{};
    uint32_t line = 1;

    while (getline(in_file, temp))
    {
        if (temp.length() != 0)
            out_file << line++ << "\t\t" << temp;
        out_file << endl;
    }

    in_file.close();
    out_file.close();

    cout << "Write successful\n";
    return 0;
}
