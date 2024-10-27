#include <iostream>
#include <math.h>
using namespace std;

void insertionSort(int arr[], int n){
    for(int i=1; i<n; i++){
        int key = arr[i];
        int j= i-1;
        while(j>0 && arr[j]>key){
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = key;
    }
}


int binarySearch(int arr[], int low, int high, int search)
{
    int mid = ceil((low+high)/2);
    bool isFound = false;
    if(search == arr[mid]){
        isFound = true;
        return mid;
    }
    if(low == high){
        isFound = true;
        return low;
    }
    if(search < arr[mid]){
        binarySearch(arr, 0, mid-1, search);
    }else{
        binarySearch(arr, mid+1, high-1, search);
    }

    if(!isFound){
        cout<<"Number not found\n";
        return -1;
    }
    
}

int main()
{
    int arr[] = {2, 5, 7, 9, 3, 6, 0, 1, 7};
    int n = sizeof(arr)/sizeof(arr[0]);
    insertionSort(arr, n);
    int search;
    cout<<"Enter the element to be searched:\n";
    cin>>search;
    int pos= binarySearch(arr, 0, n, search);
    cout<<"The element you searched is at position "<< pos<<endl;
    return 0;
}