// Encapsulation is a prosses of:
// 1. Combining variables and function in a single unit(class)
// 2.Protecting data by declaring them as private
#include<iostream>
using namespace std;

class student
{
    string name;
    public:
    void setName(string x){
        name = x;

    }
    string getName(){
        return name;
    }

};

int main()
{
    student s;
    s.setName("Shatadal");
    cout<<s.getName();
   return 0;
}
