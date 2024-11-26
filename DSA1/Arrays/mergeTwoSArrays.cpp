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

void mergeSort(int arr1[], int arr2[], int low1, int high1, int low2, int high2)
{
    int k=0;
    int b[high1+high2+2];
    while (low1 <= high1 && low2 <= high2)
    {
        if (arr1[low1] < arr2[low2])
        {
            b[k] = arr1[low1++];
        }
        else
        {
            b[k] = arr2[low2++];
        }
        k++;
    }

    while (low1 <= high1)
    {
        b[k++] = arr1[low1++];
    }

    while (low2 <= high2)
    {
        b[k++] = arr2[low2++];
    }

    printArray(b, high1+high2+2);
}
int main()
{
    int arr1[] = {1, 3, 5, 7, 9};
    int arr2[] = {0, 2, 4, 6, 8};
    int n1 = sizeof(arr1)/sizeof(arr1[0]);
    int n2 = sizeof(arr2)/sizeof(arr2[0]);
    cout<<"Array 1:"<<endl;
    printArray(arr1, n1);
    cout<<"Array 2:"<<endl;
    printArray(arr2, n2);
    cout<<"After merge sort"<<endl;
    mergeSort(arr1, arr2, 0 , n1-1, 0 , n2-2);
    return 0;
}