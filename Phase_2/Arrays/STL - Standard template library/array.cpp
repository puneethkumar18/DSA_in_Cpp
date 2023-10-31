#include<iostream>
#include<array>
using namespace std;

int main (){
    //array declaration
    //arrary<data type> 
    array<int,10> arr = {10,20,30,40,0,0,70,80,90,100};

    //Operation
    int size = arr.size();
    int firstElelment = arr.front();
    int lastElement = arr.back();
    bool isEmpty = arr.empty();
    cout<<"The size of array  "<<size<<endl;
    cout<<"firstElement of the array "<<firstElelment<<endl;
    cout<<"lastElement of the array "<<lastElement<<endl;
    cout<<"is the array Empty "<<isEmpty<<endl;

    
}