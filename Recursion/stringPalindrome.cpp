#include <iostream>
using namespace std;

bool checkPalindrome(string str){
    if(str.length()==0 || str.length() == 1){
        return true;
    }

    if(str.at(0)==str.at(str.length()-1)){
        return checkPalindrome(str.substr(1, str.length()-2));
    }
    return false;
}

int main(){
    string str;
    cout<<"Enter a String\n";
    cin>>str;

    checkPalindrome(str) ? cout<<"true" : cout<<"false";
    return 0;
}