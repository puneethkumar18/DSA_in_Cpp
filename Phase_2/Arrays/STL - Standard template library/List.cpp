#include<iostream>
#include<list>
using namespace std;

int main(){
    //declaration
    list<int> list;
    

    list.push_back(90);
    list.push_front(12);

    cout<<list.size()<<endl;
    cout<<list.back()<<endl;

    
}