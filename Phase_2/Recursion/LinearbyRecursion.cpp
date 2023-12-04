#include<iostream>
using namespace std;

void printArray(int arr[], int size){
    cout<<"The Size Of Array is "<<size<<endl;
    for(int i = 0;i < size;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

bool LinearSearch(int arr[],int size,int key){
    printArray(arr,size);
    //base case
    if(size == 0){
        return false;
    }
    if(arr[0] == key){
        return true;
    }
    int restpart = LinearSearch(arr+1, size-1, key);
    return restpart;
}
 int main (){
    int arr[5] = {23,435,66,7,23};
    int size = 5;
    int key = 232;
    bool found = LinearSearch(arr, size, key);
    if(found){
        cout<<"Key Found"<<endl;
    }
    else{
        cout<<"Key Not Found"<<endl;
    }
 }