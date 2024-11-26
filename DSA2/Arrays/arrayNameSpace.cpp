#include <arrayHeader.h>
#include <iostream>
using namespace std;
# define ARRHEADER_H

namespace array
{
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
}
