// kono akta child class thaka parent class ka call korle parent class ar sob public itame cole ase
// tarpor o same name a same vabe function likta hoy duita class a. function ar nam and paramitar same hawa lagbe
// 

#include<iostream>
using namespace std;
class Person
{
    public :
    void Display()
    {
        cout<<"I am a persion"<<endl;
    }
};

class Student : public Person
{
    public :
    void Display()
    {
        cout<<"I am a student"<<endl;
    }
};
class Teacher : public Person
{
    public :
    void Display()
    {
        cout<<"I am a Teacher"<<endl;
    }
};

int main()
{
    Person p;
    p.Display();
    Student s;
    s.Display();
    Teacher t;
    t.Display();

   return 0;
}