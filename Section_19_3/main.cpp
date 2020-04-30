// Section 19
// Challenge 3
// Word counter
#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

static vector<string> texts;

void load_text(ifstream &in_file)
{
    string temp;
    while (in_file >> temp)
        texts.push_back(temp);
}

static uint32_t search(const string &user_input)
{
    uint32_t count = 0;
    for (const string &text : texts)
        if (text.find(user_input) != string::npos)
            ++count;
    return count;
}

int main()
{
    ifstream in_file;
    in_file.open("romeoandjuliet.txt");
    if (!in_file)
    {
        cerr << "Can not open file\n";
        return 1;
    }

    load_text(in_file);

    string user_input;
    while (1)
    {
        cout << "Enter the substring to search for file \"romeoandjuliet.txt\" or type (q or Q) to quit: ";
        cin >> user_input;
        if (user_input == "q" || user_input == "Q")
            break;
        uint32_t result = search(user_input);
        cout << texts.size() << " words were searched...\n";
        cout << "The substring " << user_input << " was found " << result << " times\n";
    }

    cout << "GOOD BYE\n";
    return 0;
}
