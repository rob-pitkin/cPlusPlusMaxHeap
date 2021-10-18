/* 
 * maxHeap.cpp
 * Class implementation for a basic C++ maxHeap
 * Author: Rob Pitkin, 2021
 * Implementation inspired by Introduction to Algorithms, Chapter 7
 */

#include "maxHeap.hpp"
#include <iostream>
#include <limits.h>

using namespace std;

MaxHeap::MaxHeap()
{
    heap = nullptr;
    length = heapSize = 0;
}

MaxHeap::MaxHeap(int size)
{
    heap = new int[2*size + 1];
    heap[0] = INT_MAX;
    length = size;
    heapSize = 0;
}

MaxHeap::~MaxHeap()
{
    delete heap;
}

void MaxHeap::insert(int elem)
{
    heapSize++;
    expand();
    heap[heapSize] = elem;
    int currIndex = heapSize;
    while (getParent(currIndex) <= heap[currIndex])
    {
        swap(currIndex, currIndex / 2);
        currIndex = currIndex / 2;
    }
}

void MaxHeap::buildHeap(int arr[], int length)
{
    heap = arr;
    heapSize = length;
    for (int i = length/2; i > 0; i--)
    {
        heapify(i);
    }
}

void MaxHeap::heapSort(int arr[], int length)
{
    buildHeap(arr, length);
    for (int i = length; i > 1; i--)
    {
        swap(1, i);
        heapSize--;
        heapify(1);
    }
}

int MaxHeap::extractMax()
{
    heapSize--;
    return -1;
}

void MaxHeap::printHeap()
{
    for (int i = 1; i < heapSize + 1; i++)
    {
        cout << heap[i] << endl;
    }
}

/*---------------------------------------------------------------------------*/

void MaxHeap::heapify(int index)
{
    if (index < 1 || index > heapSize)
    {
        cerr << "ERROR: Index out of range" << endl;
        return;
    }
    int largest = index;
    int left = index * 2;
    int right = index * 2 + 1;
    if (left <= heapSize && heap[left] > heap[index])
    {
        largest = left;
    }
    if (right <= heapSize && heap[right] > heap[largest])
    {
        largest = right;
    }
    if (largest != index)
    {
        swap(index, largest);
        heapify(largest);
    }
}

void MaxHeap::expand()
{
    int* newHeap;
    if (heapSize == length - 1)
    {
        newHeap = new int[2 * length + 1];
        for (int i = 0; i < heapSize; i++)
        {
            newHeap[i] = heap[i];
        }
        delete heap;
        heap = newHeap;
        length = 2 * length + 1;
    }
}

void MaxHeap::shrink()
{
    int* newHeap;
    if (heapSize < length / 2)
    {
        newHeap = new int[length/2];
        for (int i = 0; i < heapSize; i++)
        {
            newHeap[i] = heap[i];
        }
        delete heap;
        heap = newHeap;
        length /= 2;
    }
}

void MaxHeap::swap(int indexA, int indexB)
{
    if (indexA < 0 || indexB < 0 || indexA > heapSize + 1 || indexB > heapSize + 1)
    {
        cerr << "ERROR: Index out of range." << endl;
        return;
    }
    int temp = heap[indexA];
    heap[indexA] = heap[indexB];
    heap[indexB] = temp;
}

int MaxHeap::getParent(int index)
{
    if (index == 1)
    {
        return INT_MAX;
    }
    return heap[index/2];
}

int MaxHeap::getLeftChild(int index)
{
    if (index * 2 > heapSize)
    {
        cerr << "There is no left child.";
        return -1;
    }
    return heap[index * 2];
}

int MaxHeap::getRightChild(int index)
{
    if (index * 2 + 1 > heapSize)
    {
        cerr << "There is no right child.";
        return -1;
    }
    return heap[index * 2 + 1];
}
