#include<iostream>
using namespace std;

//function for reverse the Array
void reverseArray(int arr[],int size){
    for(int i=0; i<size/2 ;i++){
        //can be swap inbuilt functon to swap the thing
        int temp = arr[i];
        arr[i] = arr[size-i-1];
        arr[size-i-1] = temp;
    }
    
}


int main(){
    
    int arr[10] = {10,20,30,40,90,80,70,0};
    int size;
    cout<<"Enter the size of the array"<<endl;
    cin>>size;
    reverseArray(arr,size);
    for(int i=0;i<size;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    
}