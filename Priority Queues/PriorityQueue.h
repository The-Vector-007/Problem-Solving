#include<vector>

class PriorityQueue{ // it will be a min heap priority queue of integers
    vector<int> pq;

    public:
    
    PriorityQueue(){

    }

    bool isEmpty(){
        return pq.size() == 0;
    }

    int getSize(){
        return pq.size();
    }

    int getMin(){
        if( isEmpty() ){
            return 0;       //0 representing that our priority queue is empty
        }
        return pq[0];
    }

    void insert( int element ){
        pq.push_back(element);

        int childIndex = pq.size() - 1;

        while( childIndex > 0 ){
            int parentIndex = ( childIndex - 1 )/2;

            if( pq[childIndex] < pq[parentIndex] ){
                int temp = pq[childIndex];
                pq[childIndex] = pq[parentIndex];
                pq[parentIndex] = temp;
            }
            else{
                break;
            }
            childIndex = parentIndex;
        }
    }

    int removeMin(){
        if( isEmpty() ){
            return 0;       // priority queue has no elements
        }

        int ans = pq[0];    // deleted element to be returned
        pq[0] = pq[ pq.size() - 1 ];    // swapping with the last element 
        pq.pop_back();   // element removed

        int parentIndex = 0;

        int leftChildIndex = 2 * parentIndex + 1;
        int rightChildIndex = 2 * parentIndex + 2;
 
        while( leftChildIndex < pq.size() ){ // if left index is out of bounds then it is a leaf node
            int minIndex = parentIndex;

            if( pq[minIndex] > pq[leftChildIndex] ){ //it is confirm that left index is within bounds
                minIndex = leftChildIndex;
            }
            if( rightChildIndex < pq.size() && pq[minIndex] > pq[rightChildIndex] ){ // it is not confirm that rightIndex 
                minIndex = rightChildIndex;                                          //is within bounds so we have to check.
            }
            if( minIndex == parentIndex ){  // if minIndex  doesn't changes then it means element has reached
                break;                      // it's correct position
            }
            int temp = pq[minIndex];
            pq[minIndex] = pq[parentIndex];
            pq[parentIndex] = temp;

            parentIndex = minIndex;
            leftChildIndex = 2 * parentIndex + 1;
            rightChildIndex = 2 * parentIndex + 2;
        } 

        return ans;
    }
};