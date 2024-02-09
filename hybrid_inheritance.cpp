#include <iostream>
using namespace std;

class A
{
public:
    void show()
    {
        cout << "I am a" << endl;
    }
};
class b : public A

{
public:
    void msg()
    {
        cout << "I am b" << endl;
    }
};
class c
{
public:
    void display()
    {
        cout << "I am c" << endl;
    }
};
class d : public b, public c
{
public:
    void output()
    {
        cout << "I am d" << endl;
    }
};

int main()
{
    d dog;
    dog.show();
    dog.msg();
    dog.display();
    dog.output();

    return 0;
}