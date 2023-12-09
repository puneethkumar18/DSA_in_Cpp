/*
input = "23" on phone key pad 2 has character of 'abc' and 3 has 'def'
so the  
output : {ad,ae,af,bd,be,bf,cd,ce,cf}
*/
#include<iostream>
using namespace std;

void combinations(string input,int index,vector<string>& ans,string output,string mapping[]){
    if(index >= input.size() ){
        ans.push_back(output);
        return;
    }
    int number = input[index] - '0';
    string alphabets = mapping[number];
    for(int i = 0; i < alphabets.size();i++){
        output.push_back(alphabets[i]);
        combinations(input,index+1,ans,output,mapping);
        output.pop_back();
    }
}

int main (){
    string input = "23";
    string mapping[10] = {" "," ","abc","def","ghi","jkl","mno","pqr","stu","vwxyz"};
    vector<string> ans;
    string output = "";
    int index = 0;
    combinations(input,index,ans,output,mapping);
    cout<<"[";
    for(int i=0;i<ans.size();i++){
        cout<<ans.at(i)<<",";
    }
    cout<<"]"<<endl;
}