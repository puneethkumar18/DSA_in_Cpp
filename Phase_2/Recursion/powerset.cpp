#include<iostream>
using namespace std;


void subset(vector<int> nums,vector<int> output,int index,vector<vector<int> >& ans){
    if(index >= nums.size()){
        ans.push_back(output);
        return;
    }
    //exclude function call
    subset(nums,output,index+1,ans);

    //Include function call
    int element =  nums[index];
    output.push_back(element);
    subset(nums,output,index+1,ans);

}

int main (){

    vector<vector<int> > ans;
    vector<int> output;
    int index = 0;
    vector<int> nums;
    nums.push_back(1);
    nums.push_back(2);
    nums.push_back(3);

    subset(nums,output,index,ans);
   for(int i=0;i<ans.size();i++){
    vector<int> a = ans.at(i);
    cout<<"[";
    for(int j =0; j < a.size();j++){
        cout<<a.at(j)<<",";
    }
    cout<<"]"<<endl;
   }
}