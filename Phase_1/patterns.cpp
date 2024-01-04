#include<iostream>
using namespace std;

int main (){
    int n ;
    cout << "enter the n"<<endl;
    cin>>n;
    int i = 1;
    while(i<=n){
        //first triangle 
        int space = n-i+1;
        while (space)
        {
            cout<<"  ";
            space--;
        }

        //second triangle
        int j = 1;
        while (j <= i)
        {
            cout<<j<<" ";
            j++;

        }
        //3rd triangle 
        int  k = i;
        while(k > 1)  {
            k--;
            cout<<k<<" ";
            
        }
        cout<<endl;
        i++;

    }
}
    

