#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
    int n;
    int m;
    cout << "Enter size of array : " << endl;
    cin >> n;
    vector<int> arr1(n); // 0 as default element
    
    // we can also give default values to the elements of the array
    vector<int> arr2(n, 8); 
    for (int i = 0; i < n; i++)
    {
        cout << arr2[i]<<endl;//each element 8
    }

    // vector doubles it capacity and increases the size to how many elements are added
    cout<<arr2.size();//4
    cout<<arr2.capacity();//4
    arr2.push_back(3);
    cout<<arr2.size();//5
    cout<<arr2.capacity();//8

    //sort
    cout<<"Enter elements of vector array to be sorted : "<<endl;
    for (int i = 0; i < n; i++)
    {
        cin>>arr1[i];
    }
    sort(arr1.begin(), arr1.end());
    // reverse(arr1.begin(), arr1.end());

    for (int i = 0; i < n; i++)
    {
        cout<<arr1[i];
    }
    return 0;
}