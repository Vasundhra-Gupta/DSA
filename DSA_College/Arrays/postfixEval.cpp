#include <iostream>
#include <stack>
#include <string>
#include <cmath>
using namespace std;
#define size 100
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
int postfixEvaluation(string postfix){
    stack<int> st;//it should be integer to store int values
    for(int i=0; i<postfix.length(); i++){
        char c= postfix[i];
        if(c>='0' && c<= '9'){
            st.push(c-'0');
        }
        else{
            int opr1= st.top();
            st.pop();
            int opr2= st.top();
            st.pop();
            int res;
            switch (c){
            case '+':
                res=opr1+opr2;
                break;
            case '-':
                res=opr1-opr2;
                break;
            case '*':
                res=opr1*opr2;
                break;
            case '/':
                res=opr1/opr2;
                break;
            case '^':
                res = pow(opr1, opr2); 
                break;           
            default:
                throw invalid_argument("Wrong Operation");
                break;
            }
            st.push(res);
        }
    }
    return st.top();
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
            while(st.top() != '('){
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
    while(!st.empty()){//this fn is to be defined outside the loop
           postfix= postfix+st.top();
           st.pop();
        }
    return postfix;
}

int main(){
    string infix= "2*(4+3)+2-1";
    cout<<"The infix expression is "<<infix<<endl; 
    string postfix= infixToPostfix(infix);
    cout<<"The postfix expression is "<< postfix<<endl;
    cout<<"The value of postfix expression is "<<postfixEvaluation(postfix);
    return 0;
}
