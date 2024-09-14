#include<iostream>
using namespace std;


void printArray(int *arr,int size){
    cout<<"Printing the elements array );"<<endl;
    for(int i = 0;i<size;i++){
        cout<<*(arr+i)<<" ";
    }
    cout<<endl;
}


int main(){
    //creating dynamic array

    //n - creating memory in stack memory (static memory)
    int *value = new int;
    cout<<"Enter the value);"<<endl;
    cin>>*value;
    cout<<"Value is "<<value<<endl;
    delete value;
    int n;
    cout<<"Enter the size of the array"<<endl;
    cin>>n;
    //new is keyword to create memory in heap memory(dynamic memory)
    //here creating pointer to store the address of array created in heap memory
    int *arr = new int[n];
    cout<<"Enter the elements array "<<endl;
    for(int i=0;i<n;i++){
        cin>>arr[i];
        //also cin>>(arr+i);
    }
    printArray(arr,n);

    //clearing the space or memory of dynamic array or heap memory
    delete []arr;

}
