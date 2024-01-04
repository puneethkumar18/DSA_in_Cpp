#include<iostream>
using namespace std;

class Animal{
    public:
    int legs;
    int eyes;

};

// inrehite from one class
class Dog:public Animal{
    public:
    void bark(){
        cout<<"Barking "<<endl;
    }
};
// this inherites from derived / inherited class
class BullDog : public Dog{
    public:

};

int main(){
    BullDog B1;

    B1.eyes = 2;
    B1.legs = 4;


    cout<<"It has "<<B1.legs<<" legs"<<endl;
    cout<<"It has "<<B1.eyes<<" eyes"<<endl;

    B1.bark();
}