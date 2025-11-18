#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int findOddOccuringElement(vector<int> &arr)
{
    int s = 0;
    int e = arr.size() - 1;

    int mid = s + (e - s) / 2;

    while (s <= e)
    {
        // One element case
        if (s == e)
        {
            return arr[s];
        }

        // Logic for the mid update:
        if (mid & 1)
        {
            // mid is odd
            if (mid + 1 <= e && arr[mid] == arr[mid + 1])
            {
                // next element same
                // right of target & mid not target
                e = mid - 1;
            }
            else
            {
                // next element not same
                // left of target & mid not target
                s = mid + 1;
            }
        }
        else
        {
            // mid is even
            if (mid + 1 <= e && arr[mid] == arr[mid + 1])
            {
                // Next element same
                // mid is target or mid mid left of target
                s = mid;
            }
            else
            {
                // Next element not same
                // mid is target or mid right of target
                e = mid;
            }
        }
        mid = s + (e - s) / 2;
    }

    return -1;
}

int main()
{
    // get file input of array
    int n;
    cin >> n;

    vector<int> arr;
    while (n--)
    {
        int temp;
        cin >> temp;
        arr.push_back(temp);
    }

    int ans = findOddOccuringElement(arr);

    cout << "The odd occurring element is " << ans << endl;

    return 0;
}