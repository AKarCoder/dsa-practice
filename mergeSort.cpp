// Merge Sort
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

// Insertion Sort O(n**2) 
void insertionSort(vector<int>& arr){
    int n = arr.size();

    // start from 1st index, so the array left of 1st index is trivially sorted
    for(int i = 1; i < n; i++){
        int j = i;
        // put the element to it's correct pos in the left sorted arr
        while(j >= 1 && arr[j-1] >= arr[j]){
            // if elements to left are greater swap them
            swap(arr[j-1], arr[j]);
            j--;
        }
    }
} 

// merge two already sorted arrays
void merge(vector<int>& arr, int start, int mid, int end){
    vector<int> mergedArray;
    // start a ptr i on left array and another j on right array
    int i = start;
    int j = mid +1;

    while(i <= mid && j <= end){
        // ptr i on smaller element 
        if(arr[i] < arr[j]){
            // push the i element 
            mergedArray.push_back(arr[i]);
            // move i forward
            i++;
        }
        // ptr j on smaller element
        else{
            mergedArray.push_back(arr[j]);
            j++;
        }
    }

    // whichever left or right array still has some elements push them all
    while(i <= mid){
        mergedArray.push_back(arr[i]);
        i++;
    }
    while(j <= end){
        mergedArray.push_back(arr[j]);
        j++;
    }

    // now graft the mergedArray to our arr
    for(int k = start; k <= end; k++){
        arr[k] = mergedArray[k-start];
    }

}

// mergeSort Divide and Conquer Algo
void mergeSort(vector<int>& arr, int start, int end){
    if(start == end){
        // trivially sorted 1 element
        return;
    }
    // Split the array into 2 parts
    int mid = (end - start)/2 + start;

    // Call mergeSort to sort left and right parts of arr

    // Left 
    mergeSort(arr,start,mid);
    // Right
    mergeSort(arr,mid+1,end);

    // Merge the 2 sorted left and right halves
    merge(arr,start,mid,end);

    return;
}

int main(){
    vector<int> arr = {4,2,-5,-10,18,13,9,22,1};
    // sort above
    int start = 0;
    int end = arr.size() -1;

    // sorting function ptr
    
    // ptr for insertion sort
    void (*func_ptr)(vector<int>&);
    func_ptr = &insertionSort;

    // ptr for merge sort
    void (*func_ptr_better)(vector<int>&, int, int);
    func_ptr_better = &mergeSort;
    
    // use the function ptr
    // func_ptr(arr);
    func_ptr_better(arr, start, end);

    cout << "Sorted Array : ";
    for (auto item : arr){
        cout << item << " ";
    } cout << endl;
}