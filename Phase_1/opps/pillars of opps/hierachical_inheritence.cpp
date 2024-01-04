#include<iostream>
using namespace std;

class Animal{
    public:
    string name;
    int legs;
    int eyes;
};

class Dog:public Animal{
    public:
  
    void sound(){
        cout<< "Barking "<<endl;
        this->name = "Ruby";
        this->eyes = 2;
        this->legs = 4;
    }
};

class Cat:public Animal{
    public:

    Cat(string name,int legs,int eyes){
        this->name = name;
        this->legs = legs;
        this->eyes = eyes;
    };

    void sound(){
        cout<< "Meow Meow "<<endl;
    }
};

int main(){
    Dog d1;
    Cat c1("ravi",4,2);

    d1.sound();

    cout<< "Name od the Dog: "<<d1.name<<endl;
    cout<< "Dog has "<<d1.eyes<<" eyes" <<endl;
    cout<< "Dog has : "<<d1.legs<<" legs"<<endl;

    

    cout<< "Name od the Cat: "<<c1.name<<endl;
    cout<< "Cat has "<<c1.eyes<<" eyes" <<endl;
    cout<< "Cat has : "<<c1.legs<<" legs"<<endl;

    c1.sound();
}