#include<iostream>
#include<algorithm>
#include<queue>
using namespace std;


// first approch
int kthLargesetSumSubArray(vector<int> arr, int k){
    vector<int> sum_store;

    for(int i=0; i<arr.size(); i++){
        int sum = 0;
        for(int j=i;j<arr.size();j++){
            sum += arr[j];
            sum_store.push_back(sum);
        }
    }
    sort(sum_store.begin(),sum_store.end());

    return sum_store[sum_store.size() - k];
}

// Second Approch
int kthLargesetSumSubArray2(vector<int> arr , int k){
    priority_queue<int,vector<int> , greater<int> > mini;

    int n = arr.size();
    for(int i=0;i<n;i++){
        int sum = 0;
        for(int j= i;j<n;j++){
            sum += arr[j];
            if(mini.size() < k){
                mini.push(sum);
            }else{
                if(mini.top() < sum){
                    mini.pop();
                    mini.push(sum);
                }
            }
        }
    }
    return mini.top();
}

int main()
{
    vector<int> heap = { 1, 2, 3};
    cout<<"Kth largest Sum of Subarray is -> "<<kthLargesetSumSubArray(heap,3)<<endl;
    cout << "Kth largest Sum of Subarray Using min Heap is -> " << kthLargesetSumSubArray2(heap, 3) << endl;
    return 0;
}