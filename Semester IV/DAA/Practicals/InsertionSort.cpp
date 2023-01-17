#include <iostream>
#include <vector>
using namespace std;

int insertionSort(vector<int> &arr)
{
    int count = 0;
    for (int i = 1; i < arr.size(); i++)
    {
        int temp = arr[i];
        int j = i - 1;
        for (; j >= 0; j--)
        {
            count++;
            if (arr[j] > temp)
                arr[j + 1] = arr[j];
            else
                break;
        }
        arr[j + 1] = temp;
    }
    return count;
}

void display(vector<int> v)
{
    for (int i = 0; i < v.size(); i++)
        cout << v[i] << " ";
    cout << endl;
}

int main()
{
    vector<int> v = {98, 42, 63, 27, 44, 1};
    cout << "No. of comparisions: " << insertionSort(v) << endl;
    cout << "Sorted array: ", display(v);
}