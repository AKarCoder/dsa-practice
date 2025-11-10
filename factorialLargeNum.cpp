#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> factorial(int n)
{
    vector<int> ans;
    ans.push_back(1);

    for (int num = 1; num <= n; num++)
    {

        int carry = 0;

        // multiply the num with ans array
        for (int i = 0; i < ans.size(); i++)
        {

            // the result of multiplication
            int res = ans[i] * num + carry;

            // just keep the units digit
            ans[i] = (res % 10);

            // rest is carry
            carry = res / 10;
        }

        // if we have any more carry push them into ans one digit at a time
        while (carry != 0)
        {
            ans.push_back(carry % 10);
            carry = carry / 10;
        }
    }

    // This vector is in reverse order
    reverse(ans.begin(), ans.end());
    return ans;
}

int main()
{

    int n = 0;
    cin >> n;
    vector<int> ans = factorial(n);

    cout << "The Factorial of " << n << " : " << endl;
    // Print out the number
    for (int digit : ans)
    {
        cout << digit;
    }
    cout << endl;
    return 0;
}