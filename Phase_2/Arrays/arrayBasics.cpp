#include<iostream>
using namespace std;

//this functon shows that array passed by the main function is BASE ADDRESS(first index adress) of array
//function doesn't make copy array
void update(int arr[],int size){
    cout<<"update function is running"<<endl;

    // this update is also done in main function
    arr[0] = 120;
    for(int i = 0;i <size; i++){
        cout<<arr[i]<<" ";

    }
    cout<<endl;

    cout<<"update function is ended"<<endl;
}

//function to find max number
int maxArray(int arr[],int size){
    int maxi = INT16_MIN;
    for (int i = 0;i < size;i++){
        maxi = max(arr[i],maxi);
    }
    cout<<"the largest number in the array is "<<maxi<<endl;
    return maxi;
}

//function to find min number
int minArray(int arr[],int size){
    int mini = INT16_MAX;
    for (int i = 0;i < size;i++){
        mini = min(arr[i],mini);
    }
    cout<<"the largest number in the array is "<<mini<<endl;
    return mini;
}
// prints the sum of all the elemnts of the array
int sumOfArray(int arr[],int size){
    int sum = 0;
    for(int i = 0;i < size;i++){
        sum = sum + arr[i]; 
    }
    cout<<"Sum of all the elements of array is "<<sum<<endl;
}

int main(){
    int a[10] = {10,19,99,78,43};
    int size;
    cout<<"Enter the size of array to access"<<endl;
    cin >> size;
    //maxArray(arr,size);
    //minArray(arr,size);
    update(a, size);
    //sumOfArray(arr,size);
        for(int i = 0;i <size; i++){
        cout<<a[i]<<" ";

    }
    


}