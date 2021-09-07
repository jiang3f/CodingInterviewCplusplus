/*
*  https://www.geeksforgeeks.org/binary-heap/
*/

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

namespace BinaryHeap
{
    // Prototype of a utility function to swap two integers
    void swap(int* x, int* y)
    {
        int tmp = *x;
        *x = *y;
        *y = tmp;
    }

    class MinHeap
    {
        int* harr; // pointer to array of elements in heap
        int capacity; // maximum possible size of min heap
        int heap_size; // Current number of elements in min heap
    public:
        // Constructor
        MinHeap(int capacity);

        // to heapify a subtree with the root at given index
        void MinHeapify(int);

        int parent(int i) { return (i - 1) / 2; }

        // to get index of left child of node at index i
        int left(int i) { return (2 * i + 1); }

        // to get index of right child of node at index i
        int right(int i) { return (2 * i + 2); }

        // to extract the root which is the minimum element
        int extractMin();

        // Decreases key value of key at index i to new_val
        void decreaseKey(int i, int new_val);

        // Returns the minimum key (key at root) from min heap
        int getMin() { return harr[0]; }

        // Deletes a key stored at index i
        void deleteKey(int i);

        // Inserts a new key 'k'
        void insertKey(int k);

    };

    MinHeap::MinHeap(int capacity)
    {
        harr = new int[capacity];
        this->capacity = capacity;
    }

    // to heapify a subtree with the root at given index
    void MinHeap::MinHeapify(int i)
    {
        int left = this->left(i);
        int right = this->right(i);
        int smallest = i;

        if (left < heap_size && harr[left] < harr[smallest])
        {
            smallest = left;
        }

        if (right < heap_size && harr[right] < harr[smallest])
        {
            smallest = right;
        }

        if (smallest != i)
        {
            swap(&harr[i], &harr[smallest]);
            MinHeapify(smallest);
        }

    }

    void MinHeap::insertKey(int k)
    {
        if (capacity == heap_size)  return;

        harr[heap_size] = k;

        int i = heap_size;

        while (i > 0 && harr[i] < harr[parent(i)])
        {
            swap(&harr[i], &harr[parent(i)]);

            i = parent(i);
        }

        heap_size++;

        
    }

    // Decreases key value of key at index i to new_val
    void MinHeap::decreaseKey(int i, int new_val)
    {
        harr[i] = new_val;

        while (i > 0 && harr[i] > harr[parent(i)])
        {
            swap(&harr[i], &harr[parent(i)]);
            i = parent(i);
        }
    }

    // to extract the root which is the minimum element
    int MinHeap::extractMin()
    {
        if (heap_size <= 0) return INT_MAX;

        if (heap_size == 1)
        {
            heap_size = 0;
            return harr[0];
        }

        int root = harr[0];

        harr[0] = harr[heap_size-1];

        heap_size--;

        this->MinHeapify(0);

        return root;
    }

    // Deletes a key stored at index i
    void MinHeap::deleteKey(int i)
    {
        harr[i] = harr[heap_size - 1];

        heap_size--;

        MinHeapify(i);

    }

};

int BinaryHeap_Test()
{
    BinaryHeap::MinHeap h(11);

    h.insertKey(3);
    h.insertKey(2);
    h.deleteKey(1);
    h.insertKey(15);
    h.insertKey(5);
    h.insertKey(4);
    h.insertKey(45);
    cout << h.extractMin() << " ";
    cout << h.getMin() << " ";
    h.decreaseKey(2, 1);
    cout << h.getMin();

    return 0;
}
