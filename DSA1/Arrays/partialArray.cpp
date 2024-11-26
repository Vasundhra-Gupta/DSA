// Write a program to implement insertion, deletion, traversal of the partially-filled array.
#include <iostream>
using namespace std;
void traversal(int[], int);
void insertAtBeginning(int[], int &);
void insertAtEnd(int[], int &);
void insertAtPosition(int[], int &, int);
void deleteAtBeginning(int[], int &);
void deleteAtEnd(int[],int &);
void deleteAtPosition(int[], int &, int);
void searchNo(int [], int);

int main() {
    int arr[10]={1,2,3,4,5,6,7};
    int ele= 7;
    cout<<"Traversal"<<endl;
    traversal(arr, ele);
    cout<<endl;
    cout<<"Insertion at begining"<<endl;
    insertAtBeginning(arr, ele);
    cout<<endl;
    cout<<"Insertion at end"<<endl;
    insertAtEnd(arr, ele);
    cout<<endl;
    cout<<"Insertion at specified position"<<endl;
    insertAtPosition(arr, ele, 3);
    cout<<endl;
    cout<<"Deletion at beginning"<<endl;
    deleteAtBeginning(arr, ele);
    cout<<endl;
    cout<<"Deletion at end"<<endl;
    deleteAtEnd(arr, ele);
    cout<<endl;
    cout<<"Deletion at specified position"<<endl;
    deleteAtPosition(arr, ele, 2);
    cout<<endl;
    int search;
    cout<<"Searching the number"<<endl;
    cout<<"Enter number to be searched"<<endl;
    cin>>search;
    searchNo(arr, search);
    return 0;
}
void traversal(int arr[], int ele){
    //Traversal
    for(int i=0; i<10; i++){
        if(i<ele){
            cout<<arr[i]<<endl;
        }else{
            cout<<"_"<<endl;
        }
    }
}
void insertAtBeginning(int arr[], int &ele){
    if(ele<10){
        for(int i=ele; i>0; i--){
                arr[i]= arr[i-1];
        }
        arr[0]=10;
        ele++;
    }else{
        cout<<"Array is full, cannot insert element!"<<endl;
    }
    traversal(arr, ele);
}
void insertAtEnd(int arr[], int &ele){
    if(ele<10){
        for(int i=0; i<10; i++){
        //   continue; 
        }
        arr[ele]=12;
        ele++;
    }else{
        cout<<"Array is full, cannot insert element!"<<endl;
    }
    traversal(arr, ele);
}
void insertAtPosition(int arr[], int &ele, int position){
    if(ele<10){
        for(int i=ele; i>position-1; i--){
            arr[i]=arr[i-1]; 
        }
        arr[position-1]=15;
        // arr[position2-1]= 20;
        ele++;
    }else{
        cout<<"Array is full, cannot insert element!"<<endl;
    }
    traversal(arr, ele);
}
void deleteAtBeginning(int arr[], int &ele){
    for(int i=0; i<10; i++){
        arr[i]=arr[i+1];
    }
    ele--;
    traversal(arr, ele);
}
void deleteAtEnd(int arr[], int &ele){
    for(int i=0; i<10; i++){
            arr[ele]=0;
    }
    ele--;
    traversal(arr, ele);
}
void deleteAtPosition(int arr[], int &ele, int position){
    for(int i=position-2; i<10; i++){
        arr[i]=arr[i+1];
    }
    ele--;
    traversal(arr, ele);
}
void searchNo(int arr[], int search){
        bool found;
        for(int i=0; i<10; i++){
            if(arr[i]==search){
                found=true;
                cout<<"The required number is at position number "<<i+1<<endl;
            }
        }
        if(!found){
            cout<<"Number not found"<<endl;
        }
}