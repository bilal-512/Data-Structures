#include <iostream>
using namespace std;

int main(int argc, char* argv[])
{
    // the first argument is always interger and it holds the number of arguments
    // the second argument is array of string which holds the string of each argument
    int sum = 0;
    for (int i = 1; i < argc; i++)
    {
        sum += stoi(argv[i]);
    }
    cout << "The sum of arguments is: " << sum<<endl;
    return 0;
}