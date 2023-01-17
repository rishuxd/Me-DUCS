#include <iostream>
#include <vector>
using namespace std;

int linearSearch(vector<int> arr, int key)
{
    for (int i = 0; i < arr.size(); i++)
    {
        if (arr[i] == key)
            return i;
    }
    return -1;
}

int main()
{
    vector<int> arr = {4, 1, 2, 8, 6, 10};
    cout << linearSearch(arr, 10) << endl;
}