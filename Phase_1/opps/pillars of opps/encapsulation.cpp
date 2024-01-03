#include<iostream>
using namespace std;


class Man{
    public:
    string name;
    int age;
    string address;

    public:
    void walk(){
        cout<<"Walking "<<endl;
    }
    void speaking(){
        cout<<"speaking "<<endl;
    }
    void bikeRide (){
        cout<<"Riding "<<endl;
    }


};

int main(){
    Man person;

    person.name = "ravi";
    person.age = 21;
    

    cout<<"Person name: "<<person.name<<endl;
    cout<<"Age: "<<person.age<<endl;
    cout<<"Address: "<<person.address<<endl;

    person.walk();
    person.speaking();
    person.bikeRide();

   
}