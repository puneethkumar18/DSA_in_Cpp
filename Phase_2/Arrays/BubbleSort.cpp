#include<iostream>
using namespace std;


void bubbleSort(int arr[] ,int size){
    bool swaped = false;
    for(int i = 1; i < size ;i++){
            for(int j = 0; j < size-i ;j++){
                if(arr[j] > arr[j+1]){
                    swap(arr[j],arr[j+1]);
                    swaped = true;
                }
           
                }
                 if (swaped == false){
                    cout<< "Its already sorted "<<endl;
                    break;
            }
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
    
    bubbleSort(arr,size);

    cout<<"the array after sorted :"<<endl;
    printArray(arr,size);

}