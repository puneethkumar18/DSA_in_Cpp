#include<iostream>
using namespace std;

void printArray(int arr[], int size){
    for(int i=0;i < size;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

void selectionsort(int arr[],int size){
    if(size == 1 || size == 0){
        return;
    }
    int minIndex = 0;
    for(int i = 1;i < size;i++){
        if(arr[i] < arr[minIndex]){
            minIndex =  i;
        }
    }
    if(minIndex != 0)
    swap(arr[minIndex],arr[0]);

    selectionsort(arr+1,size-1);
}

int main(){
    int arr[10] = {9,12, 78, 43,33,453 ,667,};
    int size = 7;
    cout<<"Before Sorting"<<endl;
    printArray(arr, size);
    selectionsort(arr,size);
    cout<<"After Sorting"<<endl;
    printArray(arr, size);


} 
