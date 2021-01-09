#include "SortEfficiencyTestFunctions.h"
#include "BubbleSort.h"
#include "BucketSort.h"
#include "HeapSort.h"
#include "InsertionSort.h"
#include "MergeSort.h"
#include "QuickSort.h"
#include "RadixSort.h"
#include "SelectionSort.h"
#include "ShellSort.h"
#include <iostream>

using namespace std;

/* main() 
* 
* 
*/

int main() {

	//Vector to be used in sorting algorithms
	vector<int> vector;

	SortEfficiencyTestFunctions sortTester(vector, 10);
	//Initializes vector of requested size with random integers
	//Print unsorted vector
	cout << "Unsorted vector: ";
	sortTester.printVector(vector);

	//Sort vector by insertion sort algorithm
	//InsertionSort insertionSort(numbers);
	//Print sorted vector
	//cout << "Vector sorted by insertion sort: ";
	//printVector(numbers);

	return 0;
}