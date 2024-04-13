#include<iostream>
using namespace std;

// it is a complete binary tree
// heap implementation with array

class Heap{
    public:
    int arr[100];
    int size;

    Heap(){
        arr[0] = -1;
        size = 0;
    }

    void insert(int data){
        size++;
        int index = size;
        arr[index] = data;

        while (index > 1)
        {
           int parent = index/2;
           if(arr[parent] < arr[index]){
            swap(arr[index],arr[parent]);
            index = parent;
           }else{
            return;
           }
        }
    }

    void deleteNode(int data){
        if(size == 0){
            cout<<"Heap is empty to delete "<<endl;
            return;
        }

        arr[1] = arr[size];
        size--;
        int i = 1;
        while (i < size)
        {
            int leftIndex = 2*i;
            int rightIndex = 2*i+1;

            if(leftIndex < size && arr[i] < arr[leftIndex] ){
                swap(arr[i],arr[leftIndex]);
                i = leftIndex;
            }
            else if (rightIndex < size && arr[i] < arr[rightIndex])
            {
                swap(arr[rightIndex], arr[i]);
                i = rightIndex;
            }
            else{
                return;
            }
            
        }
    }

    void printHeap()
    {
        for (int i = 1; i <= size; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

void heapify(int arr[], int n, int i)
{
    int largest = i;
    int left = 2 * i;
    int right = 2 * i + 1;

    if (left <= n && arr[largest] < arr[left])
    {
        largest = left;
    }

    if (right <= n && arr[largest] < arr[right])
        largest = right;

    if (largest != i)
    {
        swap(arr[largest], arr[i]);
        heapify(arr, n, largest);
    }
}

void heapSort(int arr[],int n){
    int size = n;
    while (size > 1)
    {
        swap(arr[size],arr[1]);
        size--;

        heapify(arr,size,1);
    } 
}

int main(){

    Heap* h = new Heap();
    h->insert(50);
    h->insert(53);
    h->insert(55);
    h->insert(52);
    h->insert(54);

    h->printHeap();

    h->deleteNode(55);
    h->printHeap();

    int arr[6] = {-1,54,53,55,52,50};
    int n=5;
    
    for(int i=n/2;i>0;i--){
        heapify(arr,n,i);
    }

    cout<<"Printing the Array new "<<endl;

    for(int i=1;i <= n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;

    heapSort(arr,n);
    cout << "Printing the HeapSort " << endl;

    for (int i = 1; i <= n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;


    cout<<
    return 0;
}