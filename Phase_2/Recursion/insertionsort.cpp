#include<iostream>
using namespace std;

void printArray(int arr[], int size){
    for(int i=0;i < size;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

void insertionsort(int arr[], int size){
    if(size == 1||size == 0){
        return ;
    }
    insertionsort(arr, size-1);
    for(int i = size-1;i >= 0;i--){
        if(arr[i-1] > arr[i]){
            swap(arr[i-1],arr[i]);
        }else{
            break;
        }
    }
}

int main(){
    int arr[10] = {9,12, 78, 43,33,453 ,66,};
    int size = 7;
    cout<<"Before Sorting"<<endl;
    printArray(arr, size);
    insertionsort(arr,size);
    cout<<"After Sorting"<<endl;
    printArray(arr, size);

}