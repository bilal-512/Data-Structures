
/*
This is lecture 1 of Data Structures by Dr. Mudassar Raza.
I am maintaining this repo just for my learning purpose
main_1.cpp means it lecture 1 work and main_2 means it is lecture 2 and so on.
I have also created header files where i will write my own functions for my help.



*/
#include <iostream>
#include "myFunctions.hpp"

using namespace std;

int main()
{
    char choice;

    do 
    {
        cout << "Enter the char: " << endl;
        cout << "a. Prime numbers" << endl;
        cout << "e. Exit" << endl;

        cin >> choice;  

        switch (choice)
        {
        case 'a':
            primeNumbers();
            break;

        case 'e':
            cout << "Exiting program..." << endl;
            break;

        default:
            cout << "Invalid choice!" << endl;
        }

    } while(choice != 'e');

    return 0;
}
