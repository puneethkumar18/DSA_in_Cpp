#include<iostream>
#include<math.h>
using namespace std;

//checkpolindrome
bool checkPolindrome(string& s, int i){
    if(i > (s.length()-1-i)){
        return true;
    }
    if(s[i] != s[s.length()-1-i]){
        return false;
    }else{
        i++;
        return checkPolindrome(s,i);
    }
}


//reverse the string using recursion
void reverseString(string& s,int i ,int j){
    if(i>j){
        return;
    }
    swap( s[i], s[j]);
    i++;
    j--;
    reverseString( s, i, j);
}


int main(){
    string s = "abcba"; 
    reverseString(s,0,s.length()-1);
    cout<<"The reversed arrays is ";
    cout<<s<<endl;

    bool isPolindrome = checkPolindrome(s,0);
    if(isPolindrome){
        cout<<"Yes it is polindrome"<<endl;
    }else{
        cout<<"No it is not polindrome"<<endl;
    }
}
