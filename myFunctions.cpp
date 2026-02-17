#include <iostream>
#include "myFunctions.hpp"

using namespace std;

void primeNumbers()
{
    int num;
    cout << "Enter limit to print: ";
    cin >> num;

    cout << "The prime numbers are:\n";

    for (int i = 2; i <= num; i++)
    { 
        int count = 0;

        for (int j = 1; j <= i; j++)
        {
            if (i % j == 0)
                count++;

            if (count > 2)
                break;
        }

        if (count == 2)
            cout << i << " ";
    }

    cout << endl;
}


void evenNumbers(){
    int num;
    cout << "Enter last number: ";
    cin >> num;
    cout << "The even numbers are: ";
    for (int i = 1; i <= num; i++)
    {
        if (i % 2 == 0)
            cout << i << " ";
    }
}