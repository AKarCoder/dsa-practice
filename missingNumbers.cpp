#include <iostream>
#include <vector>

using namespace std;

// Algorithm to find missing numbers in an array (size = n)
// 1 <= nums[i] <= n 

// TC -> O(n)
// SC -> O(1)
void findMissingNum(vector<int> &nums, vector<int> &ans)
{

    int i = 0; // i pointer

    while (i < nums.size())
    {
        // at each i send the number to correct pos
        int index = nums[i] - 1;

        // if number already there
        if (nums[i] == nums[index])
        {
            // move on
            i++;
        }
        else
        {
            // number not there, so swap, and check the new coming number
            swap(nums[i], nums[index]);
        }
    }

    // linear search for the indices without the correct number
    for (int i = 0; i < nums.size(); i++)
    {
        // the correct number isn't at the index, that num is missing
        if (nums[i] != i + 1)
        {
            ans.push_back(i + 1);
        }
    }
}

int main()
{
    int T, num;
    vector<int> arr;
    cin >> T;

    // Take input from array
    while (T--)
    {
        cin >> num;
        arr.push_back(num);
    }

    vector<int> ans;
    // find the missing number
    findMissingNum(arr, ans);

    cout << "The missing numbers : " << endl;
    for (auto item : ans)
    {
        cout << item << " ";
    }
    cout << endl;
    return 0;
}