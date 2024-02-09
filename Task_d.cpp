#include <iostream>
using namespace std;
int price; 
class phone{
    private: //data hiding 
       // Attribute (int variable)
    
    public: 
    string brand; // Attribute (string variable)
    string model; // Attribute (string variable)
    
    
    void description(){   // Method 
        cout<< "A smartphone is a handheld electronic device that integrates various features beyond basic voice communication."<<endl<<endl;
    }
   
    void Dis(string x, string y){ 
      brand =x;
      model =y; 
     
    }
   
};

class OS : private phone{ //singel inheratance
    public:
    void setprice(int p){
        price =p; 
    }
    int getprice(){
        return price; 
    }
     void display(){
        // cout<<"Brand = "<<brand<<" "<<endl<<"Model= "<<model<<endl; 
         cout<<"price: "<<getprice()<<endl<<endl;
    }
};

class  config{
    public:
    string display;
    int refrsh_rate;
    void D(string i, int j){ // constructor
      display =i;
      refrsh_rate =j; 
     
    }
    
};

class PS : public phone, public config{ // Multiple inheritance
    public:
    string ram;
    string rom;
    PS(string a, string b){ //constructor
      ram =a;
      rom =b; 
     
    }
    
     void show(){
        cout<<"Brand = "<<brand<<" "<<endl<<"Model= "<<model<<endl<<"Display = "<<display<<endl<<"REfresh rate = "<<refrsh_rate<<endl<<"Ram = "<<ram<<endl<<"Rom = "<<rom<<endl; 
        }
     ~PS(){
        cout<< "destructor executed."<<endl;// destructor
    }
};

int main(){
    PS hlw("12gb","244gb");
    hlw.Dis("Oppo","Reno 5");
    hlw.D("Amulate",120);
    hlw.show();

    OS hi;
    hi.setprice(10000);
    hi.display();
}