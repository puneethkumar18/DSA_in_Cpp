#include<iostream>
using namespace std;

int minCostOfRopes(vector<int> arr,int n){
    if(n <= 1){
        return 0;
    }
    int index = arr.size()/2 - 1;
    int ans = arr[index]+arr[index+1];
    arr[index] = ans;
    for(int i=index+1;i < arr.size();i++){
        arr[i] = arr[i+1];
    }
    int res = minCostOfRopes(arr,n-1);

    return ans+res;
}
int main(){
    vector<int> heap = {4,3,2,6};
    cout<<"The Result of the problem is -> "<<minCostOfRopes(heap,4)<<endl;
    return 0;
}