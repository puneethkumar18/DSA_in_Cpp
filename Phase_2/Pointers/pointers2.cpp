#include<iostream>
using namespace std;

void printElement(int *arr, int size){
    for(int i = 0;i < size ;i++){
        *(arr+i) = *(arr+i) +1;
        cout<<i+1<<" index element "<<*(arr+i)<<endl;
    }

     
}

void update(int *n){
   
    *n = *n + 1; 
    n = n+1;
    cout<<"Inside function address updated is "<<n<<endl;
}

//array can be access arr[i] and also i[arr] i is index

int main(){
    /*
    //pointers with array
    int arr[10] = {1,2,3,4,5,6,7,8,9};
    int *p = arr;
    cout<<"address "<<p<<endl;
    cout<<"value "<<*p<<endl;
    cout<<"address by address oprator "<<&p<<endl;
    cout<<"2nd "<<*(p+1)<<endl;
    cout<<"3rd "<<(p+1)<<endl;
    cout<<"4th "<<(*p+1)<<endl;

    //all the values of array is printed 
    for(int i = 0;i < 10; i++ ){
        cout<<"address of "<<i+1<<" element is "<<p+i<<endl;
        cout<<"value of "<<i+1<<" element is "<<*(p+i)<<endl;
        cout<<i[arr]<<endl;
    }
    */
   // charcter array with pointer
   char arr[6] = "abced";
   char *c = &arr[0];

   cout<< "address "<<c<<endl;
   /*it gives prints the element until it reach NULL character instead of printing address of the 
   first index */
   //cout<< functiion is diffrent from int array to character array
   // as pass the first element address it prints entire  array
   cout<<arr<<endl;

    //function with array 

    int value = 5;
    int *ptr = &value;
    //here we passing address of instead of value it change or update data stored in that address
    cout<<"Before "<<*ptr<<endl;
    cout<<"Before address "<<ptr<<endl;
    update(ptr);
    cout<<"After "<<*ptr<<endl;
    cout<<"After address "<<ptr<<endl;

    int arr1[5] = {1,2,3,4,5};
    int *p = arr1;
    
    printElement(p,5);
    



    
}

