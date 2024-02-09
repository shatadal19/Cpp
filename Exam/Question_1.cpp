#include <iostream>
using namespace std;

int main()
{
    int x = 40, y = 50, temp;

    cout << "Before swapping." << endl;
    cout << "Input first number:  " << x << ", Input second number:  " << y << endl;

    temp = x;
    x = y;
    y = temp;

    cout << "\nAfter swapping." << endl;
    cout << "Input first number:  " << x << ", Input first number: " << y << endl;

    return 0;
}
