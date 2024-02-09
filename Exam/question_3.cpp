#include<iostream>
using namespace std;

class Animal
{
public:

    void eat()
    {
        cout << "Each animals needs to eat for survive \n" ;
    }
    void sleep()
    {
        cout << "Every animals need to sleep. \n" ;
    }
    void born()
    {
        cout << "we was born once. \n" ;
    }
    void die()
    {
        cout << "we die at a point. \n" ;
    }


};




class Reptile : public Animal
{
public:
    void eat()
    {
        cout << "Each animals needs to eat for survive \n" ;
    }
    void sleep()
    {
        cout << "Every animals need to sleep. \n" ;
    }
    void born()
    {
        cout << "I was born once. \n" ;
    }
    void die()
    {
        cout << "I die at a point. \n" ;
    }
    void move()
    {
        cout<<" I crawl.";
    }

};
class Aves: public Animal
{
public:
    void eat()
    {
        cout << "Each animals needs to eat for survive \n" ;
    }
    void sleep()
    {
        cout << "Every animals need to sleep. \n" ;
    }
    void born()
    {
        cout << "I was born once. \n" ;
    }
    void die()
    {
        cout << "I die at a point. \n" ;
    }
    void move()
    {
        cout<<" I fly.";
    }

};
class Mammal : public Animal
{
public:
    void eat()
    {
        cout << "Each animals needs to eat for survive \n" ;
    }
    void sleep()
    {
        cout << "Every animals need to sleep. \n" ;
    }
    void born()
    {
        cout << "I was born once. \n" ;
    }
    void die()
    {
        cout << "I die at a point. \n" ;
    }
    void move()
    {
        cout<<" I walk.";
    }

};


class Dog: public Mammal
{
public:

    void bark()
    {
        cout << "I bark.\n" ;
    }

    void swim()
    {
        cout << "I swim. \n" ;
    }
    void domestic()
    {
        cout << "I live in domestic environment. \n" ;
    }

};
class Birds: public Aves
{
public:

    void sound()
    {
        cout << "I make kuhu sound.\n" ;
    }

    void fly()
    {
        cout << "I fly. \n" ;
    }
    void domestic()
    {
        cout << "I live in domestic environment. \n" ;
    }

};
class Snake: public Reptile
{
public:

    void sound()
    {
        cout << "I make hiss sound.\n" ;
    }

    void swim()
    {
        cout << "I swim. \n" ;
    }
    void wild()
    {
        cout << "I live in wild environment. \n" ;
    }

};

class Germanshepard : public Dog
{
public:
    void behavior()
    {
        cout << "I'm ferocious, strong and used in military.\n" ;
    }

};
class BullDog : public Dog
{
public:
    void behavior()
    {
        cout << "I'm popular, small and seen in western countries.\n" ;
    }

};
int main()
{
    Animal a;
    a.eat();
    a.born();
    a.sleep();
    a.die();
    cout<<endl<<endl;

    Reptile b;
    b.eat();
    b.born();
    b.sleep();
    b.die();
    b.move();
    cout<<endl<<endl;

    Aves c;
    c.eat();
    c.born();
    c.sleep();
    c.die();
    c.move();
    cout<<endl<<endl;

    Mammal d;
    d.eat();
    d.born();
    d.sleep();
    d.die();
    d.move();
    cout<<endl<<endl;

    Dog e;
    e.bark();
    e.swim();
    e.domestic();

    cout<<endl<<endl;

    Birds f;
    f.sound();
    f.fly();
    f.domestic();

    cout<<endl<<endl;

    Snake g;
    g.sound();
    g.swim();
    g.wild();

    cout<<endl<<endl;

    BullDog h;
    h.bark();
    h.swim();
    h.domestic();
    h.behavior();
    cout<<endl<<endl;

    Germanshepard i;
    i.bark();
    i.swim();
    i.domestic();
    i.behavior();

    cout<<endl<<endl;

    return 0;
}
