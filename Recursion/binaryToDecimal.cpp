#include <iostream>
#include <math.h>
using namespace std;

int binaryToDecimalIterative(long long int binary)
{
    int i = 0;
    int decimal = 0;
    while (binary != 0)
    {
        int rem = binary % 10;
        decimal = decimal + rem * pow(2, i);
        binary = binary/10;
        i++;
    }
    return decimal;
}

int binaryToDecimalRecursive(long long int binary, int pos=0){
    if(binary==0){
        return 0;
    }
    return binary%10 * pow(2, pos) + binaryToDecimalRecursive(binary/10, pos+1);
}

int main()
{
    long long int binary;
    cout<<"Enter number in binary format\n";
    cin>>binary;
    int decimal;
    decimal = binaryToDecimalIterative(binary);
    cout<<decimal<<endl;
    decimal = binaryToDecimalRecursive(binary);
    cout<<decimal<<endl;
    return 0;
}