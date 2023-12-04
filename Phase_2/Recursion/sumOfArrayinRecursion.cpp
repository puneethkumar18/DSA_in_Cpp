#include<iostream>
using namespace std;

int sumOfArray(int arr[],int size){
    //base case
    if(size == 0){
        return 0;
    }
    if(size == 1){
        return arr[0];
    }

    int sum = arr[0]+sumOfArray(arr+1,size-1);
    
    return sum;
}

int main(){
    int arr[10] = {2,3,4};
    int size = 3;

    int sum = sumOfArray(arr,size);
    cout<<"Sum Of The Elements Of Array "<<sum<<endl;
}