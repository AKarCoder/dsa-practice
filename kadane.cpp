#include <iostream>
#include <climits>
using namespace std;

// Implement Kadane Algorithm
int maxSubSum(int *arr){

    int maxSubSoFar = arr[0];
    int result = INT_MIN;
    for(int i = 1; i < 7; i++){
        // maxSubarray sum is +ve
        if(maxSubSoFar >= 0){
            // add the curr element
            maxSubSoFar += arr[i];
        }
        // maxSubarray sum is -ve
        else{
            // start a new sub array from curr element
            maxSubSoFar = arr[i];
        }

        // Keep maximum of subarray sum in the result
        result = (maxSubSoFar >= result) ? (maxSubSoFar) : (result);
    }
    return result;
}

int main(){
    int arr[7] = {2,3,-8,7,-1,2,3};
    int res = maxSubSum(arr);
    cout << "Answer : " << res << endl;
}