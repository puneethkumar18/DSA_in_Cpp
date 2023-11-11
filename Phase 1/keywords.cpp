#include<iostream>
using namespace std;

//declaring value which is constant and frequently used also not modify
//pi value is unchangeable
#define PI 3.14

//global variable which can be access and modifiable to all the function (bad practice)
int i = 5;

//inline function :- telling compiler to replace if the function consist of 1 or 2-3 line of code
//replace with called statement
//it avoid creation of memroy for parameter and function calling overloading
inline int getMax(int a, int b){
    return (a > b)? a:b;
}

//default argument :- function itself has given value to argument if argument is not passed than default value works
//here start is default argument with 0 value
//all default argument has to be declare right most (int arr[], int size, int start = 0)like this 
//(int arr[],int size = 5,int start) it is not correct all should be in right most 
void printArray(int arr[], int size,int start = 0){
        for(int i = start;i < size;i++){
            cout<<arr[i]<<" ";
        }
        cout<<endl;
}

void updated(){
    
    cout<<"global variable updating in upadate function "<<endl;
    cout<<"before update global variable "<<i<<endl;
    i++;
    cout<<"after update global variable "<<i<<endl;
    
}

int main(){
    cout<<"Global variable  i value is "<<i<<endl;
    updated();

    int a,b;
    cout<<"enter two number with space or Enter"<<endl;
    cin>>a;
   
    cin>>b;
    int ans = getMax(a,b);//it is replaced by compile ((a > b)? a:b;)in inline function
    cout<<"greater num is "<<ans<<endl;

    int arr[5] = {4,5,98,56,43};
    int size = 5;
    cout<<"without giving start argument "<<endl;
    printArray(arr,size);

    cout<<"with giving start argument as 1 "<<endl;
    printArray(arr,size,1);

    


}