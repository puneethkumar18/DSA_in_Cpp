#include<iostream>
using namespace std;

//pretending more than one form : Polymorphism
// it has function overloading and oprator overloadig in compile time polymorpshism
//overriding while runtime

class Calculate{
    //here add function return outpt based on parameter
    public:
    int a;
    int subtract(int a,int b){
        return a-b;
    }
    int add(int a,int b){
        return a+b;
    }

    double add(double a,double b){
        return a+b;
    }

    int add(int a,int b,int c){
        return a+b+c;
    }
   
};
class Subtract : public Calculate{
    //Overriding the subtract function 
    public:
    double subtract(double a,double b){
        return a-b;
    }
};


int main(){

    Calculate c,b;
    Subtract s;
    
    //result of overloading
    cout<<" Adding two double values "<<c.add(10.10,20.20)<<endl;
    cout<<" Adding two Integer values "<<c.add(19,20)<<endl;
    cout<<" Adding two Integer values "<<c.add(19,20,100)<<endl;

    //result of overriding
   cout<<"Output of subtrction: "<< s.subtract(20.22,10.11)<<endl;


}
