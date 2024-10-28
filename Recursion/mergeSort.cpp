#include <iostream>
#include <math.h>
using namespace std;

int merge(int arr[], int low, int mid, int high)
{
    int i = low;
    int j = mid+1;
    int k = 0;

    int* temp = new int[high - low + 1];

    while (i <= mid && j <= high)
    {
        if (arr[i] < arr[j])
        {
            temp[k] = arr[i];
            i++;
        }
        else
        {
            temp[k] = arr[j];
            j++;
        }
        k++;
    }

    while (j <= high)
    {
        temp[k] = arr[j++];
        k++;
    }
    while (i <= mid)
    {
        temp[k++] = arr[i++];
    }

    for (int i = low; i <= high; i++)
    {
        arr[i] = temp[i-low];
    }
}

int mergeSort(int arr[], int low, int high)
{
    // if (low == high)
    // {
    //     return arr[low];
    // }
    if (low < high)
    {
        int mid = (high + low) / 2;
        mergeSort(arr, low, mid);
        mergeSort(arr, mid + 1, high);
        merge(arr, low, mid, high);
    }
}

int main()
{
    int arr[] = {2, 3, 9, 7, 8, 4, 6};
    int n = sizeof(arr)/sizeof(arr[0]);

    for(int i=0; i<n; i++){
        cout<<arr[i]<<"\t";
    }

    cout<<endl;
    mergeSort(arr, 0, n-1);

    for(int i=0; i<n; i++){
        cout<<arr[i]<<"\t";
    }

    cout<<endl;
    return 0;
}