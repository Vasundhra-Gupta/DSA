#include <iostream>
using namespace std;
// int a0,a1,a2,a3,a4,a5;
// int a[]={a0,a1,a2,a3,a4,a5};
//Horner's rule
//a0+x(a1+ x(a2+x(a3+x(a4+ xa5))))
int main(){
    cout<<"Enter the values of constants!"<<endl;
    int a[6];
    for(int i=0; i<6; i++){
        cin>>a[i];
    }
    //iterative
    int res=a[5];
    int x;
    cout<<"Enter the value of x:"<<endl;
    cin>>x;
    for(int i=5; i>0; i--){
        res= res*x + a[i-1];
    }
    cout<<res;
    return 0;
}
// int horner(int n, int x){
//     if(n==0){
//         return a[0];
//     }
//     return 
// }