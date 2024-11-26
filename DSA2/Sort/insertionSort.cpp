#include <iostream>
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
int main(){
    int arr[]= {1,5,2,9,7};
    int n= sizeof(arr)/sizeof(arr[0]);
    printArray(arr, n);
    insertionSort(arr, n);
    printArray(arr, n);
    return 0;
}