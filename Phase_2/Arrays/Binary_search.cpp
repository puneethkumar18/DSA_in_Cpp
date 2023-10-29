#include<iostream>
using namespace std;


// function to find element in roteted array
int findElementInRotetedArray( int arr[],int size,int key){
    int pivot = findPivot(arr,size);
    if(arr[pivot] <= key && arr[size-1] >= key){
        return binarySearch(arr,pivot,(size-1),key);
    }
    else{
        return binarySearch(arr,0,pivot-1,key);
    }

}

// function to find pivot position in the roteted array
int findPivot(int arr[],int size){
    int low = 0;
    int high = size-1;
    int mid = low + (high - low)/2;

    while(low <= high) {
        if( arr[mid] >= arr[0]){
            low = mid+1;
        }
        else{
            high = mid;
        }
    }
    return low;
} 

// find the peak element of the array
int peakElement(int arr[], int size){
    int low = 0;
    int high = size-1;
    int mid = low + (high - low)/2;
    
    while(low <= high){
        if (arr[mid] > arr[mid+1] && arr[mid] > arr[mid-1]){
            return mid;
        }
        else if( arr[mid] < arr[mid+1]){
            low = mid + 1;
        }
        else if ( arr[mid] < arr[mid-1]){
            high = mid - 1;
        }
        mid = low +(low+high)/2;
    }
    return -1;
}


// function for first occrance of the element (key) in the array
int firstOuccrance(int arr[], int size , int key){
    int low = 0;
    int high = size-1;
    int mid = low + (high - low)/2;
    int ans = -1;
    while(low <  high){
        if(arr[mid] == key){
            ans = mid;
            high = mid-1;
        }
        else if(arr[mid] > key){
            high = mid-1;
        }
        else if (arr[mid] < key){
            low = mid+1;
        }
        mid = low + (high - low)/2; 

    }

    return ans;

}

//last occurance of the element in a array
int lastOuccrance(int arr[], int size , int key){
    int low = 0;
    int high = size-1;
    int mid = low + (high - low)/2;
    int ans = -1;
    while(low <= high){
        if(arr[mid] == key){
            ans = mid;
            low = mid+1;
        }
        else if(arr[mid] > key){
            high = mid-1;
        }
        else if (arr[mid] < key){
            low = mid+1;
        }
        mid = low + (high - low)/2; 

    }

    return ans;

}

int binarySearch(int arr[],int low,int high,int key){
    int low = low;
    int high = high;

    while (low <= high){
        int mid = low + (low+high)/2;
        if(key == arr[mid]){
            return mid;
        }
        else if(arr[mid] > key){
            high = mid-1;
        }
        else{
            low = mid + 1;
        }
        
    }
    


}
int main(){
    int arr[10] = {10,20,30,40,50,60,70,80,90,100};
    int size, key;
    cout<<"Enter the size of the array "<<endl;
    cin>>size;
    cout<<"Enter the key you want  to search in the array"<<endl;
    int result = binarySearch(arr,0,size-1,key);
    if(result == -1){
        cout<<"the key does'nt exist in the array"<<endl;
    }
    else{
        cout<<result<<" is the index of that key!!"<<endl;

    }
    

}