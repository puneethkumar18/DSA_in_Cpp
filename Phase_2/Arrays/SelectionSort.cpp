#include<stdio.h>
#include<iostream>
using namespace std;

void selectionSort(int arr[] ,int n){
    for(int i = 0; i < n; i++){
        int minIndex = i;
        for(int j = i+1; j < n; j++){
            
            if(arr[j] < arr[minIndex] ){
                    minIndex = j;                
            }
            swap(arr[i],arr[minIndex]);
        }
    }
}


int main (){
    int arr[10] = {33,89,12,9,46,76,98,23};
    int n ;
    cout <<"Enter the size of the array"<<endl;
    cin >> n;
    selectionSort(arr, n);
}