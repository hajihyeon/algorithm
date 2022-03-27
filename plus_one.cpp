#include <stdio.h>
#include <iostream>
#include <vector>
using namespace std;

vector<int> plusOne(vector<int> &digits)
{
    int size = digits.size();
    vector<int> result;
    int carry = 1;
    for (int i = 0; i < size; i++)
    {
        int num = digits[size - i - 1] + carry;
        result.push_back(num % 10);
        carry = num / 10;
    }
    if (carry != 0)
    {
        result.push_back(carry);
    }

    size = result.size();
    vector<int> reverse_result;
    for (int i = 0; i < size; i++)
    {
        reverse_result.push_back(result[size - i - 1]);
    }
    return reverse_result;
};

int main()
{
    vector<int> vect{ 4, 3, 2, 1 };
    vect = plusOne(vect);
    for(int i=0; i<vect.size(); i++){
        cout << vect[i];
    }
    return 0;
}