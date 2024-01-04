#include<iostream>
using namespace std;

void permutation(string input,vector<string>& ans,int index ){
    if(index >= input.size()){
        ans.push_back(input);
        return;
    }
    for(int i = index;i < input.size();i++){
        swap(input[index],input[i]);
        permutation(input,ans,index+1);
        swap(input[index],input[i]);
    }
}

int main(){
    string input = "ABC";
    vector<string> ans;
    vector<int> output;
    int index = 0; 

    permutation(input,ans,index);

    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }
    cout<<endl;
}