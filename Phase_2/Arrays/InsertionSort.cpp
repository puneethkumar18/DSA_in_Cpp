#include<iostream>
using namespace std;


void insertionSort(int arr[],int size){
    for(int i = 1; i < size; i++ ){
        int temp = arr[i];
        int j = i-1;
        for (; j>=0; j--){
            if( arr[j] > temp){
                arr[j+1] = arr[j];
            }
            else{
                break;
            }
        }
        arr[j+1] = temp;
    }

}

void printArray(int arr[] ,int size){
    for(int i = 0;i < size; i++){
        cout<<" "<<arr[i];
    }
}

int main (){
    int arr[10] = {10,3,89,64,23,90} ;
    int size;
    cout<<"Enter the size of the array"<<endl;
    cin >> size;
    cout<<"enter the elements of the array"<<endl;
    for(int i=0; i < size; i++){
        cin >> arr[i];
    }
    
    insertionSort(arr,size);

    cout<<"the array after sorted :"<<endl;
    printArray(arr,size);

}