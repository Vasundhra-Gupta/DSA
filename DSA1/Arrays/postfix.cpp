#include <iostream>
#include <stack>
#include <string>
using namespace std;
#define size 100
//if precedence is same then the associativity is taken from left to right according to the expression;
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

string infixToPostfix(string infix){
    stack<char> st;
    string postfix= "";
    for(int i=0; i<infix.length();i++){ 
        char c= infix[i];
        //if operand
        if(c>='0' && c<='9'){
            postfix = postfix+c;
        }
        else if(c=='('){
            st.push(c);
        }
        else if(c==')'){
            while(st.top() != '('){//dont use c here instead use st.top();
                postfix = postfix+st.top();
                st.pop();
            }
            st.pop();//to pop (
        }else{
            while(!st.empty() && precedance(c)<=precedance(st.top())){
                postfix= postfix+st.top();
                st.pop();
            }
            st.push(c);
        }
    }
    while(!st.empty()){//this fn is to be defined outside the loop, to push remaining elements of the stack to postfix.
           postfix= postfix+st.top();
           st.pop();
        }
    return postfix;
}

int main(){
    // string infix= "2*(4+3)+2";
    string infix;
    cout<<"Enter Infix Expression";
    cin>>infix;
    cout<<"The infix expression is "<<infix<<endl; 
    string postfix= infixToPostfix(infix);
    cout<<"The postfix expression is "<< postfix;

    return 0;
}
