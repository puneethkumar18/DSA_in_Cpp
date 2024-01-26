//Queue follow FIFO - first in first out
#include<iostream>
#include<queue>
using namespace std;

int main(){
    queue<int> q;

    //inserting elements to queue
    q.push(12);
    q.push(24);
    q.push(36);
    q.push(48);
    cout<<"size of the queue is "<<q.size()<<endl;

    cout<<"before pop"<<endl;
    cout<<"front element of the queue is ";
    cout<<q.front()<<endl;
    cout<<"back element of the queue is ";
    cout<<q.back()<<endl;

    q.pop();

    cout<<"After pop"<<endl;
    cout<<"front element of the queue is ";
    cout<<q.front()<<endl;
    cout<<"back element of the queue is  ";
    cout<<q.back()<<endl;

    if(q.empty()){
        cout<< "Queue is empty "<<endl;
    }else{
        cout<<"Queue is Not Empty "<<endl;
    }


    cout<<"size of the queue is "<<q.size()<<endl;

    return 0;
}