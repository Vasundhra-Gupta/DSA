#include <iostream>
using namespace std;
//25 numbers are entered in an array by the user. WAP to search an rlement entered by the user and tell its occurence.
int Search(int arr[], int num){
    int count= 0;
    for(int i=0; i<25; i++){
        if(arr[i]==num){
            cout<<"At position "<<i+1<<endl;
            count++;
        }
    }
    return count;
}
int main(){
    int arr[25];
    cout<<"Enter array Elements: "<<endl;
    for(int i=0; i<25; i++){
        cin>>arr[i];
    }

    int s;
    cout<<"Enter element to be searched:"<<endl;
    cin>>s;
    
    int count= Search(arr, s);
    cout<<"The number appeared "<<count<<" times"<<endl;
    return 0;
}