#include <iostream>
#include <stack>
#include <string>
#include <algorithm>
#include <cmath>
using namespace std;

int precedance(char c){
    if(c=='+'||c=='-')
        return 1;
    else if(c=='*'||c=='/')
        return 2;
    else if(c=='^')
        return 3;
    else
        return -1;
}
string infixToPrefix(string infix){
    reverse(infix.begin(), infix.end());
    stack<char> st;
    string prefix= "";
    for(int i=0; i<infix.length();i++){ 
        char c= infix[i];
        //if operand
        if(c>='0' && c<='9'){
            prefix +=c;
        }
        else if(c==')'){//intechange the brackets
            st.push(c);
        }
        else if(c=='('){//'(' means ')'
            while(st.top() != ')'){
                prefix += st.top();
                st.pop();
            }
            st.pop();//to pop (
        }else{
            while(!st.empty() && precedance(c)<=precedance(st.top())){
                prefix += st.top();
                st.pop();
            }
            st.push(c);
        }
    }
    while(!st.empty()){//this fn is to be defined outside the loop, to push remaining elements of the stack to postfix.
           prefix += st.top();
           st.pop();
        }
    return prefix;
}

int main(){
    string infix= "a+b*c";
    string prefix= infixToPrefix(infix);
    cout<<"The infix expression is "<<infix<<endl; 
    string postfix= infixToPrefix(infix);
    cout<<"The prefix expression is "<< prefix;
    return 0;
}