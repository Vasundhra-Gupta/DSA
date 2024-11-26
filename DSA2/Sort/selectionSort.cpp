#include <iostream>
using namespace std;
//select the minimum and swap with the first(continued in loop)
// 3 4 1 2 0
// 3  0min
// 0 4 1 2 3
// 0 4 1min
// 0 1 4 2 3
// 0 1 4 2min
// 0 1 2 4 3
// 0 1 2 3min
// 0 1 2 3 4
//loop ran n-1 times
void inputArray(int arr[], int n){
    cout<<"Enter elements of the array: "<<endl;
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
}
void printArray(int arr[], int n){
    for(int i=0; i<n; i++){
        cout<<arr[i]<<"\t";
    }
}
void selectionSort(int arr[], int n){
    for(int i=0; i<n-1; i++){//n-1 times
        int min=i;// can't store value in min , store index bcz min is not an array element so will not update its value.
        for(int j=i+1; j<n; j++){
            if(arr[j]<arr[min]){
                min= j;
            }
        }
        swap(arr[i], arr[min]);
    }
}
int main(){
    int size= 5;
    int arr[size];
    inputArray(arr, size);
    selectionSort(arr, size);
    printArray(arr, size);
    cout<<"TC = O(n square) in all cases "<<endl;
    return 0;
}