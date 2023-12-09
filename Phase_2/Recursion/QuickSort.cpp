#include<iostream>
using namespace std;

void printArray(int arr[], int size){
    for(int i=0;i < size;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

int partition(int arr[],int s,int e){
   
    int cnt = 0;
    for(int i = s+1;i<=e;i++){
        if(arr[s] > arr[i]){
            cnt++;
        }
    }
    
    int pivotIndex = cnt+s;
    swap(arr[s],arr[pivotIndex]);

    int i = 0;
    int j = e;
    while(i < pivotIndex && j > pivotIndex){
        while (arr[i] < arr[pivotIndex])
        {
            i++;
        }
        while (arr[j] > arr[pivotIndex] )
        {
            j--;
        }
        if(i < pivotIndex && j > pivotIndex){
            swap(arr[i],arr[j]);
            j--;
            i++;
        }
    }
    return pivotIndex;
}

void quicksort(int*arr,int s,int e){
    
    if( s >= e ){
        return;
    }
    int p = partition(arr,s,e);

    //left array
    quicksort(arr,s,p-1);
    //right array
    quicksort(arr,p+1,e);
}

int main(){
    int arr[10] = {56,12, 78, 43,33,453 ,66,};
    int size = 7;
    cout<<"Before Sorting"<<endl;
    printArray(arr, size);
    quicksort(arr,0,size-1);
    cout<<"After Sorting"<<endl;
    printArray(arr, size);
}