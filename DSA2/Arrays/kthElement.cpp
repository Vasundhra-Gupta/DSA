#include <iostream>
using namespace std;

// infinity number??
int partition(int arr[], int low, int high)
{
    int i = low;
    int j = high + 1;

    int pivot = arr[low];
    if (low == high)
    {
        return low;
    }
    while (i < j)
    {
        do
        {
            i++;
        } while (arr[i] < pivot && i <= high);

        do
        {
            j--;
        } while (arr[j] > pivot && i >= low);
        if (i < j)
        {
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[j], arr[low]);
    return j;
}

int kthElementPosition(int arr[], int low, int high, int k)
{
    if (low == high)
    {
        return low;
    }
    int j = partition(arr, low, high);

    if (k == j)
    {
        return j;
    }
    else if (k < j)
    {
        kthElementPosition(arr, low, j, k);
    }
    else if (k > j)
    {
        kthElementPosition(arr, j + 1, high - 1, k);
    }
}

int main()
{
    int arr[] = {1, 6, 7, 8, 9, 2, 3, 4, 5, 6};
    int n = sizeof(arr) / sizeof(arr[0]);
    int k;
    cout << "Enter k\n";
    cin >> k;
    if (k > n)
    {
        cout << "k exceeds the size" << endl;
        return 0;
    }
    int pos = kthElementPosition(arr, 0, n - 1, k - 1);
    cout << "kth smallest element is " << arr[pos] << " at k = " << k << pos << " position" << endl;
    cout << "k small elements are: " << endl;
    for (int i = 0; i < k; i++)
    {
        cout << arr[i] << "\t";
    }
    cout << endl;
    cout << "Top k elements" << endl;
    int position = kthElementPosition(arr, 0, n - 1, n - k);
    cout << position << endl;
    for (int i = position; i < n; i++)
    {
        cout << arr[i] << "\t";
    }
    return 0;
}