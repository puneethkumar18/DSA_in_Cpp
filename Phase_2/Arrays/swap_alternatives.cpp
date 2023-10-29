#include<iostream>
using namespace std;

void printArray(int arr[],int size){
    for(int i=0; i<size;i++){
        cout<<arr[i]<<" ";

    }
    cout<<endl;

}

//function to swap the altevative elements

void swapAlternate(int arr[],int size){
    for(int i = 0; i < size; i+=2){
        if(i+1 < size){
            swap(arr[i],arr[i+1]);

        }
        
    }
    printArray(arr ,size);
}

int main(){
    int arr[10] = {10,20,30,40,0,0,70,80,90,100};
    int size;
    cout<<"Enter the size of the array"<<endl;
    cin>>size;
    swapAlternate(arr,size);

}