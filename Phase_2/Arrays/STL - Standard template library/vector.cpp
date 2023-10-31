#include<iostream>
#include<vector>
using namespace std;

int main (){
    
    //initilisation 
    //it has zero size and capacity
    vector<int> vector1;
 
    //9 is size and all the index is filled with 1
    vector<int> v(9,1);
    for(int i:v){
        cout<<i<<" ";
    }

    //makes a copy
    vector<int> v2(v);

    // to add element to array/vector, 90 is element
    v.push_back(90);

    //pop the last element in the arrays
    v.pop_back(); 
      
    //fetch first and last element
    cout<<"firstElement "<<v.front()<<endl;
    cout<<"lastElement "<<v.back()<<endl; 
  
    //full empty array but capacity =! zero 
    v.clear();
}