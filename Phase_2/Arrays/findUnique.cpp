#include<iostream>
using namespace std;

void printArray(int arr[],int size){
    for(int i=0; i<size;i++){
        cout<<arr[i]<<" ";

    }
    cout<<endl;

}

//function to find uniqueelement
int findUnique(int arr[],int size){

    for(int i = 0; i < size;i++){
        for(int j = 0; j < size; j++){
            if(i != j){
                if(arr[i] == arr[j]){
                    break;
                }
                if(j == size-1){
                    return arr[i];
                }
            }            
        }
    }
}


void main(){
   int arr[10] = {10,20,30,40,0,0,70,80,90,100};
    int size;
    cout<<"Enter the size of the array"<<endl;
    cin>>size;
}