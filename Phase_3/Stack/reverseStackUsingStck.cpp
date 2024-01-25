#include<iostream>
#include<stack>
using namespace std;

int main(){
    string name = "puneeth";
    stack<char> sc;

    for(int i=0; i<name.length();i++){
        sc.push(name[i]);
    }
    
    for(int i=0; i<name.length();i++){
        name[i] = sc.top();
        sc.pop();
    }

    cout<<"Reversed String is "<<endl;
    cout<<name<<endl;
}