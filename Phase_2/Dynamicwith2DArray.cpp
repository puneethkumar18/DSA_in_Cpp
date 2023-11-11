#include<iostream>
using namespace std;

int main(){
    int row,col;
    cout<<"Enter the row size of the array );"<<endl;
    cin>>row;
    cout<<"Enter the col size of the array );"<<endl;
    cin>>col;
    //delcaring 2D dynamic array
    //craeting double pointer 
    //first one pointing to array of holding address of all array
    int **arr = new int* [row];

    for(int i=0;i<row;i++){
        *(arr+i) = new int [col];

    }
    //entering elements to 2D array
    cout<<"Enter the elements of the array); "<<endl;
    for(int i=0;i<row;i++){
        for(int j = 0;j<col;j++ ){
            cin>>arr[i][j];
        }
    }

    //printing 2D array
    cout<<"printing 2D array"<<endl;
    for(int i=0;i<row;i++){
        for(int j = 0;j<col;j++ ){
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }

    //clearing memory of 2D array in heap memory
    for(int i = 0;i < row;i++){
        delete []arr[i];
    }
    delete []arr;
    
}