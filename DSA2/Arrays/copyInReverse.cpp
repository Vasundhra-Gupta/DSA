#include <iostream>
#include <math.h>
using namespace std;
int main(){
    int n;
    cout<<"Enter n:"<<endl;
    cin>>n;
    int a[n];
    cout<<"Enter elements:"<<endl;
    for(int i=0; i<n; i++){
        cin>>a[i];
    }
    int b[n];
    for(int i=0; i<=n; i++){
       b[i]=a[n-i-1];
    }
    for(int i=0; i<n; i++){
        cout<<b[i]<<endl;
    }

    //without using external array;
    cout<<"Without using external array"<<endl;
    int arr[n];
    cout<<"Enter elements:"<<endl;
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    int mid= floor(n/2);
    for(int i=0; i<=mid; i++){
        int temp= arr[i];
        arr[i]= arr[n-i-1];
        arr[n-i-1] = temp;
    }
    for(int i=0; i<n; i++){
        cout<<arr[i]<<endl;
    }

    // or use swap using two indices which is an inbuilt function!
    return 0;
}