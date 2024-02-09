// Abstruction is this prosses of hiding the implementation ditails and showing only the functionality to the user;
//class ar kono body thake na,
// class ar kono object hoy na.
// pointer diya object rakha jbe
// ata constructor hoita parbe.
// function ar age vairtual diya diclear korta hobe


#include<iostream>
using namespace std;

// Abstruct class
// 1.virtual function obossoi rakta hobe, non vartual o rakha jbe

class Mobileuser
{
    public:
    void call(){
        cout<<"hello"<<endl;
    }

    virtual void sendMessage() = 0;//pure vartual function;
};
class Shatadal : public Mobileuser{
    public:
    void sendMessage(){
        cout<<"Hi this is shatatadal"<<endl;
    }
};
class Animesh : public Mobileuser{
    public:
    void sendMessage(){
        cout<<"Hi this is Animesh"<<endl;
    }
};

int main()
{
    Mobileuser *m;

    Shatadal s;
    Animesh a;
    m = &s;
    m->sendMessage();
    m = &a;
    m->sendMessage();
    m->call();

   return 0;
}