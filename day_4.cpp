#include <iostream>

using namespace std;

int idx  = 0;
int arr[1000];
void add();
void sortArr();
void exit1();
void print();
void removeElement();
void swap(int a, int b);
//void removeElement();
int main()
{
    int choice;
    do 
    {
        cout << "Enter Choice: " << endl;
        cout << "1. Add "<< endl;
        cout << "2. Delete " << endl;
        cout << "3. Exit" << endl;
        cout << "4. Print " << endl;
        cin >> choice;
        switch (choice)
        {
        case 1:
           add();
            break;
        case 2:
            removeElement();
           break;
        case 3:
            exit1();break;
        case 4 :
        print();break;
        default:
            break;
        }

    } while (1);
    
    return 0;
}


// function definations
void print()
{
    for (int i = 0; i < idx; i++)
    {
        cout << arr[i] << " ";
    }
}
void add()
{
    int n;
    cout << "Enter element to add: ";
    cin >>n;
    arr[idx] = n;
    idx++;
    sortArr();
}
void sortArr()
{
    for (int i = idx-1; i > 0; i--)
    {
        if (arr[i] > arr[i-1])
            swap(arr[i], arr[i-1]);
    }
}

void removeElement()
{
    int v;
    cout << "Enter value to delete: ";
    cin >> v;
    for (int i = 0; i < idx-1;i++)
    {
        if (arr[i] == v)
        {
            arr[i] = INT_MAX;
                sortArr();
    idx--;
            break;
        }
    }

}
void exit1()
{
    exit(1);
}

void swap(int a, int b)
{
    int temp;
    temp = a;
    a = b;
    b = temp;
}