#include<iostream>
using namespace std;

class Animal{
    public:
    int legs;
    int eyes;
};

class Dog{
    public:
    void bark(){
        cout<<" barking"<<endl;
    }
};
// inherites from multiple classes
class BullDog: public Animal,public Dog{
    public:
    string name;
    int age;
};


int main(){
    BullDog b1;

    b1.name = "Raamu";
    b1.age = 10;
    b1.eyes = 2;
    b1.legs = 4;

    cout<<"Name of the dog is "<<b1.name<<endl;
    cout<<"Dog's age "<<b1.age<<endl;
    cout<<"Eyes: "<<b1.eyes<<endl;
    cout<<"Legs: "<<b1.legs<<endl;

    b1.bark();
}
