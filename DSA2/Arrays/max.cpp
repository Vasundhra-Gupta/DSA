#include <iostream>
using namespace std;
int main()
{
    int n;
    cout << "Enter size of the Array" << endl;
    cin >> n;
    int arr[n];
    cout << "Enter Elements of the array" << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    // Print maximum element
    int max = 1;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] > max)
        {
            max = arr[i];
        }
    }
    cout << "The maximum element is " << max << endl;
    cout<< "Time Complexity = O(n) Space Complexity = O(n)"<<endl;

    return 0;
}