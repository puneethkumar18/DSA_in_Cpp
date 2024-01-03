#include<iostream>
using namespace std;

class Human{
    public:
    string name;
    int age;

    public:
    void run(){
        cout<<" Running "<<endl;
    }
};

//Single Inheritance

class Men:public Human{
      public:
      string address;
};
 
int main(){
    Men men;

    men.name = "Aleen";
    men.age = 35;
    men.address = "rameshwaram";

    cout<<"Name: "<<men.name<<endl;
    cout<<"Age: "<<men.age<<endl;

    men.run();
}
