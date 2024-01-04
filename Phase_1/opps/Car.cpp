#include<iostream>
using namespace std;

class Car{
    
    public:
    string name;
    //static variable
    static string name;
    static int model;


    Car(string name){
       this->name = name;
    }
  
    string getname(){
        return name;
    }

};
int Car::model = 2002;
int main(){
    string* name = new string;
    *name = "puneeth";
    Car c1(*name);
   
    
    cout<<Car::model<<endl; 

}