#include <iostream>
#include <math.h>
using namespace std;
void reversePart(int arr[], int start, int end)
{
    while (start < end)
    {
        swap(arr[start], arr[end]);
        start++;
        end--;
    }
}
int *rotate(int arr[],int n, int k)
{
    if (k > n)
        k = k % n;
    reversePart(arr, 0, n - k - 1);
    reversePart(arr, n - k, n - 1);
    reversePart(arr, 0, n - 1);
    return arr;
}

int main()
{
    // reverse part of array
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 0};
    int n = sizeof(arr) / sizeof(arr[0]);
    // for rotating the array
    //  -- reverse array before kth index
    //  -- reverse array after kth index
    //  -- reverse the whole array
    rotate(arr, n, 5);
    for (int i = 0; i < n; i++)
    {
        cout<<arr[i]<<endl;
    }
    
    return 0;   
}