#include<iostream>
#include<math.h>
using namespace std;

//find the squareroot of the given number using binary serach
int squreRootInteger(int number)
{
    int low = 0;
    int high = number-1;
    int mid = low + (high-low)/2;
    int ans;
    while(low <= high){
        if((pow(mid,2)) == number){
            return mid;
        }
        else if ((pow(mid,2)) > number){
            low = mid+1;
        }
        else{
            ans = mid;
            high = mid -1;
        }
        mid = low + (high - low)/2;
    }
    return -1;
}

double morePrecision(int number , int precision,int somevalue ){
    int factor = 1;
    double ans = somevalue; 

    for( int i = 0; i<precision ; i++){
        factor = factor/10;
        for(double   j = ans; j*j < number; j = j+factor ){
            ans = j; 
        }
    }
    return ans;
}

int main (){
    int number;
    cout<<"Enter the number to get square root"<<endl;
    cin >> number;
    int nearValue = squreRootInteger(number);
    cout<<"the given nummber is squreroot of "<<morePrecision(number,3,nearValue)<<endl;
    
}