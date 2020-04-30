// Section 19
// Challenge 2
// Automated Grader
#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>

using namespace std;

uint32_t get_score(const string &stu_answer, const string &answer)
{
    uint32_t right_answer = 0;
    for (size_t i = 0; i < answer.length(); i++)
    {
        if (stu_answer.at(i) == answer.at(i))
            ++right_answer;
    }

    return right_answer;
}

void print_header(int stu_len_col, int sco_len_col)
{
    cout << setw(stu_len_col) << left << "Student"
         << setw(sco_len_col) << right << "Score";
    cout << endl;
    cout << setw(stu_len_col + sco_len_col) << setfill('-') << "" << endl
         << setfill(' ');
}

void print_student(int stu_len_col, const string &name, int sco_len_col, uint32_t score)
{
    cout << setw(stu_len_col) << left << name
         << setw(sco_len_col) << right << score;
    cout << endl;
}

void print_footer(int stu_len_col, int sco_len_col, uint32_t total_stu, uint32_t total_score)
{
    cout << setw(stu_len_col + sco_len_col) << setfill('-') << "" << endl
         << setfill(' ');

    cout << setw(stu_len_col) << left << "Average";
    if (total_stu != 0)
        cout << setw(sco_len_col) << right << fixed << setprecision(1)
             << (static_cast<double>(total_score) / total_stu);
    else
        cout << setw(sco_len_col) << right << 0;
    cout << endl;
}

int main()
{
    ifstream in_file;
    string answer;
    string name;
    string stu_answer;
    int stu_len_col = 10;
    int sco_len_col = 5;
    uint32_t score = 0;
    uint32_t total_score = 0;
    uint32_t total_stu = 0;

    in_file.open("responses.txt");

    if (!in_file)
    {
        cerr << "Can not open sources file\n";
        return 1;
    }

    print_header(stu_len_col, sco_len_col);

    in_file >> answer;

    while (in_file >> name >> stu_answer)
    {
        ++total_stu;
        score = get_score(stu_answer, answer);
        print_student(stu_len_col, name, sco_len_col, score);
        total_score += score;
    }

    print_footer(stu_len_col, sco_len_col, total_stu, total_score);
    return 0;
}
