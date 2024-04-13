#include<iostream>
#include<queue>

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

//approch 2
int minCostOfRopes2(vector<int> arr){
    priority_queue<int,vector<int>, greater<int>> pq;

    for(int i = 0;i<arr.size();i++){
        pq.push(arr[i]);
    }

    int cost = 0;

    while (pq.size() > 1)
    {
        int a = pq.top();
        pq.pop();
        int b = pq.top();
        pq.pop();
        int sum = a+b;

        cost += sum;

        pq.push(sum);
    }
    
    return cost;
}
int main(){
    vector<int> heap = {4,3,2,6};
    cout<<"The Result of the problem is -> "<<minCostOfRopes(heap,4)<<endl;
    cout << "The Result of the problem is by Using Priority Queue -> " << minCostOfRopes2(heap) << endl;
    return 0;
}