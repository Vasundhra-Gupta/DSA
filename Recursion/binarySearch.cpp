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

void insertionSort(int a[], int n){
    for(int i=1; i<n; i++){
        int key= a[i];
        int j=i-1;
        while(a[j]>key && j>=0){
            a[j+1]= a[j];
            j--;
        }
        a[j+1] = key;
    }
}

int binarySearch(int arr[], int low, int high, int search)
{
    int mid = (low+high)/2;
    if(search == arr[mid]){
        return mid;
    }

    if(search < arr[mid]){
        binarySearch(arr, 0, mid-1, search);
    }else{
        binarySearch(arr, mid+1, high-1, search);
    }    
}

int main()
{
    int arr[] = {2, 5, 7, 9, 3, 6, 0, 1, 7};
    int n = sizeof(arr)/sizeof(arr[0]);
    insertionSort(arr, n);
    for(int i=0; i<n; i++){
        cout<<arr[i]<<"\t";
    }
    cout<<endl;
    int search;
    cout<<"Enter the element to be searched:\n";
    cin>>search;
    int pos= binarySearch(arr, 0, n, search);
    cout<<"The element you searched is at position "<< pos+1<<endl;
    return 0;
}