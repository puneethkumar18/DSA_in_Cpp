#include<iostream>
using namespace std;

void printHeap(vector<int> arr)
{
    for (int i = 1; i <= arr.size(); i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

vector<int> mergeToHeap(vector<int> heap1, vector<int> heap2)
{
    vector<int> ans;

    ans.push_back(-1);
    for(auto i:heap1){
       ans.push_back(i);
    }
    for(auto i:heap2){
        ans.push_back(i);
    }
    printHeap(ans);
    return ans;
} 

void heapify(vector<int> &arr,int i,int n){
    int largest = i;
    int left = 2*i;
    int right = 2*i+1;

    if(left <= n && arr[largest] < arr[left]){
        largest = left;
    }
    if(right <= n && arr[largest] < arr[right]){
        largest = right;
    }

    if(largest != i){
        swap(arr[i], arr[largest]);
        heapify(arr,largest,n);
    }

}

vector<int> merge2MaxHeap(vector<int> heap1,vector<int> heap2){
    vector<int> merged = mergeToHeap(heap1,heap2);
    int size = merged.size();
    for(int i = size/2; i > 0;i--){
        heapify(merged,i,size);
    }
    
    return merged;
}

int main(){
    vector<int> heap1 = {10, 5, 6, 2};
    vector<int> heap2 = {12, 7, 9};

    vector<int> merged = merge2MaxHeap(heap1,heap2);

    printHeap(merged);

    return 0;
}