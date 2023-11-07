#include<iostream> 
#include<stack>
using namespace std;

int main(){

    //stack is data structure of elements added first can be poped at last
    //(FILO - first in last out)
    stack<int> s;
    cout<<"size of the stack is  "<<s.size()<<endl;
    s.push(12);
    s.push(24);
    s.push(36);
    s.push(48);
    cout<<"size of the stack is  "<<s.size()<<endl;
    cout<<"top of the stack is "<<s.top()<<endl;
    s.pop();
    cout<<"size of the stack is  "<<s.size()<<endl;
    cout<<"top of the stack is "<<s.top()<<endl;
    cout<<"stack is empty or not "<<s.empty()<<endl;

}