/*
notes:
   If we inhariting B from c and A from B(A------>B---->c)
   1. A is the base class for B and B is base class of C;
   2. A---->B---->C is called inheritance path;

*/

#include <iostream>
using namespace std;

class Student
{
protected:
   int roll_number;

public:
   void set_roll_number(int);
   void get_roll_number(void);
};
void Student ::set_roll_number(int r)
{
   roll_number = r;
}
void Student ::get_roll_number()
{
   cout << "The rool number is rool number" << roll_number << endl;
}
class Exam : public Student
{
protected:
   float mathe;
   float physics;

public:
   void set_marks(float, float);
   void get_marks(void);
};
void Exam ::set_marks(float m1, float m2)
{
   mathe = m1;
   physics = m2;
}
void Exam ::get_marks()
{
   cout << "The marks obtain physics are: " << physics << endl;
   cout << "The marks obtain math are: " << mathe << endl;
}
class Rersult : public Exam
{
   float persentage;

public:
   void display()
   {
      get_roll_number();
      get_marks();
      cout << "Your persentage is" << (mathe + physics / 2) << endl;
   }
};

int main()
{
   Rersult shatadal;
   shatadal.set_roll_number(42);
   shatadal.set_marks(94.8, 98.7);
   shatadal.display();
   return 0;
}
