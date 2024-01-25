#include<iostream>
#include<stack>
using namespace std;

// stack using STL 
int main(){
    stack<int> s;

    s.push(20);
    s.push(30);
    s.push(50);

    cout<<"Top of the stack is "<<endl;
    cout<<s.top()<<endl;

    cout<<"berfore pop top of the stack is"<<endl;
    cout<<s.top()<<endl;

    s.pop();

    
    cout<<"after pop topm of stack is "<<endl;
    cout<<s.top()<<endl;

    cout<<endl<<"checking whether stack is empty "<<endl;
    if(s.empty()){
        cout<<"yes stack is empty" << endl;
    }else{
        cout<<"No stack is not empty"<< endl;
    }
}