#include<iostream>
#include<math.h>
using namespace std;

// checking whether the given number is 2powi
void is2poweri(int a){
    int bitcount = 0;
    while(a != 0){
        if (a&1){
           bitcount++;

    }
    a<<1;
    }
    if(bitcount == 1){
        cout<<"Yes the number given is power of 2"<<endl;

    }
    else{
        cout<<"NO the number given is not power of 2"<<endl;
    }


}

//function to convert binary to decimal
void biToDeci(int a){
    int ans = 0, i = 0;

    while (a != 0 )  
    {
        if(a & 1){
            ans = ans + pow(2,i);
        }
        i++;

        a<<1;
    }

    cout<<ans<<endl;
    

}

//function to check with logical opration
int logical(int a, int b,char ch){

    int shift_no;

    switch(ch){
        case '&':cout<<"a&b = "<<(a & b)<<endl;
                 break;
                
        case '|':cout<<"a|b = "<<(a | b)<<endl;
                break;
        
        case '<':
                cout<<"enter the no of times tobe shift"<<endl;
                cin>>shift_no;
                cout<< "left shift ="<<(a<<shift_no)<<endl;
                break;

        case '>':
                cout<<"enter the no of times tobe shift"<<endl;
                cin>>shift_no;
                cout<<"right shift ="<< (a>>shift_no)<<endl;
                break;
        
        default : cout<< "sorry we don't have that opration"<<endl;

    }
    
    
}

int main(){
    int a ;  
    cout<<"enter the first number a"<<endl;
    cin >> a;
    int b ;
    cout<<"enter the second number b"<< endl;
    cin >> b; 

    char ch;
    cout<<"Enter the logical oprator "<<endl;
    cin>> ch;
    //logical(a,b,ch);
    biToDeci(a);


    
}