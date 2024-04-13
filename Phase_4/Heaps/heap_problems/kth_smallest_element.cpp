#include<iostream>
#include<queue>
using namespace std;


int kthSmallest(int arr[],int n,int k){
    priority_queue<int> pq;

    // step-1 create heap of the first k elements
    for(int i=0;i<k;i++){
        pq.push(arr[i]);
    }

    // step-2
    for(int i=k;i<n;i++){
        if(arr[i] < pq.top()){
            pq.pop();
            pq.push(arr[i]);
        }
    }
    return pq.top();
}
int main(){
    int arr[6] = {12,34,78,9,7,5};
    int ans = kthSmallest(arr,6,5);

    cout<<"Kth Smallest element is -> "<<ans<<endl;

    return 0;
}