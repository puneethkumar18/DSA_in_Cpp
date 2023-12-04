#include<iostream>
using namespace std;

bool isSorted(int arr[],int size){
    //base case
    if(size == 0 || size == 1){
        return 1;
    }

    if(arr[0] > arr[1]){
        return false;
    }else{
        bool remainingpart = isSorted((arr+1),(size-1));
        return remainingpart;
    }
}

int main(){
    int arr[10] = {2,3,4,56,9};
    int size = 5;
    cout<<"The given Array is ";
    bool result  = isSorted(arr,size);
    if(result){
        cout<<" Sorted"<<endl;
    }else{
        cout<<" Not Sorted"<<endl;
    }
}
