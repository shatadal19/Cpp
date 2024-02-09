
#include<iostream>
using namespace std;
int main()
{
    char a;
    float x,y;
   printf("Enter Your First number: ");
   scanf("%f",&x);
   printf("Enter Your operation: ");
   scanf("%f",&a);
   printf("Enter Your Second number: ");
   scanf("%f",&y);
    switch(a){
        case '+':
       printf("Result ="x+y);
        break;
        /*case '-':
       printf("Result = "<<x<<a<<y<<"="<<x-y;
        break;
        case '*':
       printf("Result = "<<x<<a<<y<<"="<<x*y;
        break;
        case '/':
       printf("Result = "<<x<<a<<y<<"="<<x/y;
        break;
        default:
       printf("Your operation is invalid.";
        break;*/
    }

   return 0;
}
