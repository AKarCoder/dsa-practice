#include <iostream>
#include <vector>
using namespace std;

void merge(vector<int>& arr, int start, int mid, int end, vector<int>& store ){
    // arr's start -> mid sorted array 1
    // arr's mid+1 -> end sorted array 2
    
    // merge them in vector store

    // start ptr i and j
    int i = start;
    int j = mid+1;

    // another ptr k to point to the store arr
    // begins from start index but must end by the end index

    int k = start;

    // till one of the sorted arr expires
    while(i <= mid && j <= end){
        if(arr[i] <= arr[j]){
            // i points to lesser value 
            store[k] = arr[i];
            // advance k and i
            k++;
            i++;
        }
        else{
            // j points to lesser value
            store[k] = arr[j];
            // advance k and j
            k++;
            j++;
        }
    }

    // store all the remaining elements of left arr (if any)
    while(i <= mid){
        store[k] = arr[i];
        // advance i and k
        k++;
        i++;
    }
    // store all the remaining elements of right arr (if any)
    while(j <= end){
        store[k] = arr[j];
        // advance j and k
        j++;
        k++;
    }

    // Now graft all the sorted elements from store back to arr
    for(int l = start; l <= end; l++){
        arr[l] = store[l];
    }

}

// mergeSort Divide and Conquer Algo
void mergeSort(vector<int>& arr, int start, int end, vector<int>& store){
    if(start == end){
        // trivially sorted 1 element
        return;
    }
    // Split the array into 2 parts
    int mid = (end - start)/2 + start;

    // Call mergeSort to sort left and right parts of arr

    // Left 
    mergeSort(arr,start,mid, store);
    // Right
    mergeSort(arr,mid+1,end, store);

    // Merge the 2 sorted left and right halves
    
    merge(arr,start, mid, end, store);

    return;
}

int main(){
    vector<int> arr = {4,2,-5,-10,18,13,9,22,1};

    // store singular array to write & read during mergeSort
    vector<int> store(arr.size(),0);

    int start = 0;
    int end = arr.size() -1;

    mergeSort(arr, start, end, store);

    // print sorted arr
    for (auto item : arr){
        cout << item << " ";
    }
    cout << endl;
}