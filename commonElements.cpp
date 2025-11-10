#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>

using namespace std;

// returns duplicate removed array in O(n) time and constant space
vector<int> removeDuplicates(vector<int> &arr)
{
    // we use a window approach
    int i = 0;

    // Marks all duplicates as INT_MIN in O(n) Time
    // viable since arr is sorted so all duplicates are bunched toghether

    while (i < arr.size())
    {
        int j = i + 1;
        // j within bound and j-th element is duplicate of i-th element
        while (j < arr.size() && arr[j] == arr[i])
        {
            // replace j-th element with INT_MIN
            arr[j] = INT_MIN;

            // increment j
            j++;
        }
        // update i
        i = j;
    }

    // Now build an array without the duplicates
    vector<int> ans;

    for (int item : arr)
    {
        // push item in ans only if it's not marked
        if (item != INT_MIN)
        {
            ans.push_back(item);
        }
    }

    return ans;
}

// find elements common to all 3 sorted arrays
void findCommonElements(vector<int> &a, vector<int> &b, vector<int> &c, vector<int> &ans)
{
    int i = 0;
    int j = 0;
    int k = 0;

    // run till we run out of any one array
    while (i < a.size() && j < b.size() && k < c.size())
    {
        // are we on same elements ?
        if ((a[i] == b[j]) && (b[j] == c[k]))
        {
            // yes
            ans.push_back(a[i]);

            // increment the pointers to next element in their array
            i++;
            j++;
            k++;
        }
        else
        {
            // no
            // Then, determine which of 3 pointers is on maxValue
            int maxValue = max(a[i], max(b[j], c[k]));

            // iterate all pointers till we reach greater or equal maxValue (till < maxValue)

            while (i < a.size() && a[i] < maxValue)
            {
                i++;
            }

            while (j < b.size() && b[j] < maxValue)
            {
                j++;
            }

            while (k < c.size() && c[k] < maxValue)
            {
                k++;
            }
        }
    }
}

int main()
{

    // 3 Sorted Arrays
    vector<int> a = {1, 1, 1, 2, 2, 2};
    vector<int> b = {1, 1, 2, 2, 2};
    vector<int> c = {1, 1, 1, 1, 2, 2, 2, 2};

    // remove duplicates within the array
    a = removeDuplicates(a);
    b = removeDuplicates(b);
    c = removeDuplicates(c);

    vector<int> ans;

    // find common elements and push into ans
    findCommonElements(a, b, c, ans);

    // print out ans vector
    cout << "Common Elements : " << endl;

    for (int item : ans)
    {
        cout << item << " ";
    }
    cout << endl;

    return 0;
}