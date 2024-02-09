// reusabilaty is very importent ferure off OOPs
// in c++ we can reuse a class and add additionalmfeature to it
// reduse classes save time and money
// reusing already tested and debugged class will save a lot of effort developing and debugging the same again.

#include <iostream>
using namespace std;
// bass class
class Employ
{
    

    // float salary;
public:

    int id;
    float salary;
    Employ(int inpId)
    {
        id = inpId;
        
        salary = 34;
    }
    Employ() {}
};

// drived class
/*class {{derived-class-name}} : {{visibility-mode}} {{base-class-name}}
{
    class member/method etc.
}
1

*/
//
class Programer : public Employ
{
public:
    Programer(int inpId)
    {
        id = inpId;
    }
    int languagecode = 9;
    void getdata(){
        cout<<id<<endl;
    }
};

int main()
{
    Employ shatadal(1), shovon(2);
    cout << shatadal.salary << endl;
    cout << shovon.salary << endl;
    Programer skillFF(1);
    cout << skillFF.languagecode << endl;
    cout << skillFF.id << endl;
    
    skillFF.getdata();
    return 0;
}