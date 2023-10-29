#include<iostream>
using namespace std;

//Linear Search
int search(int arr[],int size,int key){
    for(int i = 0;i < n;i++){
        if (arr[i] == key){
            return 1;
        }
    }
    return 0;
    
}

int main(){
    int arr[10] = {-2,-89,98,4,8,39,28,292,18,90};
    int key,size;
    cout<<"Enter the key to be found"<<endl;
    cin >> key;
    cout<<"Enter the size of array "<<endl;
    cin >> size;
    bool found = search(arr , size,key);

    if(found){
        cout<<key<<" is present in the array"<<endl;
    }
    else{
        cout<< key<<" is not present in the array"<<endl;
    }
}