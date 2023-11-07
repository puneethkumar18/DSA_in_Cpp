#include<iostream>
using namespace std;

int main (){
    int i = 5;
    int *p = &i;
    cout<<"address of that pointer is holding "<<p<<endl;
    cout<<"value in the address pointing by pointer"<<(*p)<<endl;
    //Increment value using pointer
    cout<<"Incremented value "<<++(*p)<<endl; 

    //pointer assign another pointer
    int num = 3;
    int *n = &num;
    int *m = n;
    cout<<"first pointer pointing to "<<(*n)<<" - adress is "<<n<<endl;
    cout<<"second pointer pointing to "<<(*m)<<" - address is "<< m<<endl;

    *n = *n + 1;
    cout<<"Incremented number is  "<<(*m)<<endl;
    //size of the pointer
    cout<<"Size of the pointer is "<<sizeof(n)<<endl; 
    
    //incrementing the pointer itself
    //because of poiter is int datatype it increments 4 bytes
    int a = 1;
    int *ptr = &a;

    cout<<"Before Pointer Incremened - "<<ptr<<endl;  
    ptr = ptr + 1;
    cout<<"After Pointer Incremened - "<<ptr<<endl;  
}