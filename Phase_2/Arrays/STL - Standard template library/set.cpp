#include<iostream>
#include<set>
using namespace std;


int main(){
    //set is structure of having only unique values
    set<int> set1;
    set1.insert(12);
    set1. insert(24);
    set1.insert(36);
    set1.insert(0);
    set1.insert(12);
    cout<<"size of the set is "<<set1.size()<<endl;
    
    int begin = set1.count(12);
    cout<<"count 12 element is "<<begin<<endl;
    //even though inserting 12 elemetnt 2 time it gives count of 1 Only
    set1.erase(set1.begin(),set1.end());
    cout<<"Size of the set after deleting begin to end  "<<set1.size()<<endl;
}