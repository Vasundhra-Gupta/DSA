#include <iostream>
using namespace std;

void decimalToBinaryIterative(int num)
{
    int binary[32];
    int i = 0;
    while (num != 0)
    {
        binary[i] = num % 2;
        i++;
        num = num / 2;
    }

    for (int j = i - 1; j >= 0; j--)
    {
        cout << binary[j];
    }
    cout << endl;
}

string decimalToBinaryRecursive(int num)
{
    if (num == 0)
    {
        return "0";
    }
    if(num ==1){
        return "1";
    }

    return decimalToBinaryRecursive(num / 2) + to_string(num%2);
}

int main()
{
    int num;
    cout << "Enter number" << endl;
    cin >> num;
    decimalToBinaryIterative(num);
    string binary = decimalToBinaryRecursive(num);
    cout<<binary;
    return 0;
}