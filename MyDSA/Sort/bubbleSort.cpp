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

void bubbleSort(int arr[], int n){
    for(int i=0; i<n; i++){
        for(int j=n-1; j>=i+1; j--){
            if(arr[j-1]>arr[j]){
                swap(arr[j-1], arr[j]);
            }
        }
    }
}
int main(){
    int arr[]= {1,5,2,9,7};
    int n= sizeof(arr)/sizeof(arr[0]);
    printArray(arr, n);
    bubbleSort(arr, n);
    printArray(arr, n);
    return 0;
}

