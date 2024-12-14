//to merge such that nodes from both nodes from both are taken alternatively.
//TC -> O(n)

#include <iostream>
#include "headers/node.h"
using namespace std;

// Node* mergeTwoSortedLists(Node* head1, Node* head2){
//     Node* head = new Node(INT8_MIN);
//     Node* current = head;

//     while(head1!=NULL && head2!=NULL){
//         if(head1->data<=head2->data){
//             current = head1;
//             cout<<current->data<<"A"<<endl;
//             head1 = head1->next;
//             current = current->next;
//         }else if(head2->data<head1->data){
//             current = head2;
//             cout<<current->data<<"B"<<endl;
//             head2 = head2->next;
//             current = current->next;
//         }
//     }

//     while(head1!= NULL){
//         current = head1;
//         cout<<current->data<<"D"<<endl;
//         head1 = head1->next;
//     }

//     while(head2!= NULL){
//         current = head2;
//         cout<<current->data<<"E"<<endl;
//         head2 = head2->next;
//     }
//     return head;
// }

Node* mergeTwoSortedLists(Node* head1, Node* head2){
    Node* head = new Node(INT8_MIN);
    Node* current = head;

    while(head1!=NULL && head2!=NULL){
        if(head1->data<=head2->data){
            current->next = head1;
            current = head1;
            head1 = head1->next;
        }else if(head2->data<head1->data){
            current->next = head2;
            current = head2;
            head2 = head2->next;
        }
    }

    while(head1!= NULL){
        current->next = head1;
        current = head1;
        head1 = head1->next;
    }

    while(head2!= NULL){
        current->next = head2;
        current = head2;
        head2 = head2->next;
    }
    return head->next;
}

int main(){
    Node* head1 = NULL;
    Node* head2 = NULL;
    Node* head = NULL;
    int arr1[] = {5, 4, 3, 2, 1}; 
    int n1 =sizeof(arr1)/sizeof(arr1[0]);
    head1 = makeALinkedList(head1, arr1, n1);
    displayList(head1);
    int arr2[] = {7, 5, 3, 1}; 
    int n2 =sizeof(arr2)/sizeof(arr2[0]);
    head2 = makeALinkedList(head2, arr2, n2);
    displayList(head2);

    head = mergeTwoSortedLists(head1, head2);
    displayList(head);
    return 0;
}
