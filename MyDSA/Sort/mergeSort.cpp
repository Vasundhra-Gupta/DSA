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

void mergeSort(int arr[], int low, int mid, int high)
{
    int i = low;
    int j = mid;
    int k = low;
    int b[high];
    while (i < mid && j < high)
    {
        if (arr[i] < arr[j])
        {
            b[k] = arr[i];
            i++;
        }
        else
        {
            b[k] = arr[j];
            j++;
        }
        k++;
    }
    printArray(b, high);
}
int main()
{
    int arr[] = {1, 3, 5, 7, 9, 0, 2, 4, 6, 8};
    printArray(arr, 10);
    mergeSort(arr, 0, 5, 10);
    return 0;
}