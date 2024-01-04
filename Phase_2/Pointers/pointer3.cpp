#include<iostream>
using namespace std;

//function of checking changes and passing double pointer
void updated(int ** ptr){
  //ptr = ptr +1;
  
  //*ptr = *ptr + 1;

  **ptr = **ptr +1;
   
}

int main(){
  //creating multilevel pointer
    int value = 5;
    int *p = &value;
    int **p1 = &p;
    
    cout<<"Address of the value "<<&value<<endl;
    cout<<"Address of the pointer one "<<&p<<endl;
    cout<<"Address of the pointer two "<<&p1<<endl;
    cout<<"pointer 2 final pointing value is "<<**p1<<endl;
    cout<<endl<<endl;


    cout<<"Before update value "<<value<<endl;
    cout<<"Before update pointer "<<p<<endl;
    cout<<"Before update pointer 2 "<<p1<<endl;
    updated(p1);
    
    cout<<"After update value "<<value<<endl;
    cout<<"After update pointer "<<p<<endl;
    cout<<"After update pointer 2 "<<p1<<endl;



    //cout<<"successfully craeted double pointer"<<endl;
    
  }