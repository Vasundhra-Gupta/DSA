//rearrange the elements of the array to for a max heap(heapify)
//swap max element at the top with last element and decrease heap size.(max element in array)
//heapify again
//swap max with last and repeat 
//if we have max heap already and we disturb single node then we cam heapify it completing by calling it with singke node.
//if it's not max heap, then who guarantees its child will be greater than parent and heapify will not be called.
// Max heap 
#include <iostream>
#include <math.h>
using namespace std;

void printArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << "\t";
    }
    cout<<endl;
}

void heapify(int arr[],int n, int i){
    int large= i;
    int left= 2*i+1;
    int right= 2*i+2;
    if(left<n && arr[left]>arr[large]){
        large=left;
    }
    if(right<n && arr[right]>arr[large]){
        large = right;
    } 
    if(large!= i){
        swap(arr[large], arr[i]);
        //furthur sorting
        heapify(arr, n, large);
    }
}

void heapSort(int arr[], int n){
    //form max heap
    for(int i= floor(n/2)-1; i>=0; i--){
        heapify(arr, n, i);
    }
    cout<<"heapified"<<endl;
    printArray(arr, n);
    int size= n; //array size
    for(int i= 0 ; i<size; i++){
        swap(arr[0], arr[n-1]);//arr[n-1] and not arr[size-1]
        n--;
        heapify(arr, n, 0);
    }
}

int main(){
    int arr[]= {5,4,3,2,8};
    int n= sizeof(arr)/sizeof(arr[0]);
    printArray(arr,n);
    //traversing each node...
    // for(int i= floor(n/2)-1; i>=0; i--){
    //     heapify(arr, n, i);
    // }
    // heapify(arr, n, 0);
    // cout<<"Tree"<<endl;
    // printArray(arr,n);

    heapSort(arr, n);
    cout<<"Sorted List"<<endl;
    printArray(arr,n);

    return 0;
}
