#include <iostream>
#include <string>
#include <cmath>
using namespace std;
//note: for some reason the decToBinary function outputs a space first

string decToBinary();
int binaryToDec();
void menu();

int main()
{
    bool flag;
    char choice = true;

    do{
        menu();
        cin >> choice;
        switch(choice)
        {
            case 'q':
            case 'Q':
                flag = false;
                break;
            case 'd':
            case 'D':
                cout << binaryToDec();
                break;
            case 'b':
            case 'B':
                cout << decToBinary();
                break;
            default:
                cout << "Invalid selection. Try again. \n\n";
                break;
        }
    }while(flag);
    return 0;
}

/*
1   0   0   1   1   1   0   0
2^7 2^6 2^5 2^4 2^3 2^2 2^1 2^0
128 64  32  16  8   4   2   1    */
/*logic behind it:
1) receive a string
2) go through all the positions
3)  a) i[0]= 2^(str.length()-1)
    b) i[1]= 2^(str.length()-2)
    c) i[n]= 2^(str.length()-(n+1))*/
int binaryToDec()
{
    string toConv;
    cout << "Please enter the binary number you wish to convert: " <<endl;
    cin >> toConv;

    int decimal = 0;
    for(int i=0;i<toConv.length();i++)
    {
        if(toConv[i] == '1')
            decimal += pow(2,(toConv.length()-(i+1)));
    }
    return decimal;
}

/*
156/2  0
78/2   0
39/2   1
19/2   1
9/2    1
4/2    0
2/2    0
1/2    1    */
//basic idea here is if dividend is even you put a 0
//if odd put a 1. output in reverse order
//i.e. read bottom up in the case of the chart above
string decToBinary()
{
    int toConv;
    cout << "Please enter the decimal number you wish to convert: " <<endl;
    cin >> toConv;

    string binaryOut,revBinaryOut;

    while(toConv>=1)
    {
        if(toConv%2==0)
            binaryOut += "0";
        else
            binaryOut += "1";

        toConv/=2;
    }
    for(int i = binaryOut.length();i>=0;i--) //reverse string
    {
        revBinaryOut+=binaryOut[i];
    }

    return revBinaryOut;
}

void menu()
{
    cout << endl << endl;
    cout << "What are you converting into? (case insensitive):" << endl;
    cout << "\t****************************" << endl;
    cout << "\t     B -- Decimal -> Binary" << endl;
    cout << "\t     D -- Binary -> Decimal" << endl;
    cout << "\t     Q - Quit" << endl;
    cout << endl << "\tEnter your selection: ";
    return;
}