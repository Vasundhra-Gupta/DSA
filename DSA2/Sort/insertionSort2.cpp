#include <iostream>
using namespace std;

// 9 7 1  8 2 5
//round 1
//round 2
//7 9 1 8 2 5
//round 3
// 7 1 9
// 1 7 9 8 2 5
//round 4
// 1 7 8 9
// 1 7 8 9
//1 7 8 9 2 5
//round 5
//1 7 8 2 9
// 1 7 2 8 9
// 1 2 7 8 9 5
//rond 6
// 1 2 7 8 5 9
// 1 2 7 5 8 9
// 1 2 5 7 8 9

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
void insertionSort(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = i; j >= 1; j--)
        {
            if (arr[j] < arr[j - 1])
            {
                swap(arr[j], arr[j - 1]);
            }
        }
    }
}
//in this case best case O(n)
// void insertionSort(int arr[], int n){
//     int j;
//     for(int i=0 ; i<n; i++){
//         j=i;
//         while(j>0 && arr[j]<arr[j-1]){
//             swap(arr[j], arr[j-1]);
//             j--;
//         }
//     }
// }
int main()
{
    int size = 5;
    int arr[size];
    inputArray(arr, size);
    insertionSort(arr, size);
    printArray(arr, size);
    cout<<"Time complexity for best case O(n) times and for worst O(n^2)"<<endl;
    return 0;
}