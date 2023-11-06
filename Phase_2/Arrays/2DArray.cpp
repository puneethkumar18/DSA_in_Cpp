#include<iostream>
using namespace std;


// print in wave form
void wavePrint(int arr[][4],int row, int col){
    for(int i = 0;i < col;i++){
        if(i&1){
            for(int j = row-1; j >= 0 ;j-- ){
                cout<<arr[j][i]<<" ";
            }
            cout<<endl;
        }
        else{
            for(int j = 0; j < row; j++){
                cout<<arr[j][i]<<" ";
            }
            cout<<endl;
        }
    }
}
// function to print column wise sum
void colSum(int arr[][4],int row,int col){
    int total_sum = 0;
    for(int  i = 0;i < col;i++){
        int sum = 0;
        cout<<"Sum of "<<i+1 <<" column elements is "<<endl;
        for(int j = 0;j < row;j++){
            sum = arr[j][i] + sum;
        }
        cout<<sum<<endl;
        if( total_sum < sum){
            total_sum = sum;
        }
        
    }
    cout<<"the largest row sum number in matrix is  "<<total_sum<<endl;

}

// function prints row sum and larget sum of row
void rowSum(int arr[][4], int row,int col){
    int total_sum = 0;
    for(int  i = 0;i < row;i++){
        int sum = 0;
        cout<<"Sum of "<<i+1 <<" row elements is "<<endl;
        for(int j = 0;j < col;j++){
            sum = arr[i][j] + sum;
        }
        cout<<sum<<endl;
        if( total_sum < sum){
            total_sum = sum;
        }
        
    }
    cout<<"the largest row sum number in matrix is  "<<total_sum<<endl;
}


//dunction to check whether the key is presentbor not
bool isPresent(int arr[][4],int row, int col, int key){
    for(int i = 0;i < row;i++){
        for(int j = 0; j < col; j++){
            if (arr[i][j] == key){
                return 1;
            }
        }
    }
    return 0;
}

// printing rotated 2d array
void rotatedArray(int arr[][4],int col, int row){
    cout<<"Printing the rotated image of 2D array"<<endl;
    for(int i = 0;i < col;i ++ ){
        for(int j = row-1 ; j >= 0 ; j--){
            cout<<arr[j][i]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
}

// function taking input to array
void takeElement(int arr[][4]){
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 4;j++){
            cin>>arr[i][j];
        }
    }
    cout<<endl;
}

//print array
void printArray(int arr[][4]){
    cout<<"Printing the array"<<endl;
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 4;j++){
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;

}

int main(){
    int arr[3][4] = {1,2,3,4,5,6,7,8,9,10,11,12};
    /*int target;
    cout<<" Enter the target to check in the matrix"<<endl;
    cin>>target;
    bool result = isPresent(arr,3,4,target);
    if(result){
        cout<<"Yes! it is present"<<endl;
    }
    else{
        cout<<"No! it is not present"<<endl;
    }
    rowSum(arr,3,4);
    colSum(arr,3,4);
    //takeElement(arr);
    //rotatedArray(arr,4,3);
    //printArray(arr);*/
    printArray(arr);
    cout<<endl;
    wavePrint(arr,3,4);



}