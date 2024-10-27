#include <iostream>
using namespace std;
void printName(int n){
    //diamond
    for(int i=0; i<n; i++){
        for(int s=0; s<n-i-1;s++){
            cout<<" ";
        }
        for(int j=0; j<2*i+1; j++){
                cout<<"*";
        }
        cout<<endl;
    }

    for(int i=n-1; i>=0; i--){
        for(int s=0; s<n-i-1;s++){
            cout<<" ";
        }
        for(int j=0; j<2*i+1; j++){
                cout<<"*";
        }
        cout<<endl;
    }

    //triangle
    for(int i=1; i<=2*n -1; i++){
        if(i>n){
            for(int j=0; j<2*n-i; j++){
                cout<<"*";
            }  
        }else{
            for(int j=0; j<i; j++){
                cout<<"*";
            }
        }
        cout<<endl;
    }

    //0 1 flip triangle
    for(int i=0; i<n; i++){
        int start;
        if(i%2==0){
            start=1;
        }else{
            start=0;
        }
        for(int j=0; j<=i; j++){
           cout<<start;
           start= 1- start;
        }
        cout<<endl;
    }

    //numerical v pattern
    for(int i=1; i<=n; i++){
        for(int j=1; j<=i; j++){
            cout<<j;
        }
        for(int s=0; s<2*n-2*i; s++){
            cout<<" ";
        }
        for(int k=i;k>=1; k--){
            cout<<k;
        }
        cout<<endl;
    }

    //A ABA ABBA
    for(int i=0; i<n; i++){
        for(int s=0; s<n-i-1; s++){
            cout<<" ";
        }
        char ch='A'-1;
        for(int j=0; j<2*i+1; j++){
            if(j<=(2*i+1)/2){
                ch++;
            }else{
                ch--;
            }
            cout<<ch;
        }
        cout<<endl;
    }

    //E DE CDE
    for(int i=0; i<n; i++){
        char ch='E';
        ch=ch-i;
        for(int j=0; j<=i; j++){
            cout<<ch;
            ch++;
        }
        cout<<endl;
    }

    //except diamond
    for(int i=0; i<n; i++){
        //star
        for(int j=0; j<n-i; j++){
            cout<<"* ";
        }
        //space
        for(int s=0; s<2*i; s++){
            cout<<"  ";
        }
        //star
        for(int j=0; j<n-i; j++){
            cout<<"* ";
        }
        cout<<endl;
    }
    for(int i=n-1; i>=0; i--){
        //star
        for(int j=0; j<n-i; j++){
            cout<<"* ";
        }
        //space
        for(int s=0; s<2*i; s++){
            cout<<"  ";
        }
        //star
        for(int j=0; j<n-i; j++){
            cout<<"* ";
        }
        cout<<endl;
    }

    cout<<endl;
    //mirror triangle
    //half half
    for(int i=1; i<=n; i++){
        for(int j=1; j<=i; j++){
            cout<<"* ";
        }
        for(int s=0; s<2*n-2*i;s++){
            cout<<"  ";
        }
        for(int j=1; j<=i; j++){
            cout<<"* ";
        }
        cout<<endl;
    }
    for(int i=n-1; i>=1; i--){
        for(int j=1; j<=i; j++){
            cout<<"* ";
        }
        for(int s=0; s<2*n-2*i;s++){
            cout<<"  ";
        }
        for(int j=1; j<=i; j++){
            cout<<"* ";
        }
        cout<<endl;
    }
    cout<<endl;
    //in one go
    for(int i=1; i<=2*n-1; i++){
        //lower
        if(i>n){
            for(int j=0; j<2*n-i; j++){
                cout<<"* ";
            }
            for(int s=0; s<2*i-2*n;s++){
                cout<<"  ";
            }
            for(int j=0; j<2*n-i; j++){
                cout<<"* ";
            }
        }
        //upper
        else{
            for(int j=0; j<i; j++){
                cout<<"* ";
            }
            for(int s=0; s<2*n-2*i;s++){
                cout<<"  ";
            }
            for(int j=0; j<i; j++){
                cout<<"* ";
            }
        }
        cout<<endl;
    }

    //hollow rectangle
    for(int i=1;i<=n;i++){
        for(int j=1; j<=n; j++){
            if(i==1||i==n){
                cout<<"* ";
            }else if(j==1||j==n){
                cout<<"* ";
            }else{
                cout<<"  ";
            }
        }
        cout<<endl;
    }
    /*
    33333
    32223
    32123
    32223
    33333
    */
    // for(int k=1; k<=n; k++){
    for(int i=1; i<=2*n-1; i++){
        for(int j=1; j<=2*n-1; j++){
            //positions
            int top=i-1;
            int bottom= 2*n-1-i;
            int left=j-1;
            int right= 2*n-1-j;
            cout<<(n-min(min(top,bottom),min(left,right)));
            //let us consider a number 3 at i=3 and j=3;
            //then top=2, bottom=7, left=2, right=7
            //5-min(min(2,7), min(2,7));
            //5-min(2,2)
            //3
        }
        cout<<endl;
    }
   }
    
// }
int main(){
    int t;
    cin>>t;
    for(int i=0; i<t; i++){
        int n;
        cin>>n;
        printName(n);
        cout<<"__________________________________"<<endl;
    }
    return 0;
}

