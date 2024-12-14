//Check whether LL is palindrome or not, in O(n)
//TC- O(n/2)+O(n)+O(n/2) = O(2n)
//SC - O(1)
#include <iostream>
#include "headers/node.h"
using namespace std;

//BruteForce
// Push All elements to the stack and then compare one by one all elements of LL and Stack
// TC - O(2n)
// SC - O(n)

//After reversing the list mid(43) ke, next me toh abi bhi 33 hi hai, but hm 33->next = NULL kar chuke hai, so that's why after reversing , it looks that elements are missing bcz we didnt connected mid to the new head of LL(which it broke )
//(Not a mistake) Just To consider
// bool isPalindrome(Node *head){
//     Node* mid = middle(head);
//     Node* current1 = head;
//     displayList(current1);
//     Node* current2 = reverseLL(mid->next);
//     displayList(current1);
//     displayList(current2);
//     while(current1!=current2 && current2!=NULL){
//         if(current1->data!=current2->data){
//             return false;
//         }
//         current1 = current1->next;
//         current2 = current2->next;
//     }
//     return true;
// }

bool isPalindrome(Node *head){
    Node* mid = middle(head);
    Node* current1 = head;
    Node* current2 = reverseLL(mid->next);
    mid->next = current2; // reconnecting the LL
    while(current1!=current2 && current2!=NULL){
        if(current1->data!=current2->data){
            return false;
        }
        current1 = current1->next;
        current2 = current2->next;
    }
    return true;
}

int main(){
    Node* head = NULL;
    head= insertAtHead(head, 23);
    head= insertAtHead(head, 33);
    head= insertAtHead(head, 43);
    head= insertAtHead(head, 33);
    head= insertAtHead(head, 23);

    // displayList(head);

    if(isPalindrome(head)){
        cout<<"The Linked List is a Palindrome"<<endl;
    }else{
        cout<<"Not Palindrome"<<endl;
    }
    return 0;
}