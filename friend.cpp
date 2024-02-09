#include <iostream>

using namespace std;

class myclass {
   int n, d;
public:
   myclass(int i, int j) { n = i; d = j; }
   friend int isafactor(myclass ob);
};

int isafactor(myclass ob)
{
   if((ob.n % ob.d) == 0) return 1;
   else return 0;
}

int main()
{
   int a, b, r;

   cin >> a >> b;
   myclass ob1(a, b);

   r = isafactor(ob1);

   if(r == 1)
      cout << a << " is divided by " << b << "\n";
   else
      cout << a << " is not divided by " << b << "\n";

   return 0;
}





