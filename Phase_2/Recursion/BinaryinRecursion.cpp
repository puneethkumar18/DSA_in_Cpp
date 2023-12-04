#include<iostream>
using namespace std;

bool BinarySearch(int arr[], int s, int e, int key){
    //basecase
   if (s > e){
    return false;
   }
   int mid = s + (e-s)/2;
   if (arr[mid] == key){
    return true;
   }
    else if (arr[mid] < key){
        return BinarySearch(arr, mid+1,e,key);
    }
    else{
        return BinarySearch(arr,s, mid-1,key);
    }
}

int main (){
    int arr[10] = {1,2,3,4,5,6,7};
   
    int key = 0;
    bool found = BinarySearch(arr,0,6,key);
    if (found){
        cout<<"Key Found"<<endl;
    }
    else{
        cout<<"Key Not Found"<<endl;
    }

}