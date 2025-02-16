﻿// C++ program to demonstrate all operations of
// k-ary Heap
#include <iostream>



using namespace std;

// function to heapify (or restore the max- heap
// property). This is used to build a k-ary heap
// and in extractMin()
// att[] -- Array that stores heap
// len -- Size of array
// index -- index of element to be restored
//		 (or heapified)
void restoreDown(int arr[], int len, int index,int k)
{
	// child array to store indexes of all
	// the children of given node
	int* child=new int[k + 1];

	while (1)
	{
		// child[i]=-1 if the node is a leaf
		// children (no children)
		for (int i = 1; i <= k; i++)
			child[i] = ((k * index + i) < len) ?
			(k * index + i) : -1;

		// max_child stores the maximum child and
		// max_child_index holds its index
		int max_child = -1, max_child_index;

		// loop to find the maximum of all
		// the children of a given node
		for (int i = 1; i <= k; i++)
		{
			if (child[i] != -1 &&
				arr[child[i]] < max_child)  //////
			{
				max_child_index = child[i];
				max_child = arr[child[i]];
			}
		}

		// leaf node
		if (max_child == -1)
			break;

		// swap only if the key of max_child_index
		// is greater than the key of node
		if (arr[index] > arr[max_child_index]) ///////
			swap(arr[index], arr[max_child_index]);

		index = max_child_index;
	}
}

// Restores a given node up in the heap. This is used
// in decreaseKey() and insert()
void restoreUp(int arr[], int index, int k)
{
	// parent stores the index of the parent variable
	// of the node
	int parent = (index - 1) / k;

	// Loop should only run till root node in case the
	// element inserted is the maximum restore up will
	// send it to the root node
	while (parent >= 0)
	{
		if (arr[index] < arr[parent])  /////
		{
			swap(arr[index], arr[parent]);
			index = parent;
			parent = (index - 1) / k;
		}

		// node has been restored at the correct position
		else
			break;
	}
}

// Function to build a heap of arr[0..n-1] and value of k.
void buildHeap(int arr[], int n, int k)
{
	// Heapify all internal nodes starting from last
	// non-leaf node all the way upto the root node
	// and calling restore down on each
	for (int i = (n - 1) / k; i >= 0; i--)
		restoreDown(arr, n, i, k);
}

// Function to insert a value in a heap. Parameters are
// the array, size of heap, value k and the element to
// be inserted
void insert(int arr[], int* n, int k, int elem)
{
	// Put the new element in the last position
	arr[*n] = elem;

	// Increase heap size by 1
	*n = *n + 1;

	// Call restoreUp on the last index
	restoreUp(arr, *n - 1, k);
}

// Function that returns the key of root node of
// the heap and then restores the heap property
// of the remaining nodes
int extractMax(int arr[], int* n, int k)
{
	// Stores the key of root node to be returned
	int max = arr[0];

	// Copy the last node's key to the root node
	arr[0] = arr[*n - 1];

	// Decrease heap size by 1
	*n = *n - 1;

	// Call restoreDown on the root node to restore
	// it to the correct position in the heap
	restoreDown(arr, *n, 0, k);

	return max;
}

// Driver program
int main()
{
	const int capacity = 100;
	int arr[capacity] = { 4, 5, 6, 7, 8, 9, 10 };
	int n = 7;
	int k = 3;

	buildHeap(arr, n, k);

	printf("Built Heap : \n");
	for (int i = 0; i < n; i++)
		printf("%d ", arr[i]);

	int element = 3;
	insert(arr, &n, k, element);

	printf("\n\nHeap after insertion of %d: \n",
		element);
	for (int i = 0; i < n; i++)
		printf("%d ", arr[i]);

	printf("\n\nExtracted max is %d",
		extractMax(arr, &n, k));

	printf("\n\nHeap after extract max: \n");
	for (int i = 0; i < n; i++)
		printf("%d ", arr[i]);

	int* niz2 = new int[n];
	for (int i = 0; i < n; i++)
	{
		niz2[i] = arr[i];
	}

	buildHeap(niz2, n, k);

	cout << endl << endl;
	printf("Niz2 heap : \n");
	for (int i = 0; i < n; i++)
		printf("%d ", niz2[i]);
	
	printf("\n\nExtracted max is %d",
		extractMax(niz2, &n, k));

	printf("\n\nHeap after extract max: \n");
	for (int i = 0; i < n; i++)
		printf("%d ", niz2[i]);

	printf("\n\nExtracted max is %d",
		extractMax(niz2, &n, k));

	printf("\n\nHeap after extract max: \n");
	for (int i = 0; i < n; i++)
		printf("%d ", niz2[i]);

	return 0;
}
