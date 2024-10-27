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

//we pass high as size-1 genrally!!
int partition(int arr[], int low,  int high){
    int pivot = arr[low];
    int i = low;//no need to take low-1, bcz we dont need to compare first element.
    int j = high +1;// high= n-1
    do{
        do{
            i++;
        }while(arr[i]<=pivot && i<=high+1);
        do{
            j--;
        }while(arr[j]>pivot && j>= low);
        if(i<j){
            swap(arr[i], arr[j]);
        }
    }while(i<j);
    swap(arr[low], arr[j]);
    return j;
}

void quickSort(int arr[], int low, int high){
    if(low<high+1){
        int p= partition(arr, low, high);
        quickSort(arr, low, p-1);
        quickSort(arr, p+1, high);
    }
}
int main(){
    int arr[]= {5, 1, 3, 7, 9, 8, 5, 2};
    int n= sizeof(arr)/sizeof(arr[0]);
    printArray(arr, n);
    partition(arr, 0, n-1);
    printArray(arr, n);
    quickSort(arr, 0, n-1);
    printArray(arr, n);
    return 0;
}