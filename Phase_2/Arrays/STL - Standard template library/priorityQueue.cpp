#include<iostream>
#include<queue>
using namespace std;



int main (){
    //it creates queue of higher to low
    priority_queue<int> p;
    p.push(12);
    p.push(100);
    p.push(1);
    


    cout<<endl;
    cout<<"the size of the priority queue is "<<p.size()<<endl;
    cout<<"top of the queue is equal to  "<<p.top()<<endl;
    cout<<endl;
    p.pop();
    cout<<"top of the queue after deletion is   "<<p.top()<<endl;
    p.push(99);
}
