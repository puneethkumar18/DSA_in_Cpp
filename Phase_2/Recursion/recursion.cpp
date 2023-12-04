#include<iostream>
using namespace std;

//recursive function for getpower of the number
inline int getPower(int num,int power){
    if(power == 1){
        return num;
    }
    return num * getPower(num,power-1);
}
//factorisation
int factorisation(int n){
    if(n == 0 ){
        return 1;
    }
    return n * factorisation(n-1);
}

int main(){
    int num , power;
    cout<<"Enter the base );"<<endl;
    cin>>num;
    cout<<"Enter the power );"<<endl;
    cin>>power;

    cout<<"Power of the number  is "<<getPower(num,power)<<endl;
    int n;
    cout<<"Enter the number to get factorial "<<endl;
    cin>>n;
    cout<<"Factorial of the number "<<n<<" is "<<factorisation(n)<<endl;
    
}