#include<iostream>
using namespace std;
//reference varibale - varible pointing to another variable and their address

//pass by reference variable
void update(int& n){
    n = n+1;
}
//retturing ref  from function
//but while passing or returning reference varible declare in function gets dicarded after closing braces.
//so return ref get discared;
int& update1(int a){
    int a = 5;
    int& ans = a;
    return ans; 
}

int main(){
    int i = 10;
    //creating reference variable for i

    int& j = i;

    cout<<"main variable value is "<<i<<endl;
    cout<<"reference variable is "<<j<<endl;

    //increment using ref variable
    cout<<"Before increment by ref variable "<<j<<endl;
    j++;
    cout<<"After increment by ref variable "<<j<<endl;

    cout<<"Before passing to function "<<j<<endl;
    update(j);
    cout<<"After passing to function "<<i<<endl;

}