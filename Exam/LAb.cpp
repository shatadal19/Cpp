#include<iostream>
#include<cstring>
#include<ctype.h>

using namespace std;
// function to check if a string is a keyword
bool isKeyword(string str) {
 string keywords[32] = {"auto", "break", "case", "char", "const", "continue",
"default",
 "do", "double", "else", "enum", "extern", "float", "for", "goto",
 "if", "int", "long", "register", "return", "short", "signed",
 "sizeof", "static", "struct", "switch", "typedef", "union",
 "unsigned", "void", "volatile", "while"};
 for(int i=0; i<32; i++) {
 if(str.compare(keywords[i]) == 0)
 return true;
 }
 return false;
}
// function to check if a character is an operator
bool isOperator(char c) {
 char operators[10] = {'+', '-', '*', '/', '=', '>', '<', '%', '&', '|' };
 for(int i=0; i<10; i++) {
 if(c == operators[i])
 return true;
 }
 return false;
}
int main() {
 string input;
 int i=0, len, count_kw=0, count_id=0, count_op=0, count_const=0,
count_punc=0;
 getline(cin, input);
 len = input.length();
 while(i < len) {
 // check for spaces and ignore them
 if(input[i] == ' ') {
 i++;
 continue;
 }
 // check for decimal numbers
 if(isdigit(input[i])) {
 string temp = "";
 while(isdigit(input[i]) || input[i] == '.') {
 temp += input[i];
 i++;
 }
 cout << "Constant (" << ++count_const << "): " << temp << endl;
 continue;
 }
 // check for identifiers
 if(isalpha(input[i])) {
 string temp = "";
 while(isalnum(input[i])) {
 temp += input[i];
 i++;
 }
 if(isKeyword(temp))
 cout << "Keyword (" << ++count_kw << "): " << temp << endl;
 else
 cout << "Identifier (" << ++count_id << "): " << temp << endl;
 continue;
 }
 // check for operators
 if(isOperator(input[i])) {
 cout << "Arithmetic Operator (" << ++count_op << "): " << input[i] << endl;
 i++;
 continue;
 }
 // check for parentheses
 if(input[i] == '(' || input[i] == ')') {
 cout << "Parenthesis (" << ++count_punc << "): " << input[i] << endl;
 i++;
 continue;
 }
 // check for punctuation
 if(input[i] == ';') {
 cout << "Punctuation (" << ++count_punc << "): " << input[i] << endl;
 i++;
 continue;
 }
 i++;
 }
 return 0;
}



