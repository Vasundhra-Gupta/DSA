//fibbonacci terms till n
#include <iostream>
using namespace std;
int fibo(int);
// int fibbonacci(int, int);
int main(){
    int a=0;
    int b=1;
    int c=0;
    cout<<a<<'\t'<<b<<'\t';
    //using loops
    while(c<20){
        c=a+b;
        cout<<c<<'\t';
        a=b;
        b=c;
    }
    cout<<endl;
    //using recursions(printing ith fibo number)
    for(int i=0; i<10;i++){
        int res =fibo(i);
        cout<<res<<'\t';
    }
   
    return 0;
}

int fibo(int n){
    if(n==0){
        return 0;
    }else if(n==1){
        return 1;
    }else{
        return fibo(n-1)+ fibo(n-2);
    }
}