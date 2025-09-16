#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// to merge the 2 sorted arrays
void merge(vector<int>& arr, int start, int mid, int end, vector<int>& store){
    // get a ptr to both sorted arrays
    int i = start;
    int j = mid +1;

    // ptr to store array
    int k = start;

    // keep running till one array runs out
    while(i <= mid && j <= end){
        if(arr[i] <= arr[j]){
            // i points to smaller 
            store[k] = arr[i];
            // advance both k and i
            k++;
            i++;
        }
        else{
            // j points to smaller
            store[k] = arr[j];
            // adavnce k and j
            k++;
            j++;
        }
    }

    // insert all remaining arr values (if any)
    while(i <= mid){
        store[k] = arr[i];
        k++;
        i++;
    }

    while(j <= end){
        store[k] = arr[j];
        k++;
        j++;
    }

    // graft back the sorted store into arr
    for(int l = start; l <= end; l++){
        arr[l] = store[l]; 
    }
}

// iterative way to mergeSort array
void iterativeMergeSort(vector<int>& arr, vector<int>& store){

    // currSize sets the size of the sorted arrays we merge

    // OuterLoop picks the size of arr we merge (1->2->4->8->.....->arr.size())
    for(int currSize = 1; currSize <= arr.size(); currSize = 2*currSize){

        // For each size, we pick 2 sorted subarrays of that size and merge them
        // We do that for all pairs of such subarrays that can be picked from the array
        for(int start = 0; start <= arr.size() -1; start += 2*currSize){
           
            // compute the valid mid and end for that start

            // this takes care of the case when mid might overshoot array
            // if we do, we just pick the remaining array we get, whose size is lesser than currSize
            int n = arr.size() -1;

            // currSize -1 just picks the subarrays of currSize, cuz, otherwise we get subarrays of currSize +1
            int mid = min(start + (currSize -1), n);

            // similarly, for end
            int end = min(start + (2*currSize -1), n);

            // now we just call merge on the 2 sub-arrays defined by start,mid,end
            merge(arr,start, mid, end, store);
        }

    }
}

int main(){
    vector<int> arr = {4,2,-5,-10,18,13,9,22,1};

    // vector to store the sorted values
    vector<int> store(arr.size(),0);

    iterativeMergeSort(arr, store);

    // printing sorted arr
    for(auto item : arr){
        cout << item << " ";
    }
    cout << endl;
}