// ak e nam ar function but argument gulo alada hoila saita hobe function overloading.
// ar argument ba parameters onujai function call ar somoy choice hoy

#include<iostream>
using namespace std;
int sum(int a, int b)
{
    cout<<"using function with two argument"<<endl;
    return a+b;
}
int sum(int a, int b, int c)
{
    cout<<"using function with three argument"<<endl;
    return a+b+c;
}
// calculate the area of selinder

int volume(double r, int h)
{
    return(3.14 * r * r *h);
}
// calclute the area of cube
int volume(int a){
    return a * a * a;
}
// calclute the area of rectungular box
int volume(int l, int b, int h)
{
    return (l*b*h);
}

int main()
{
    cout<<"The sume of 3 and 6 is "<<sum(3,6)<<endl;
    cout<<"The sume of 3 and 6 and 7 is "<<sum(3,6,7)<<endl;
    cout<<"The volume of cuboid is 3, 7 and 6 "<<volume(3, 7, 6)<<endl;
    cout<<"The volume of selinder is 3, 6 "<<volume(3, 6)<<endl;
    cout<<"The volume of cube is 3 "<<volume(3)<<endl;
   return 0;
}