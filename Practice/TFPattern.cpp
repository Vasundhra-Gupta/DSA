#include <iostream>
using namespace std;
int pattern(int , int);
char arr[10];
int main(){
    int n;
    cout<<"Enter number of positions"<<endl;
    cin>>n;
    pattern(1,n);//TF FT TT TF
    return 0;
}
//k is for index, 123, 123, 123 for n=3
int pattern(int k, int n){
    if(k>n){
        for(int i=1; i<=n; i++){
            cout<<arr[i]<<" ";
        }
        cout<<endl;
    }else{
        arr[k]='T';
        pattern(k+1,n);
        arr[k]='F';
        pattern(k+1,n);
    }
}