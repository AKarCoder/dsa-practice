#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

// TC -> O(power)
long long int slowExpo(int base, int power)
{
    long long int ans = 1;

    for (int i = 0; i < power; i++)
    {
        ans = ans * base;
    }

    return ans;
}

// TC -> O(log(power))
long long int fastExpo(int base, int power)
{
    long long int ans = 1;

    // We halve the power at each step, hence we have to square the base
    while (power > 0)
    {
        // If power is odd -> we also have to multiply by base once before we halve power
        if (power & 1)
        {
            ans = ans * base;
        }

        // Halve the power (by right shifting bits by 1)
        power >>= 1;

        // Square the base
        base = base * base;
    }

    return ans;
}

int main()
{
    // long long int val = slowExpo(10, 5);

    long long fasterVal = fastExpo(10, 5);

    // cout << "Value : " << val << endl;

    cout << "Faster : " << fasterVal << endl;

    return 0;
}