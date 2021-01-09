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
#include <vector>
#include <ctime>
#include <sstream>

using namespace std;

/* intializeIntegerVector()
* 
* Takes an integer vector and adds requested number of random integers to the vector
*/

void intializeIntegerVector(vector<int>& vector, int requestedSizeOfVector) {
	
	srand(time(0)); // Generates new seed for rand()
	
	// Adds random integer to the vector
	while (vector.size() < requestedSizeOfVector)
	{
		vector.push_back(rand() % 100);
	}
}

/* printVector()
* 
* Prints all indexes of vector
*/

void printVector(const vector<int>& vector) {
	
	// Prints each value in the vector
	for (const int& number : vector)
	{
		cout << number << " ";
	}
	cout << endl;
}

/* main() 
* 
* 
*/

int main() {

	//Vector to be used in sorting algorithms
	vector<int> numbers;
	//Initializes vector of requested size with random integers
	intializeIntegerVector(numbers, 5);
	//Print unsorted vector
	cout << "Unsorted vector: ";
	printVector(numbers);

	//Sort vector by insertion sort algorithm
	InsertionSort insertionSort(numbers);
	//Print sorted vector
	cout << "Vector sorted by insertion sort: ";
	printVector(numbers);

	return 0;
}