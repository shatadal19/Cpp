// constructor ar num class ar  num ar same hoita hobe
//  copy constructor amon akta constructor ja onno object ar copy banay day
// when no constructor is found then compailer provide his won constructor
#include <iostream>
using namespace std;

class Number
{

    int a;

public:
    Number()
    {
        a = 0;
    }
    Number(int num)
    {
        a = num;
    }
    Number(Number &obj)
    {
        cout << "Copy constructor called!!!" << endl;
        a = obj.a;
    }
    void display()
    {
        cout << "The Number for the object is: " << a << endl;
    }
};

int main()
{
    Number x, y, z(45),z2;
    x.display();
    y.display();
    z.display();
    Number z1(x);//copy constructor invoked
    z1.display();
    z2 = z;//copy constructor not invoked
    Number z3 = z;//copy constructor invoked
    return 0;
}
