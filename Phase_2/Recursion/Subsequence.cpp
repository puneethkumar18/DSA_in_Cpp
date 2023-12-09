#include<iostream>
using namespace std;

void subsequence(string s,int index, vector<string>& ans,string output){
    //base case
    if(index >= s.length()){
        ans.push_back(output);
        return;
    }
    subsequence(s,index+1,ans,output);

    char element = s[index];
    output.push_back(element);
    subsequence(s,index+1,ans,output);
}

int main (){
    string  s = "abc";
    vector<string> ans;
    int index = 0;
    string output = "";
    subsequence(s,index,ans,output);
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<",";
    }
    cout<<endl;
}