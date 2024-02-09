#include<iostream>
using namespace std;
void value(int *a){    // for reference (int *a)
   *a=20;              // for reference *a = 20;
}
int main()
{
    int a=10;
    value(&a);         // for reference value (&a)
    cout<<a;
    return 0;
    }
