//21156_Sarthak_Nirgude
//Batch : G1
#include <iostream>
#define ll long long
using namespace std;

template <class T>
void SelectionSort(T *arr, int n)
{

    for (int i = 0; i < n; i++)
    {
        int minindex = i;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[minindex])
            {
                minindex = j;
            }
        }
        swap(arr[i], arr[minindex]);
    }
}
int main()
{
    int n1, n2;
    cout << "Enter the Number of Integer\n";
    cin >> n1;
    int arr[n1];
    cout << "Enter the Integers\n";
    for (int i = 0; i < n1; i++)
    {
        cin >> arr[i];
    }
    cout << "Enter the Number of Float\n";
    cin >> n2;
    float arr1[n2];
    for (int i = 0; i < n2; i++)
    {
        cin >> arr1[i];
    }
    SelectionSort<int>(arr, n1); //For sorting the integer array
    SelectionSort<float>(arr1, n2); //For sorting the float array

    cout << "Sorted Integers are :\t";
    for (int i = 0; i < n1; i++)
    {
        cout << arr[i] << " ";
    }
    cout << "\nSorted Floats are :\t";
    for (int i = 0; i < n2; i++)
    {
        cout << arr1[i] << " ";
    }

    return 0;
}