// oparetor holo +,-,*,/,& etc.
// operators are workes on build in dada types, it cannot works on user difined data type
// tai computer k bole lage ja user diffined data type a ki vabe oprator use hoy r ai poddothi k operator over loding bole.
//  over loading ar maddome buid in, user diffined a duto e oparetor babohar hoy
// unarry or binary opreator
// unarry-1.Prefix. 2.Postfix..


#include<iostream>
using namespace std;

class Test
{
    int num;
    public:
    Test(){
        num = 0;
    }

    // prefix increment
    void operator++(){
        
        ++num;
        
    }
    // just function ta te parameter babohar korla postfix increement
    void operator++(int){
        
        ++num;
        
    }
    // prefix decremnt
    void operator--(){
        
        --num;
        
    }
    //  just function ta te parameter babohar korla postfix decreement
    void operator--(int){
        
        --num;
        
    }
    void display(){

        cout<<"valu "<<num<<endl;
    }

};

int main()
{
    Test t1;
   t1.display();
    ++t1;
    t1++;
    // --t1;
    // t1--;
    t1.display();
    

   return 0;
}