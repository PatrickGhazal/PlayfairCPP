#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const string EMPTY_STR = "";
string table;
string preppedMessage;
string translated;

char toUpperCase(char ch)
{
    return ch - (ch >= 'a' ? 32 : 0);
}

bool isLetterNotY(char ch)
{
    return (ch >= 'A' && ch <= 'X') || ch == 'Z' || (ch >= 'a' && ch <= 'x') || ch == 'z';
}

void translate(string mode)
{
    int direction = mode == "E" ? 2 : -2;

    for (unsigned i = 0; i < preppedMessage.length(); i += 2) {
        string let1 = EMPTY_STR + preppedMessage.at(i);
        string let2 = EMPTY_STR + preppedMessage.at(i + 1);
        int let1Index = table.find(let1);
        int let2Index = table.find(let2);
        // diff = Math.abs(1 - 2)
        //TODO notebook rules for diff
    }

    //TODO delete following line
    translated = preppedMessage;
}

void prepMessage(string message, string mode)
{
    string charPairs;

    for (unsigned i = 0; i < message.length(); i++)
    {
        char ch = message.at(i);
        if (isLetterNotY(ch))
        {
            ch = toUpperCase(ch);
            if (charPairs.length() == 2)
            {
                preppedMessage += charPairs;
                charPairs = EMPTY_STR + ch;
            }
            else
            {
                charPairs += ch;
            }
        }
    }
    preppedMessage += charPairs;

    if (mode == "E" && charPairs.length() == 1) preppedMessage += "X";
}

string searchChInTable(char ch)
{
    string letter = EMPTY_STR + toUpperCase(ch);
    return table.find(letter) == -1 ? letter : EMPTY_STR;

}

void genTable(string keyword) //TODO study speed of removing table letters from alphabet
{
    const string alphabet = "abcdefghijklmnopqrstuvwxz"; // y merged with i to make a 5x5 table
    char ch;
    for (unsigned i = 0; i < keyword.length(); i++)
    {
        ch = keyword.at(i);
        if (isLetterNotY(ch)) table += searchChInTable(ch);
    }
    for (unsigned i = 0; i < alphabet.length(); i++) table += searchChInTable(alphabet.at(i));
}

int main()
{
    string keyword, message, mode;

    cout << "Please enter the keyword.";
    getline(cin, keyword);

    cout << "Please enter the message.";
    getline(cin, message);

    cout << "Encode or Decode? Please type 'E' or 'D'.";
    while (mode != "E" && mode != "D") getline(cin, mode);

    genTable(keyword);
    prepMessage(message, mode);
    translate(mode);

    cout << table << "\n" << preppedMessage << "\n" << translated << endl;

    return 0;
}
