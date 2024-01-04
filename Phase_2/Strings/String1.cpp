/* 1.maxOccuranceCharcter function
   2. reverseString
      - using reverse array to check the string is polindrome  or not*/


#include<iostream>
using namespace std;

char maxOccuranceCh(string s){
    int arr[26] = {0};
    int number ;
    int index = -1, max = -1;
    char ans;

    for(int i = 0; i < s.length(); i++){
        if(s[i] >= 'a' && s[i] <= 'z'){
            number = s[i] - int('a');
        }
        else{
            number =  s[i] - int('A') ;
        }
        arr[number]++;
    }
    for(int i = 0; i < 26;i++){
        if(max < arr[i]){
            max = arr[i];
            index = i;
        }
    }
    ans = int('a')+index;
    return ans;
}
//function to reverse string
string reverseString(string s){
    string s1 = s;
    int i = 0;
    int e = s.length()-1;

    while(i < e){
        swap(s[i], s[e]);
        e--;
        i++;

    }
    cout<<"Reversed string id :- "<<s<<endl;
    return s;
}

int main(){
    string s;
    cout<<"Enter the String to check maximum number occured character"<<endl;
    cin>>s;
    cout<<"the Enter string is "<<s<<endl<<"the length of string is "<<s.length()<<endl;
    cout<<"Maximum Occured character  "<<maxOccuranceCh(s)<<endl;
    string s1 = reverseString(s);
    
    if (s1 == s){
        cout<<s<<"  is a polindrome"<<endl;

    }
    else{
        cout<<s<< "  is not a polindrome"<<endl;
    }
}