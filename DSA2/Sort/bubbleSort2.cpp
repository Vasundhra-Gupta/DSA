#include <iostream>
using namespace std;
// select the maximum , put to the last by ADJACENT SWAPPING
// 1st round, swap adjacent
// 9 2 4 1 6
// round 1
// 2 9 4 1 6
// 2 4 9 1 6
// 2 4 1 9 6
// 2 4 1 6 9 
// round 2
// 2 4 1 6 9 
// 2 1 4 6 9
// 2 1 4 6 9
// 2 1 4 6 9
// round 3
// 1 2 4 6 9

void inputArray(int arr[], int n)
{
    cout << "Enter elements of the array: " << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
}
void printArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << "\t";
    }
}
void bubbleSort(int arr[], int n)
{
    bool didSwap = false;
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        { // 0 - n-1 || 0- n-2...
            if (arr[j] > arr[j + 1])
            {
                swap(arr[j], arr[j + 1]);
                didSwap = true;
            }
        }
        if (didSwap == false)
        {
            cout << "TC (best)= O(n)" << endl;
             break;
        }
    }
}
int main()
{
    int n;
    cout << "Enter size of array:" << endl;
    cin >> n;
    int arr[n];
    inputArray(arr, n);
    bubbleSort(arr, n);
    printArray(arr, n);
    cout << "TC = O(n square) for worst and avg case" << endl;
    // but wt about the best case, if array is already sorted then it will run just 1st n times and not ahead so in that case complexity will be O(n) times.
    return 0;
}