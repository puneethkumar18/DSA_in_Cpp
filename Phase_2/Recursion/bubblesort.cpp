#include<iostream>
using namespace std;
void printArray(int arr[],int size){
    for (int i = 0; i<size;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

void bubblesort(int arr[], int size){
    //base case
    if(size == 1){
        return ;
        }
    
    
    for(int i = 0;i < size;i++){
        if(arr[i] > arr[i+1]){
            swap(arr[i],arr[i+1]);
        }   
    }
    bubblesort(arr,size-1);
}

int main(){
    int arr[6] = {11,2,33,4,55,6};
    int size = 6;
    cout<<"Before Sorting"<<endl;
    printArray(arr, size);
    bubblesort(arr,size);
    cout<<"After Sorting"<<endl;
    printArray(arr, size);

}