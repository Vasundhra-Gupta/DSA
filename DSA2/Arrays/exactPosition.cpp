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

// int findPosition(int arr[], int n, int ele){
//     int count=0;
//     for(int i=0; i<n; i++){
//         if(arr[i]<ele) count++;
//     }
//     // arr[count]= ele;
//     // for(int i=0, j=n-1; i<n, j>=0; i++, j--){
//     //     if(arr[i]>ele && arr[j]<ele){
//     //         swap(arr[i], arr[j]);
//     //     }
//     // }
//     // return count+1;
// }

void exactPosition(int arr[], int n, int m){
    int pivot= arr[m];
    int i=m;
    int j= n;// size+1;
    do{
        do{
            i++;
        }while(arr[i]<=pivot);
        do{
            j--;
        }while(arr[j]>pivot);
        if(i<j){
            swap(arr[i], arr[j]);
        }
    }while(i<j);
    swap(arr[m], arr[j]);
}

int main(){
    int arr[]= {5, 1, 9, 6, 7, 8, 3};
    int n= sizeof(arr)/sizeof(arr[0]);
    printArray(arr, n);
    exactPosition(arr, n, 0);
    printArray(arr, n);
    exactPosition(arr, n, 0);
    printArray(arr, n);
    return 0;
}