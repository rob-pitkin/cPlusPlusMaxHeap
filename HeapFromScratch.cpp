/* 
 * MaxHeap in C++ test driver code
 * Author: Rob Pitkin, 2021
 */

#include <iostream>
#include <math.h>
#include "maxHeap.hpp"

using namespace std;

int main(int argc, char const *argv[]) {
    // Basic heap insert test
    MaxHeap h(6);
    h.insert(1);
    h.insert(2);
    h.insert(3);
    h.insert(4);
    h.insert(5);
    h.insert(6);
    h.printHeap();
    cout << endl;
    
    // Basic buildHeap test
    int* arr = new int[7];
    for (int i = 1; i < 7; i++)
    {
        arr[i] = i;
    }
    MaxHeap j(6);
    j.buildHeap(arr, 6);
    j.printHeap();
    cout << endl;
    
    // Basic HeapSort test
    int* arr2 = new int[7];
    for (int i = 1; i < 7; i++)
    {
        arr2[i] = i*11;
    }
    MaxHeap k(6);
    k.heapSort(arr2, 6);
    for (int i = 1; i < 7; i++)
    {
        cout << "Sorted at " << i << ": " << arr2[i] << endl;
    }
    return 0;
}