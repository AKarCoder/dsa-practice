#include <iostream>
#include <vector>

using namespace std;

class JointHeap
{
public:
    vector<int> minHeap;
    vector<int> maxHeap;

    int minHeapEnd = -1;
    int maxHeapEnd = -1;

    void maxHeapSiftUp(vector<int> &heap, int node)
    {
        // sift up till we reach root or stop
        while (node > 0)
        {
            int parent = (node - 1) / 2;

            if (heap[node] > heap[parent])
            {
                // we need to swap
                swap(heap[node], heap[parent]);

                // update node to it's new pos
                node = parent;
            }
            else
            {
                // we are at correct pos
                break;
            }
        }
    }

    void minHeapSiftUp(vector<int> &heap, int node)
    {
        // sift till we stop or reach root node (0)
        while (node > 0)
        {
            int parent = (node - 1) / 2;

            if (heap[node] < heap[parent])
            {
                // we need to swap
                swap(heap[node], heap[parent]);

                // update to new node
                node = parent;
            }
            else
            {
                // we are at correct pos
                break;
            }
        }
    }

    void minHeapSiftDown(vector<int> &heap, int node)
    {
        // whilst we still on nodes with children
        while ((2 * node) + 1 < heap.size())
        {
            // assume current node is smallest
            int smallest = node;

            // one child exists and its smaller -> it's now smallest
            if (heap[(2 * node) + 1] < heap[node])
            {
                smallest = (2 * node) + 1;
            }

            // second child exists and it's smaller than the curr smallest
            if ((2 * node + 2) < heap.size() && heap[(2 * node + 2)] < heap[smallest])
            {
                smallest = 2 * node + 2;
            }

            // present node is smallest
            if (smallest == node)
            {
                // curr pos is the correct pos
                break;
            }

            // swap the node with the smallest child
            swap(heap[node], heap[smallest]);

            // update the current node to keep sifting it down
            node = smallest;
        }
    }

    void maxHeapSiftDown(vector<int> &heap, int node)
    {

        // while we still on nodes with children
        while ((2 * node) + 1 < heap.size())
        {
            // assume the curr node is largest
            int largest = node;

            // check if it's 1st children is larger
            if (heap[(2 * node) + 1] > heap[node])
            {
                // now it's the largest
                largest = (2 * node) + 1;
            }

            // check if it's 2nd child exists and if it's larger
            if ((2 * node) + 2 < heap.size() && heap[(2 * node) + 2] > heap[largest])
            {
                // now it's largest
                largest = (2 * node) + 2;
            }

            // if curr node is same as largest -> we can stop
            if (node == largest)
            {
                break;
            }

            // swap node with largest child
            swap(heap[node], heap[largest]);

            // update to new node -> so that sifting down continues
            node = largest;
        }
    }

    int minHeapTop(vector<int> &heap)
    {
        if (heap.size() > 0)
        {
            return heap[0];
        }
    }

    int minHeapPop(vector<int> &heap)
    {
        if (heap.size() == 1)
        {
            int top = heap[0];

            // just remove the one element
            minHeapEnd--;
            heap.pop_back();

            return top;
        }

        if (heap.size() > 1)
        {
            // store: min Value
            int top = heap[0];

            // swap the last heap element and top and remove last node
            swap(heap[0], heap[heap.size() - 1]);
            minHeapEnd--;

            minHeap.pop_back();

            // set the new heap[0] to correct pos
            minHeapSiftDown(heap, 0);

            return top;
        }
    }

    void minHeapPush(vector<int> &heap, int val)
    {
        // push the value to minHeap (last pos)
        heap.push_back(val);
        minHeapEnd++;

        // siftUp to it correct pos
        minHeapSiftUp(heap, heap.size() - 1);
    }

    int maxHeapTop(vector<int> &heap)
    {
        if (heap.size() > 0)
        {
            return heap[0];
        }
    }

    int maxHeapPop(vector<int> &heap)
    {
        if (heap.size() == 1)
        {
            int top = heap[0];

            // just remove the one element
            maxHeapEnd--;
            maxHeap.pop_back();

            return top;
        }

        if (heap.size() > 1)
        {
            // store: largest value
            int top = heap[0];

            // swap the top with the last node and remove last node
            swap(heap[0], heap[heap.size() - 1]);
            maxHeapEnd--;

            maxHeap.pop_back();

            // sift down the new heap[0] to correct pos
            maxHeapSiftDown(heap, 0);

            return top;
        }
    }

    void maxHeapPush(vector<int> &heap, int val)
    {
        // push value into the max Heap
        maxHeap.push_back(val);
        maxHeapEnd++;

        // sift it up to correct pos
        maxHeapSiftUp(heap, heap.size() - 1);
    }

    // These functions are accesible to user of this DS

    bool isEmpty()
    {
        return ((minHeap.size() + maxHeap.size()) == 0) ? true : false;
    }

    int size()
    {
        return minHeap.size() + maxHeap.size();
    }

    void insert(int val)
    {
        if (minHeap.empty() && maxHeap.empty())
        {
            // both empty -> push to minHeap
            minHeapPush(minHeap, val);
        }
        else if ((!minHeap.empty()) && maxHeap.empty())
        {
            // minHeap not empty but maxHeap empty ...

            // If value is greater then top of minHeap
            if (val > minHeapTop(minHeap))
            {
                // push val in maxHeap
                maxHeapPush(maxHeap, val);
            }
            else
            {
                // remove an element from end of minHeap and push in maxHeap
                int removedElement = minHeap[minHeap.size() - 1];
                minHeap.pop_back();
                minHeapEnd--;

                maxHeapPush(maxHeap, removedElement);

                // now, push val into minHeap
                minHeapPush(minHeap, val);
            }
        }
        else if (minHeap.empty() && (!maxHeap.empty()))
        {
            // minHeap empty but maxHeap not empty ...
            if (val < maxHeapTop(maxHeap))
            {
                // push into minHeap
                minHeapPush(minHeap, val);
            }
            else
            {
                // remove the last element from maxHeap and push into minHeap
                int removedElement = maxHeap[maxHeap.size() - 1];
                maxHeap.pop_back();
                maxHeapEnd--;

                minHeapPush(minHeap, removedElement);

                // now push val into maxHeap
                maxHeapPush(maxHeap, val);
            }
        }
        else
        {
            // both not empty

            // get the sizes of minHeap and maxHeap
            int minHeapSize = minHeap.size();
            int maxHeapSize = maxHeap.size();

            // depending on relative sizes of minHeap and maxHeap and minHeapTop and maxHeapTop
            // push to minHeap or maxHeap

            if (maxHeapSize == minHeapSize)
            {
                // both heap same sized

                // check where val falls between minHeapTop and maxHeapTop
                if (val < minHeapTop(minHeap))
                {
                    // push into minHeap
                    minHeapPush(minHeap, val);
                }
                else if (val > maxHeapTop(maxHeap))
                {
                    // push into maxHeap
                    maxHeapPush(maxHeap, val);
                }
                else
                {
                    // in between -> can go anywhere
                    maxHeapPush(maxHeap, val);
                }
            }
            else if (maxHeapSize < minHeapSize)
            {
                // val is lesser than minHeapTop
                if (val < minHeapTop(minHeap))
                {
                    // remove last element from minHeap -> push that to maxHeap
                    int removedElement = minHeap[minHeap.size() - 1];
                    minHeapEnd--;
                    minHeap.pop_back();

                    maxHeapPush(maxHeap, removedElement);

                    // now we can push val to minHeap
                    minHeapPush(minHeap, val);
                }
                // val is in-between or greater then maxHeapTop
                else
                {
                    // we can safely push to maxHeap
                    maxHeapPush(maxHeap, val);
                }
            }
            else
            {
                // maxHeap is larger then minHeap

                // val is larger than maxHeap top
                if (val > maxHeapTop(maxHeap))
                {
                    // remove last element from maxHeap -> push to minHeap
                    int removedElement = maxHeap[maxHeap.size() - 1];
                    maxHeapEnd--;
                    maxHeap.pop_back();

                    minHeapPush(minHeap, removedElement);

                    // now we can safely push val to maxHeap
                    maxHeapPush(maxHeap, val);
                }
                // val is in-between or less than minHeapTop
                else
                {
                    // we can safely push to minHeap
                    minHeapPush(minHeap, val);
                }
            }
        }
    }

    int min()
    {
        // provided minHeap non-empty
        if (!minHeap.empty())
        {
            // return the current min in set
            return minHeapTop(minHeap);
        }
    }

    int max()
    {
        // Provided maxHeap not empty
        if (!maxHeap.empty())
        {
            // return the current max in set
            return maxHeapTop(maxHeap);
        }
    }

    vector<int> getMinMax()
    {
        vector<int> ans;

        // No element in set
        if (minHeap.size() + maxHeap.size() == 0)
        {
            return ans;
        }

        // There is just 1 element in set
        if (minHeap.size() + maxHeap.size() == 1)
        {
            // if minHeap empty fill with maxHeap element
            // if not empty fill with minHeap element
            int minAndMax = (minHeap.empty()) ? (maxHeapTop(maxHeap)) : (minHeapTop(minHeap));

            ans.push_back(minAndMax);
            return ans;
        }

        ans.push_back(minHeapTop(minHeap));
        ans.push_back(maxHeapTop(maxHeap));

        return ans;
    }

    // write the popMin and popMax functions ...
    void popMin()
    {

        // check the size diff between maxHeap and minHeap
        int minHeapSize = minHeap.size();
        int maxHeapSize = maxHeap.size();

        // minHeap larger / equal to maxHeap
        if (minHeapSize >= maxHeapSize)
        {
            // safely pop from minHeap
            minHeapPop(minHeap);
        }
        // minHeap smaller than maxHeap
        else
        {
            // remove last element from maxHeap -> push into minHeap
            int removedElement = maxHeap[maxHeap.size() - 1];
            maxHeapEnd--;

            maxHeap.pop_back();

            minHeapPush(minHeap, removedElement);

            // now safely pop top of minHeap
            minHeapPop(minHeap);
        }
    }

    void popMax()
    {

        // check the size diff between maxHeap and minHeap
        int minHeapSize = minHeap.size();
        int maxHeapSize = maxHeap.size();

        if (maxHeapSize >= minHeapSize)
        {

            // maxHeap larger than minHeap, safely pop from maxHeap
            maxHeapPop(maxHeap);
        }
        else
        {
            // maxHeap smaller than minHeap

            // remove last element from minHeap -> push to maxHeap
            int removedElement = minHeap[minHeap.size() - 1];
            minHeapEnd--;
            minHeap.pop_back();

            maxHeapPush(maxHeap, removedElement);

            // now, safely pop from maxHeap
            maxHeapPop(maxHeap);
        }
    }
};

int main()
{
    JointHeap jHeap;

    // bunch of inserts:
    jHeap.insert(10);
    jHeap.insert(1);
    jHeap.insert(100);
    jHeap.insert(5);
    jHeap.insert(20);
    jHeap.insert(15);

    cout << "Max right now : " << jHeap.max() << endl;
    cout << "Min right now : " << jHeap.min() << endl;

    // delete max
    jHeap.popMax();

    jHeap.insert(5);

    // delete min
    jHeap.popMin();

    // getting the current min max values
    vector<int> minMax = jHeap.getMinMax();

    // printing the min-max array:
    cout << "Min and Max currently : " << endl;

    for (auto value : minMax)
    {
        cout << value << " ";
    }
    cout << endl;

    return 0;
}