#include<iostream>
using namespace std;
// in line function compile time a replace hoya jay.
// kom line ar function a inline babohar kore..
// recustion a use kora jabe na
// static mane akta vlu reten kore rakhe. jate next vlutar sthe operation korta pare
// ststic ar sathe inline use kora jabe na
// inlien function request kore compilar ar kasa.
inline int product (int i, int j){
   return i*j;
}
float moneyReceived(int currentMoney, float factor=1.04){
   return currentMoney*factor;

}
int main()
{
   int i, j;
   cout<<"Enter the valu of I and J:";
   cin>>i>>j;
   cout<<"the product i and j is: "<<product(i,j)<<endl;
   int money = 100000;
   cout<<"If you habe "<<money<<" taka in your bank account you will recive "<<moneyReceived(money)<<" taka after 1 year"<<endl;
   cout<<"For vip If you habe "<<money<<" taka in your bank account you will recive "<<moneyReceived(money, 1.10)<<" taka after 1 year";



   return 0;
 }
// #include<iostream>
// using namespace std;
// // static mane akta vlu reten kore rakhe. jate next vlutar sthe operation korta pare
// int product (int i, int j){
//    static int k=0;
//    k = k + 1;
//    return i*j+k;
// }
// int main()
// {
//    int i, j;
//    cout<<"Enter the valu of I and J:";
//    cin>>i>>j;
//    cout<<"the product i and j is: "<<product(i,j)<<endl;
//    cout<<"the product i and j is: "<<product(i,j)<<endl;
//    cout<<"the product i and j is: "<<product(i,j)<<endl;
//    cout<<"the product i and j is: "<<product(i,j)<<endl;
//    cout<<"the product i and j is: "<<product(i,j)<<endl;
   


//    return 0;
// }