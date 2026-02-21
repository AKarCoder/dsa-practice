#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int gcd(int a, int b)
{

    if (a == 0)
        return b;

    if (b == 0)
        return a;

    if (a < b)
    {
        swap(a, b);
    }

    while (b != 0)
    {
        a = a % b;

        swap(a, b);
    }

    return a;
}

int main()
{
    cout << "GCD : " << gcd(1071, 462) << endl;
    cout << "Real GCD : " << __gcd(1071, 462) << endl;
    return 0;
}