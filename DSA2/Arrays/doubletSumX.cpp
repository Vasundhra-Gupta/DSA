#include <iostream>
#include <vector>
using namespace std;
int main()
{
    int x;
    cout << "Enter the value of x :"<<endl;
    cin >> x;
    int arr[] = {1, 6, 7, 8, 2, 5, 9, 4};
    vector<int> res(2);
    int n = sizeof(arr) / sizeof(arr[0]);

    for (int i = 0; i < n; i++)
    {
        bool flag =true;
        for (int j = i+1; j < n; j++)
        {
            if (arr[i] + arr[j] == x)
            {
                res[0]= i;
                res[1]= j;
                flag= false;
                // or simply return here only
                break;
            }
        }
        if(flag==false) break;
    }
    cout<< "Doublet are: "<<res[0]<<","<<res[1]<<endl;
    return 0;
}