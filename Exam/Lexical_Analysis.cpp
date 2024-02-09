#include <iostream>
#include <vector>                        
#include <string>
   

using namespace std;

// function to check if a string is a keyword
bool isKeyword(string str)
{
    string keywords[32] = {"auto", "break", "case", "char", "const", "continue",
                           "default", "do", "double", "else", "enum", "extern", "float", "for", "goto",
                           "if", "int", "long", "register", "return", "short", "signed", "sizeof", "static",
                           "struct", "switch", "typedef", "union", "unsigned", "void", "volatile", "while"};
    for (int i = 0; i < 32; i++)
    {
        if (str.compare(keywords[i]) == 0)
            return true;
    }
    return false;
}

// function to check if a character is an arithmetic operator
bool isArithOperator(char c)
{
    char operators[10] = {'+', '-', '*', '/'};
    for (int i = 0; i < 10; i++)
    {
        if (c == operators[i])
            return true;
    }
    return false;
}

// function to check if a character is an logical operator
bool isLogicalOperator(char c)
{
    char operators[10] = {'=', '>', '<', '%', '&', '|'};
    for (int i = 0; i < 10; i++)
    {
        if (c == operators[i])
            return true;
    }
    return false;
}

int main()
{
    string input;
    int i = 0, len, count_kw = 0, count_id = 0, count_op = 0, count_const = 0,
        count_punc = 0;
    // storing data using vector functions
    vector<string> constants;
    vector<string> keywords;
    vector<string> identifiers;
    vector<char> operators;
    vector<char> logicalOperators;
    vector<char> parentheses;
    vector<char> punctuations;
    cout << "Enter your input: " << endl;
    getline(cin, input);
    len = input.length();
    while (i < len)
    {
        // check for spaces and ignore them
        if (input[i] == ' ')
        {
            i++;
            continue;
        }
        // check for decimal numbers
        if (isdigit(input[i]))
        {
            string temp = "";
            while (isdigit(input[i]) || input[i] == '.')
            {
                temp += input[i];
                i++;
            }
            constants.push_back(temp);
            continue;
        }
        // check for identifiers
        if (isalpha(input[i]))
        {
            string temp = "";
            while (isalnum(input[i]))
            {
                temp += input[i];
                i++;
            }
            if (isKeyword(temp))
                keywords.push_back(temp);
            else
                identifiers.push_back(temp);
            continue;
        }
        // check for operators
        if (isArithOperator(input[i]))
        {
            operators.push_back(input[i]);
            i++;
            continue;
        }

        // check for operators
        if (isLogicalOperator(input[i]))
        {
            logicalOperators.push_back(input[i]);
            i++;
            continue;
        }

        // check for parentheses
        if (input[i] == '(' || input[i] == ')' || input[i] == '{' || input[i] == '}' ||
            input[i] == '[' || input[i] == ']')
        {
            parentheses.push_back(input[i]);
            i++;
            continue;
        }
        // check for punctuation
        if (input[i] == ';' || input[i] == ',' || input[i] == '@' || input[i] == '#' ||
            input[i] == '$' || input[i] == '!' || input[i] == ':')
        {
            punctuations.push_back(input[i]);
            i++;
        }
        i++;
    }
    //using for auto loop in vector function for storing data
    cout << "Constants (" << constants.size() << "): ";
    for (auto x : constants)
    {
        cout << x << " ";
    }
    cout << "\n";
    cout << "Identifiers (" << identifiers.size() << "): ";
    for (auto x : identifiers)
    {
        cout << x << " ";
    }
    cout << "\n";
    cout << "Keywords (" << keywords.size() << "): ";
    for (auto x : keywords)
    {
        cout << x << " ";
    }
    cout << "\n";
    cout << "Arithmetic Operators (" << operators.size() << "): ";
    for (auto x : operators)
    {
        cout << x << " ";
    }
    cout << "\n";
    cout << "Logical Operators (" << logicalOperators.size() << "): ";
    for (auto x : logicalOperators)
    {
        cout << x << " ";
    }
    cout << "\n";
    cout << "Parentheses (" << parentheses.size() << "): ";
    for (auto x : parentheses)
    {
        cout << x << " ";
    }
    cout << "\n";
    cout << "Punctuations (" << punctuations.size() << "): ";
    for (auto x : punctuations)
    {
        cout << x << " ";
    }
    cout << "\n";

    return 0;
}