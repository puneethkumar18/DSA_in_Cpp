#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

int main(){
    vector<int> question;
    question.push_back(12);
    question.push_back(34);
    question.push_back(665);
    question.push_back(34);
    question.push_back(56);
    question.push_back(78);
    question.push_back(76);
    question.push_back(665);
    question.push_back(67);
    question.push_back(9);
    question.push_back(9);
    question.push_back(27);
    question.push_back(43);
    question.push_back(665);
    

    unordered_map<int,int> count;

    int maxFreq = INT_MIN;
    int ans = -1;
    for(int i=0; i<question.size(); i++){
        count[question[i]]++;
        if(count[question[i]] > maxFreq){
            maxFreq = count[question[i]];
        }
    }

    for(int i=0; i<12; i++){
        if(maxFreq == count[question[i]]){
            ans = question[i];
        }
    }
    
    cout<<ans<<endl;
    return 0;
}