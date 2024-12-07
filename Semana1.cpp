#include <iostream>
#include <fstream>
#include <cstdint>
#include <vector>
#include <string>

using namespace std;

struct stringCategory
{
    uint32_t size{};
    uint32_t numberOfVowels{};
    uint32_t numberOfConsonants{};
    uint32_t numberOfDigits{};
};

string question1(ifstream &file)
{
    string output{};
    string temp1{};
    string temp2{};
    while (getline(file, temp1))
    {
        temp2 = temp1.substr(0, 7);
        if (temp2 == ".......")
        {
            break;
        }
        output += temp1;
        output += " ";
    }
    return output;
}

vector<int32_t> question2 (string line, string subString)
{
    vector<int32_t> result{};
    uint32_t subStringSize = subString.length();
    uint32_t lineSize = line.length();
    for (uint32_t i = 0; i < lineSize - subStringSize; i++)
    {
        if (line.substr(i, subStringSize) == subString)
            result.push_back(i);
    }
    if (result.empty())
        result.push_back(-1);
    return result;
}

stringCategory question3(string &line)
{
    stringCategory result{};
    result.size = line.length();
    string vowels = "AEIOUaeiou";

    for(char c : line)
    {
        if (isdigit(c))
            result.numberOfDigits += 1;
        if (vowels.find(c) != string::npos)
            result.numberOfVowels += 1;
        if (isalpha(c) && vowels.find(c) == string::npos)
            result.numberOfConsonants += 1;
        if (isalpha(c))
            tolower(c);
    }

}
int main()
{
    ifstream input("input.txt");
    ofstream output("output.output");


    string question1Result = question1(input);
    cout << question1Result << endl;
    vector<int32_t> question2Result = question2(question1Result, "book");

    for (auto i:question2Result)
    {
        cout << i << " ";
    }
    cout << endl;

    input.close();
    output.close();
}
