#include<iostream>
using namespace std;

// adstact class
class Calculate{
    public:
    int add(int a,int b);
};
class Add : public Calculate{
    public:
    int add(int a,int b){
        return a+b;
    }
};

int main(){
    Add a;

    cout<<"Output of Addition is :"<<a.add(10,20)<<endl;
    
}