#include <iostream>
using namespace std;
int arr[]= {3,8,10,15,17,20,25,30,32,35,40,50,55,70,80};

int bs(int, int, int);
int main(){
    int high=sizeof(arr)/sizeof(arr[0]);
    int s;
    cout<<"Enter the number to be searched"<<endl;
    cin>>s;
    int res= bs(0,high-1,s);//
    if(res){
        cout<<"Number found in array at index "<<res-1<<endl;
    }else{
        cout<<"Number not found!"<<endl;
    }
}
int bs(int low, int high, int x){
    while(low<=high){
        if(low==high){
            if(arr[low]==x){
                return low;
            }else{
                return 0;
            }
        }else{
            int mid= (low+high)/2;
            if(x==arr[mid]){
                return mid;
            }else if(x>arr[mid]){
                return bs(mid+1, high, x);
            }else{
                return bs(low, mid-1, x);
            }
        }
    }
}