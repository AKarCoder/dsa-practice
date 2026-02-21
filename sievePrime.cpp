#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>

using namespace std;

vector<bool> sieve(int n)
{
    // vector of primes
    vector<bool> primes(n + 1, true);

    primes[0] = false;
    primes[1] = false;

    for (int i = 2; i <= sqrt(n); i++)
    {
        if (primes[i])
        {
            int j = 2 * i;

            while (j <= n)
            {
                primes[j] = false;
                j += i;
            }
        }
    }

    return primes;
}

vector<bool> segmentedSieve(int l, int h)
{
    vector<bool> segmentPrimes(h - l + 1, true);

    vector<bool> sqrtPrimes = sieve(sqrt(h));

    // Mark the segment primes using primes <= sqrt(h)
    for (int i = 2; i < sqrtPrimes.size(); i++)
    {
        if (sqrtPrimes[i])
        {
            // Map j to correct int >= low
            int j = (l / i) * i;

            // if j is less than l -> go to the multiple higher than l by adding i
            if (j < l)
            {
                j += i;
            }

            // Now since i is a prime and if j is same as i -> don't mark i as non prime
            if (j == i)
            {
                j += i;
            }

            while (j <= h)
            {
                segmentPrimes[j - l] = false;
                j += i;
            }
        }
    }

    return segmentPrimes;
}

int main()
{
    int low = 100;
    int high = 200;

    vector<bool> ans = segmentedSieve(low, high);

    cout << "All primes in range " << low << " to " << high << " : " << endl;

    for (int i = 0; i < ans.size(); i++)
    {
        if (ans[i])
        {
            cout << (i + low) << " ";
        }
    }
    cout << endl;

    return 0;
}