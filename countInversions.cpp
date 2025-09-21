// 
#include <iostream>
#include <vector>

using namespace std;

// counts inversions and merges the 2 sorted arrays in one sorted array
int countInvMerge(vector<int>& arr, int start, int mid, int end){

    // vector to store the combined sorted array
    vector<int> store;

    // count to store the total inversion
    int count = 0;

    // ptrs to both left and right array
    int i = start;
    int j = mid +1;

    // place the elements in sorted fashion till one arr runs out
    while(i <= mid && j <= end){
        if(arr[i] <= arr[j]){
            // i points to smaller push arr[i] and move i
            store.push_back(arr[i]);
            i++;
        }
        else{
            // j (right ptr is pointing to smaller, hence inversion)
            // all the elements from ith to mid in the left array will count as left array is sorted ascending

             count += (mid -i) +1;

            // j points to smaller push arr[j] and move j
            store.push_back(arr[j]);
            j++;
        }
    }

    // push any remaining elements to store
    while(i <= mid){
        store.push_back(arr[i]);
        i++;
    }

    while(j <= end){
        store.push_back(arr[j]);
        j++;
    }

    // graft the sorted store vector back into arr

    for(int k = start; k <= end; k++){
        arr[k] = store[k - start];
    }

    return count;
}


int countInversion(vector<int>& arr, int start, int end){

    if(start >= end){
        // 1 element -> no inversion
        return 0;
    }
    
    int mid = (end - start)/2 + start;

    // get all the inversions in the left and right array
    int leftInvCount = countInversion(arr, start, mid);
    int rightInvCount = countInversion(arr, mid+1, end);

    // get all the inversions in the current array with sorted left and right halves
    int currentInvCount = countInvMerge(arr, start, mid, end);

    // thus total inversions of the array
    return (leftInvCount + currentInvCount +rightInvCount);

}


int main(){

    vector<int> arr =  {4,2,-5,-10,18,13,9,22,1};

    // sort above
    int start = 0;
    int end = arr.size() -1;

    int totalInversions = countInversion(arr, start, end);

    cout << "Total Inversions in given arr : " << totalInversions << endl;

    cout << "Sorted Array : ";
    for (auto item : arr){
        cout << item << " ";
    } cout << endl;
}