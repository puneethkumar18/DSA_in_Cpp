#include<iostream>
#include<queue>
using namespace std;

int main (){
    //Queue is data structure of elements are added at end of the queue and poping at front
    //(LIFO - last in first out)
    queue<int> q;
    q.push(12);
    q.push(100);
    q.push(24);
    q.push(76);

    cout<<"the size of the queue is "<<q.size()<<endl;
    cout<<"first element in the queue is "<<q.front()<<endl;
    cout<<"last element of the queue is "<<q.back()<<endl;

    q.pop();
    cout<<"checking whether the queue is empty or not "<<endl<<q.empty()<<endl;
    cout<<"after deletion or poping first element is  "<<q.front()<<endl;
    cout<<"after deletion last element is "<<q.back()<<endl;
}