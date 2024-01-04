#include<iostream>
#include<vector>
using namespace std;




//printng array
void printArray(int arr[],int n){
    for(int i=0;i<n;i++){
        cout<<" "<<arr[i];
    }
    cout<<endl;
}

//moving zeros to right of array

void moveZeros(int arr[],int size){
    for(int i = 1 ;i < size;i++){
            for(int j = i ; j > 0; j--){
                if(arr[j-1] == 0 && arr[j] > 0){
                    swap(arr[j-1],arr[j]);
                    
                }
                else{
                    break;
                }
            }
        
        }
    }





//mergeing two sorted arrays in soretd 
void mergeSortedArray(int arr1[],int size1,int arr2[],int size2){
    int i = 0, j = 0;
    vector<int> arr;
    while(i < size1 && j < size2){
        if (arr1[i] < arr2[j]){
            arr.push_back(arr1[i]);
            i++;
            
        
        }
        else if(arr1[i] > arr2[j]){
            arr.push_back(arr2[j]);
            j++;
        } 
    }
    while(i < size1){
        arr.push_back(arr1[i]);
        i++;
    }
    while(j < size2){
        arr.push_back(arr2[j]);
        j++;
    }
    cout<<"the Sorted array is "<<endl;
    cout<<"[ ";
    for(int i = 0; i < arr.size();i++){
        cout<<arr[i]<<",";
    }
    cout<<" ]"<<endl;

}

void enterArrayElement(int arr[] ,int n){
    
    cout<<"Enter the elemnts of array"<<endl;
    for(int i = 0; i < n; i++){
        cin>>arr[i];
    }
}

int main(){
    int arr1[10];
    /*
    int arr2[10];
    int n1,n2;
    cout<<"Enter the size of first array "<<endl;
    cin>>n1;
    enterArrayElement(arr1,n1);
    cout<<arr1[0]<<" "<<arr1[1]<<endl;
    cout<<"Enter the size of Second array "<<endl;
    cin>>n2;
    enterArrayElement(arr2,n2);
    mergeSortedArray(arr1,n1,arr2,n2);

    */
    int n1;
    cout<<"Enter the size of first array "<<endl;
    cin>>n1;
    enterArrayElement(arr1,n1);
    moveZeros(arr1,n1);
    printArray(arr1,n1);
}
