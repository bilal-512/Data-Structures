#include <iostream>
using namespace std;

// function signatures
void addElement(int arr[], int &idx);
void removeElement(int arr[], int &sizeOfArr);
void end();
void sortArr(int arr[], int size);
void printArr(int arr[], int &s);

// start of the main function

int main()
{
    int arr[1000];
    int index = 0;
    int choice;
    do 
    {
        cout << "Enter Choice: " << endl;
        cout << "1. add element" << endl;
        cout << "2. delete element" << endl;
        cout << "3. exit the program" << endl;
        cin >> choice;
        switch (choice)
        {
        case 1:
            addElement(arr, index);//call the add element function
            break;
        case 2:
            removeElement(arr, index); // call the remove element function
            break;
        case 3:
            end(); // call the end function
            break;
        default:
            cout << "Make a valid choice " << endl;
        }
    }while(choice != 3);

    return 0;
}


// function definations
void sortArr(int arr[], int s)
{
    
    for (int i = 0; i < s; i ++)
    {
        for (int j = i; j < s - 1; j++)

        {
            if (arr[i] > arr[j+1])
            {
                arr[i] = arr[i] + arr[j+1];
                arr[j+1] = arr[i] - arr[j+1];
                arr[i] = arr[i] - arr[j+1];
            }
        }
    }
    printArr(arr, s);
}

// function definations
void addElement(int arr[], int &idx)
{
    if (idx == 1000)
    {
        cout << "Array is full, cannot add elements "<< endl;
        return;
    }
    int element;
    cout << "Enter element to add: ";
    cin >> element;
    arr[idx] = element;
    idx++;
    sortArr(arr, idx);
}

void removeElement(int arr[], int &sizeOfArr)
{
    
    // as our array would be always sorted so we can find element using O(log) time complexity
    int n;
    cout << "Enter Element to remove: " << endl;
    cin >> n;
    int flag  = 0;
    int left  = 0;
    int right = sizeOfArr-1;
    int mid = (left + right )/2;
    int index =-1;
    while (left <= right)
    {
        if (arr[mid] == n)
        {
            index = mid;
            flag = 1;
            break;
        }
        else if (n < arr[mid])
        {
            right = mid -1;
        }
        else
            left = mid +1;
        mid = (left + right) / 2;
    }
    if (flag)
    {
        for (int j = index; j < sizeOfArr - 1; j ++)
        {
            arr[j] = arr[j+1];
        }
        sizeOfArr--;
         printArr(arr, sizeOfArr);
    }
    else 
        {
            cout << "Element could not be found "<< endl;
        }
    
}

void end()
{
    cout << "Ending Program..." << endl;
    exit(1);
}

void printArr(int arr[], int &size)
{
    cout << "Printing array: " << endl;
    for (int i = 0;i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}