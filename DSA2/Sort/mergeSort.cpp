#include <iostream>
using namespace std;

void printArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << "\t";
    }
    cout << endl;
}

void mergeSort(int arr[], int low, int mid, int high)
{
    int i = low;
    int j = mid;
    int k = low;
    int b[high+1];
    while (i < mid && j <= high)
    {
        if (arr[i] < arr[j])
        {
            b[k] = arr[i++];
        }
        else
        {
            b[k] = arr[j++];
        }
        k++;
    }

    while (i <= mid)
    {
        b[k++] = arr[i++];
    }

    while (j <= high)
    {
        b[k++] = arr[j++];
    }

    printArray(b, high);
}
int main()
{
    int arr[] = {1, 3, 5, 7, 9, 0, 2, 4, 6, 8};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout<<"Array:"<<endl;
    printArray(arr, n);
    cout<<"After merge sort"<<endl;
    mergeSort(arr, 0, n/2 , n);
    return 0;
}