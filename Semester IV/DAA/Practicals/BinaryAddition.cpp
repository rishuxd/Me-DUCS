#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector<int> v1 = {1, 0, 1, 1, 1};
    vector<int> v2 = {1, 1, 0, 1, 0, 1};

    vector<int> res = {0, 0, 0, 0, 0, 0, 0};

    int carry = 0;

    int j = v2.size() - 1;
    int k = j + 1;

    for (int i = v1.size() - 1; i >= 0; i--)
    {
        if (v1[i] == v2[j])
        {
            res[k] = 0 + carry;
            carry = v1[i] * v2[j];
        }
        else
        {
            res[k] = (1 + carry) % 2;
            carry = 1 * carry;
        }
        j--;
        k--;
    }

    while (j >= 0)
    {
        if (carry == 0)
            res[k] = carry + v2[j];
        else
        {
            if (v2[j] == 0)
            {
                res[k] = carry + v2[j];
                carry = 0;
            }
            else
            {
                res[k] = (1 + carry) % 2;
                carry = 1 * carry;
            }
        }
        j--;
        k--;
    }
    res[k] = carry;

    for (int i = 0; i < res.size(); i++)
        cout << res[i] << " ";
    cout << endl;

    return 0;
}