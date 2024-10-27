#include <iostream>
using namespace std;
int main()
{
    int n;
    cout << "Enter size of Array : " << endl;
    cin >> n;

    int arr[n];
    cout << "Enter element of the array :" << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    // second largest element
    int max = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] > max)
        {
            max = arr[i];
        }
    }

    int temp = max;

    int secMax = -1;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] > secMax && arr[i] < temp)
        {
            secMax = arr[i];
        }
    }

    if (secMax == -1)
    {
        cout << "The Second largest element in the array doesn't exists." << endl;
    }
    else
    {
        cout << "The Second largest element in the array is " << secMax << endl;
    }
    cout << "Time Complexity = O(n) Space Complexity = O(n)" << endl;

    return 0;
}