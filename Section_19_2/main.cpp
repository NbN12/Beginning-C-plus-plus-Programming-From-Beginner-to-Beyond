// Section 19
// Challenge 2
// Automated Grader
#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>

using namespace std;

uint32_t count_right_answer(const string &stu_answer, const string &answer)
{
    uint32_t right_answer = 0;
    for (size_t i = 0; i < answer.length(); i++)
    {
        if (stu_answer.at(i) == answer.at(i))
            ++right_answer;
    }

    return right_answer;
}

int main()
{
    ifstream in_file;
    in_file.open("responses.txt");
    if (!in_file.is_open())
    {
        cout << "Can not open sources file\n";
        return 1;
    }

    string stu_answer;
    string answer;
    string name;
    int stu_len_col = 10;
    int sco_len_col = 5;
    uint32_t score = 0;
    auto len = answer.length();
    uint32_t total_score = 0;

    cout << setw(stu_len_col) << left << "Student"
         << setw(sco_len_col) << right << "Score";
    cout << endl;
    cout << setw(stu_len_col + sco_len_col) << setfill('-') << "" << endl
         << setfill(' ');

    in_file >> answer;

    while (in_file >> name >> stu_answer)
    {
        score = count_right_answer(stu_answer, answer);
        cout << setw(stu_len_col) << left << name
             << setw(sco_len_col) << right << score;
        cout << endl;
        total_score += score;
    }
    cout << setw(stu_len_col + sco_len_col) << setfill('-') << "" << endl
         << setfill(' ');

    cout << setw(stu_len_col) << left << "Average"
         << setw(sco_len_col) << right << (static_cast<double>(total_score) / len);
    return 0;
}
