#include<iostream>
using namespace std;

//number printing between a range of n
void printnumber(int number){
    cout<<"printing the numbers before "<<number<<endl;
    for (int i = 0;i <= number; i++){
        cout<<i<<" ";

    }
    cout<<endl;

}

//functon ti find odd or even

void oddOrEven(int number){
    if (number & 1){
        cout<< number<<" is odd"<<endl;

    }
    else{
        cout<<number<<" is even"<<endl;
    }
    
}



// Prime number function1-> prime, 0-> notPrime
bool isPrime(int number){
    for(int i = 2; i<number;i++){
        if (number % i == 0){
            return 0;
        }
    }
    return 1;
}

int main(){

    int a;
    cout<< "Enter the number N"<<endl;
    cin>>a;
    int ans = isPrime(a);
    if(ans == 1){
        cout<<"the given number is prime"<<endl;
    }
    else{
        cout<<"the given number is not a prime"<<endl;
    }
    oddOrEven(a);
    printnumber(a);
}