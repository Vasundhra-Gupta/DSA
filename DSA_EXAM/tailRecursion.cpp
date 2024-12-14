//Demonstrate tail recursion
//When recursion is the last thing to be done
#include <iostream>
using namespace std;

//tail recursion
//just return back back and back (bcz print at frst-? 3 2 1)
void fun1(int n){
    if(n==0) {
        return;
    }else{
        cout<<n<<"\t";
    }
    fun1(n-1);
}

//non-tail Recursion
//first reach to base case and then print return print return (1 2 3)
void fun2(int n){
    if(n==0){
        return;
    }
    fun2(n-1);
    cout<<n<<"\t";
}

int main(){
    fun1(3);
    cout<<endl;
    fun2(3);
    return 0;
}