//Dequeue - Double ended queue

#include<iostream>
#include<deque>
using namespace std;


int main(){
    //declartion
    deque<int> d;

    cout<<"this is declaring deque with size and value to all the index "<<endl;
    deque<int> d1(5,100);
    for(int i = 0; i < d1.size();i++){
        cout<<d1[i]<<" ";
    }
    cout<<endl;

    //copying the another queue
    cout<<"this is copied queue  of d1 - ";
    deque<int> d2(d1);
    for(int i = 0; i < d2.size();i++){
        cout<<d2[i]<<" ";
    }
    cout<<endl;


    cout<<"Pushing elements by oprations"<<endl;
    //opreations
    d.push_back(90);
    d.push_back(12);

    d.push_front(22);
    d.push_front(18);

    for(int i = 0;i < d.size();i++){
        cout<<d[i]<<" ";
    }
  
    cout<<endl<<"after erasing the element in queue"<<endl;
    d.erase(d.begin(),d.begin()+1);

    for(int i = 0 ; i < d.size();i++){
        cout<<d[i]<<" ";
    }
    cout<<endl;

    cout<<"First element of the queue - "<<d.front()<<endl;
    cout<<"Last element of the queue - "<<d.back()<<endl;
    cout<<"Element in the position 2 - "<<d.at(1)<<endl;
    
}