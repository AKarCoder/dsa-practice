#include <iostream>
#include <vector>

using  namespace std;

// min Heap
class Heap{
    private:
    // heap array to store numbers
    vector<int> heap;
    int end = -1;

    // sends element up the tree to correct pos
    void siftUp(int i){
        // till we reach root or place heap[i] in correct pos
        while(i >= 1 && heap[(i-1)/2] > heap[i]){
            // swap and update i
            swap(heap[i], heap[(i-1)/2]);
            i = (i-1)/2;         
        }
    }
    
    // sends element down the tree to correct pos
    void siftDown(int i){

        // if (2*i) +1 > end -> no child exists of that node/leaf, hence do nothing
        while((2*i) +1 <=  end){
            // least supposed to hold least of the three (1 parent & 2 child)
            int least = i;
            
            // first child is smaller than parent
            if(heap[i] > heap[(2*i) +1]){
                least = (2*i) +1;
            }

            // second child exits and is smaller than least element
            if((2*i) +2 <= end && heap[least] > heap[(2*i) +2]){
                least = (2*i) +2;
            }

            // we are on least element
            if(least == i){
                // we have reached correct pos
                break;
            }

            // swap least element and parent node
            swap(heap[i], heap[least]);

            // update i onto where we swapped
            i = least;
        }
    }
   
    public:

    int size(){
        // size of heap currently
        return end +1;
    }

    void insert(int val){
        // insert in heap
        heap.push_back(val);
        end++;

        // go up the Heap to place in proper pos
        siftUp(end);
    }

    int pop(){
        // top of heap holds min element
        int min = heap[0];

        // swap the top and last element and remove the newly swapped last element
        swap(heap[0], heap[end]);
        end--;

        // place the newly swapped top element to correct pos
        siftDown(0);

        // give back the min element
        return min;
    }

};

int main(){
    int T;
    cin >> T;
    int num;

    Heap minHeap;

    while(T--){
        cin >> num;
        minHeap.insert(num);
    }

    cout << "Min Heap : " << endl;
    
    while(minHeap.size() > 0){
        cout << minHeap.pop() << " ";
    }
    cout << endl;

}