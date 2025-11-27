#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int binSearch(vector<int> &arr, int x)
{
    int s = 0;
    int e = arr.size() - 1;

    int mid = s + (e - s) / 2;

    int index = -1;

    while (s <= e)
    {
        if (arr[mid] == x)
        {
            // Found it
            return mid;
        }
        else if (arr[mid] < x)
        {
            // Store and look for closer in right
            index = mid;
            s = mid + 1;
        }
        else
        {
            // Look in left
            e = mid - 1;
        }
        mid = s + (e - s) / 2;
    }

    // We deal with x < arr[0] case, by sending the closest valid index
    if (index < 0)
        return 0;

    // Here, we are guaranteed -> index >= 0
    if (index + 1 < arr.size() && abs(arr[index + 1] - x) < abs(arr[index] - x))
    {
        // closest (from right) index is index + 1
        index++;
    }

    return index;
}

// Binary Seach + 2 pointer approach with an expanding window upto size k
// TC  -> O(k log(n))

vector<int> findClosestElements(vector<int> &arr, int k, int x)
{
    // we got index closest to x:
    int closestIndex = binSearch(arr, x);

    // We include the first element
    int left = closestIndex - 1;
    int right = closestIndex + 1;

    // Till we have ints to fill : the Subarray we take [left +1 : right -1]

    // Each loop turn takes 1 element by k--
    while (k > 1)
    {
        // if left is outta bound
        if (left < 0)
        {
            right++;
        }
        // right is outta bound
        else if (right >= arr.size())
        {
            left--;
        }
        // within bound
        else if (abs(arr[left] - x) <= abs(arr[right] - x))
        {
            // left is closer to x than right
            left--;
        }
        else
        {
            // right is closer to x than left
            right++;
        }
        k--;
    }

    // Now, our sorted ans lies in arr[left +1 : right -1]
    vector<int> ans;

    for (int i = left + 1; i <= right - 1; i++)
    {
        ans.push_back(arr[i]);
    }

    return ans;
}

// Alternative approaches:

// 1. Sorting using the distance of arr[i] from x:

// Custom Comparator Class that looks at abs(arr[i] - x) to sort
class Comp
{
public:
    int x;

    Comp(int xVal)
    {
        x = xVal;
    }

    bool operator()(int a, int b)
    {
        if (abs(a - x) >= abs(b - x))
        {
            return false;
        }
        return true;
    }
};

// TC -> O(n log(n))
vector<int> kClosestElements(vector<int> &arr, int k, int x)
{

    // Sort (stable) the array with custom comparator
    Comp cmp(x);

    stable_sort(arr.begin(), arr.end(), cmp);

    // Store the first K elements in ans and sort that
    vector<int> ans;

    for (int i = 0; i < k && i < arr.size(); i++)
    {
        ans.push_back(arr[i]);
    }

    sort(ans.begin(), ans.end());

    return ans;
}

// 2. Using the 2 pointer method as arr is sorted

// Tc -> O(n - k)
vector<int> closestElements(vector<int> &arr, int k, int x)
{
    int left = 0;
    int right = arr.size() - 1;

    // arr[left : right] is the sorted array of k elements closest to x

    // arr[left : right] lenght is k when right - left == k-1
    while (right - left >= k)
    {
        if (abs(arr[left] - x) > abs(arr[right] - x))
        {
            // Remove arr[left] from consideration
            left++;
        }
        else
        {
            // abs(arr[right] - x) greater than equal to abs(arr[left] - x), remove arr[right]
            // Especially, in equal case : we are told to keep the lesser value arr[left]
            right--;
        }
    }
    
    vector<int> ans;

    for (int i = left; i <= right; i++)
    {
        // place arr[left : right] in ans
        ans.push_back(arr[i]);
    }

    return ans;
}

int main()
{
    vector<int> arr = {1, 2, 3, 4, 5};
    int x = 4;
    int k = 3;

    // 2 pointer + Modified Binary Search
    vector<int> ans = findClosestElements(arr, k, x);

    // print ans
    cout << "Ans array : ";
    for (auto item : ans)
    {
        cout << item << " ";
    }
    cout << endl;

    // Custom Comparator Sorting
    vector<int> anotherAns = kClosestElements(arr, k, x);

    cout << "Using Custom Sorting : ";

    for (auto item : anotherAns)
    {
        cout << item << " ";
    }
    cout << endl;

    // Pure 2 pointer method
    vector<int> newArr = {1, 2, 3, 4, 5};
    vector<int> yetAnotherAns = closestElements(newArr, k, x);

    cout << "Using just 2 pointer : ";

    for (auto item : yetAnotherAns)
    {
        cout << item << " ";
    }
    cout << endl;

    return 0;
}