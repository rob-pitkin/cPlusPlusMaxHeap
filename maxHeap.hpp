/* 
 * maxHeap.hpp
 * Class definition for a basic C++ maxHeap
 * Author: Rob Pitkin, 2021
 */

#ifndef MAXHEAP_H_
#define MAXHEAP_H_

class MaxHeap
{
public:
    MaxHeap();
    MaxHeap(int size);
    ~MaxHeap();
    void insert(int elem);
    void buildHeap(int arr[], int length);
    void heapSort(int arr[], int length);
    int extractMax();
    void printHeap();
private:
    int* heap;
    int heapSize;
    int length;
    
    void heapify(int index);
    void expand();
    void shrink();
    void swap(int indexA, int indexB);
    int getParent(int index);
    int getLeftChild(int index);
    int getRightChild(int index);
};

#endif