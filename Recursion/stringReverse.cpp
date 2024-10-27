#include <iostream>
using namespace std;

string reverseString(string str){
    if(str==""){
        return "";
    }
    return reverseString(str.substr(1)) + str.at(0);
}

// rev(boy)=  rev(oy) + b
// rev(oy) = rev(y) + o
//rev(y) = rev("") + y
//rev("") = ""

//so rev(boy) = 
int main(){
    string str;
    cout<<"Enter a string\n";
    cin>>str;
    string reverseStr = reverseString(str);
    cout<<reverseStr<<endl;
    return 0;
}