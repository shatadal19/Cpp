#include <iostream>
using namespace std;

// syntax for inheriting  in multiple inheritance
// class Derivedc: visibility-mode base1, visibility mode base2
// {
//     class body of class "Drivedc"
// };

class base1
{
protected:
    int base1int;

public:
    void set_base1int(int a)
    {
        base1int = a;
    }
};
class base2
{
protected:
    int base2int;

public:
    void set_base2int(int a)
    {
        base2int = a;
    }
};
class base3{
protected:
int base3int;
public:
    void set_base3int(int a)
    {
        base3int = a;
    }
};
class Drived : public base1, public base2, public base3{
    public:
    void show(){
        cout<<"The valu of base1 is: "<<base1int<<endl;
        cout<<"The valu of base2 is: "<<base2int<<endl;
        cout<<"The valu of base3 is: "<<base3int<<endl;
        cout<<"The sum of base1 and base2 and base3 is: "<<base1int + base2int+base3int<<endl;
    }
};

int main()
{
    Drived shatadal;
    shatadal.set_base1int(25);
    shatadal.set_base2int(5);
    shatadal.set_base3int(10);

    shatadal.show();
    return 0;
}