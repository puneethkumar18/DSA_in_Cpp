#include<iostream>
using namespace std;

//polindrome checking while reversing
int checkPolindrome(string s){
    int i = 0, e = s.size();
   while(i<e){
     if(s[i] == s[e]){
        i++;
        e--;
    }
    else{
        return -1;
    }
   }
   return 1;
}

int main(){
    string s;
    cout<<"Enter the string"<<endl;
    cin>>s;
    int result = checkPolindrome(s);
    if(result == 1){
        cout<<s<<"  is polindrome"<<endl;

    } 
    else{
        cout<<s<<" is not polindrome"<<endl;
    }
    
    
}