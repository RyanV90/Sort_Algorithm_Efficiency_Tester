#include <iostream>
#include <ctime>
#include <sstream>
#include <vector>
using namespace std;

//function receives a vector of integer type elements by reference call
//the function initializes the vector with random integers 0 - 499
void initializeList(vector<int>& l)
{
	srand(time(0));
	for (int i = 0; i < l.size(); i++)
		l[i] = (rand() % 500);
}

//function receives a vector of template type T
//and prints the elements of the vector
template<typename T>
void printVector(const vector<T>& l)
{
	for (int i = 0; i < l.size(); i++) // prints only the first 20 elements
		cout << l[i] << " ";
	cout << endl;
}

//========================Selection Sort===============================

//the function template selectionSort receives a vector of template type T 
//and sorts the vector.
template<typename T>
void selectionSort(vector<T>& l)
{

	for (int i = 0; i < l.size() - 1; i++)
	{
		int minIndex = i;
		for (int j = i + 1; j < l.size(); j++)
			if (l[minIndex] > l[j])
				minIndex = j;
		//swap elements in locations i and minIndex
		T temp = l[i];
		l[i] = l[minIndex];
		l[minIndex] = temp;
	}
}

//=========================== Insertion Sort ==========================

//Insertion sort receives a vector and implements the insertion sort algorithm
template<typename T>
void insertionSort(vector<T>& l)
{
	for (int i = 1; i < l.size(); i++)
	{
		int j = i;
		while (j > 0 && (l[j] < l[j - 1])) //insert the ith element into sorted list 
		{
			T temp = l[j];
			l[j] = l[j - 1];
			l[j - 1] = temp;
			j--; // move index j back
		}
	}
}

//==========================   Quicksort =====================

//partition functio is used by the quicksort
//the function receives a vector and the left and right index of the list as parameters
//partition uses the midpoint element as the pivot
template <typename T>
int partition(vector<T>& l, int i, int k)
{
	bool done = false;
	int midpoint = i + (k - i) / 2; //Pick middle value as pivot 
	T pivot = l[midpoint];
	int low = i;  // 
	int high = k;
	while (!done) {
		while (l[low] < pivot) ++low; /* Increment low while l[l] < pivot */
		while (pivot < l[high]) --high; /* Decrement high while pivot < l[h] */
		if (low >= high)
			done = true;
		else
		{
			T temp = l[low];
			l[low] = l[high];
			l[high] = temp;
			++low;   --high;
		}
	}
	return high;
}

//QuickSort function 
template <typename T>
void quicksort(vector<T>& l, int i, int k)
{
	int j = 0;
	if (i >= k)     //Base case
		return;
	j = partition(l, i, k);
	/* Recursively sort low and high partitions */
	quicksort(l, i, j);
	quicksort(l, j + 1, k);
}
//==============================  Shell Sort ===============
//function is utilized in shellsort
template <typename T>
void insertionSortInterleaved(vector<T>& l, int startIndex, int gap)
{
	int i = 0;
	int j = 0;
	int temp = 0;  // Temporary variable for swap
	for (i = startIndex + gap; i < l.size(); i = i + gap)
	{
		j = i;
		while (j - gap >= startIndex && l[j] < l[j - gap])
		{
			temp = l[j];
			l[j] = l[j - gap];
			l[j - gap] = temp;
			j = j - gap;
		}
	}
}

//ShellSort makes call to insertionSortInterleaved for each sublist
template <typename T>
void shellSort(vector<T>& l, int initialGapValue) {
	for (int gapValue = initialGapValue; gapValue >= 1; gapValue -= 3)
	{
		for (int i = 0; i < gapValue; i++)
			insertionSortInterleaved(l, i, gapValue);
	}
}

//=============================  Radix Sort =================
// Returns the length, in number of digits, of value
int RadixGetLength(int value)
{
	if (value == 0)
		return 1;
	int digits = 0;
	while (value != 0)
	{
		digits = digits + 1;
		value = value / 10;
	}
	return digits;
}

// Returns the maximum length, in number of digits, out of all elements in the array
int RadixGetMaxLength(vector<int> l)
{
	int maxDigits = 0;
	for (int i = 0; i < l.size(); i++)
	{
		int digitCount = RadixGetLength(l[i]);
		if (digitCount > maxDigits)
			maxDigits = digitCount;
	}
	return maxDigits;
}



void radixSort(vector<int>& l)
{

	// Find the max length, in number of digits
	int  maxDigits = RadixGetMaxLength(l);
	vector<vector<int> > buckets(10);
	// Start with the least significant digit
	int pow10 = 1;
	for (int digitIndex = 0; digitIndex < maxDigits; digitIndex++)
	{
		for (int i = 0; i < l.size(); i++)
		{
			int bucketIndex = abs(l[i] / pow10) % 10; // 654; 
			buckets[bucketIndex].push_back(l[i]);
		}
		int arrayIndex = 0;
		for (int i = 0; i < 10; i++)
		{
			for (int j = 0; j < buckets[i].size(); j++)
				l[arrayIndex++] = buckets[i][j];
		}
		pow10 = 10 * pow10;
		for (int i = 0; i < 10; i++)
			buckets[i].clear();
	}
}
//===========================  Merge Sort ===============

//The merge function merges a two sorted lists
template<typename T>
void merge(vector<T>& l, int i, int j, int k) {
	// Create temporary array mergedNumbers
	// Initialize position variables
	vector<T> mergedNumbers(k - i + 1);
	int leftPos = i;
	int rightPos = j + 1;
	// Add smallest element to merged numbers
	int mergePos = 0;
	while (leftPos <= j && rightPos <= k)
	{
		if (l[leftPos] <= l[rightPos])
		{
			mergedNumbers[mergePos] = l[leftPos];
			++leftPos;
		}
		else
		{
			mergedNumbers[mergePos] = l[rightPos];
			++rightPos;
		}
		++mergePos;
	}
	// If left partition not empty, add remaining elements
	while (leftPos <= j)
	{
		mergedNumbers[mergePos] = l[leftPos];
		++leftPos;
		++mergePos;
	}

	// If right partition not empty, add remaining elements
	while (rightPos <= k)
	{
		mergedNumbers[mergePos] = l[rightPos];
		++rightPos;
		++mergePos;
	}

	// Copy merge number back to numbers
	for (mergePos = 0; mergePos < mergedNumbers.size(); ++mergePos)
	{
		l[i + mergePos] = mergedNumbers[mergePos];
	}
}

//merge sort function
template<typename T>
void mergeSort(vector<T>& l, int i, int k)
{
	int j = 0;
	if (i < k)
	{
		j = (i + k) / 2;   // Find the midpoint in the partition
		// Recursively sort left and right partitions
		mergeSort(l, i, j);
		mergeSort(l, j + 1, k);
		// Merge left and right partition in sorted order
		merge(l, i, j, k);

	}
}

//Shows the before and after of each type of sort on a vector of size 20.
template<typename T>
void testSortFunctionsFunctionality(vector<T>& l) {

	//Selction Sort
	initializeList(l);
	cout << "Unsorted List: ";
	printVector(l);
	cout << "Sorted by selection sort: ";
	selectionSort(l);
	printVector(l);
	cout << endl;

	//Insertion Sort
	initializeList(l);
	cout << "Unsorted List: ";
	printVector(l);
	cout << "Sorted by insertion sort: ";
	insertionSort(l);
	printVector(l);
	cout << endl;

	//Quicksort
	initializeList(l);
	cout << "Unsorted List: ";
	printVector(l);
	cout << "Sorted by quicksort: ";
	quicksort(l, 0, l.size() - 1);
	printVector(l);
	cout << endl;

	//Shell Sort
	initializeList(l);
	int initialGapValue = pow(2, floor(log2(l.size())));
	cout << "Unsorted List: ";
	printVector(l);
	cout << "Sorted by shell sort: ";
	shellSort(l, initialGapValue);
	printVector(l);
	cout << endl;

	//Radix Sort
	initializeList(l);
	cout << "Unsorted List: ";
	printVector(l);
	cout << "Sorted by radix sort: ";
	radixSort(l);
	printVector(l);
	cout << endl;

	//Merge Sort
	initializeList(l);
	cout << "Unsorted List: ";
	printVector(l);
	cout << "Sorted by merge sort: ";
	mergeSort(l, 0, l.size() - 1);
	printVector(l);
	cout << endl;
}

//Shows the input size and number of seconds for each type of sort algorithm
template<typename T>
void testSortFunctionsEfficiency(vector<T>& l) {

	clock_t start, stop;
	
	//Selection Sort
	initializeList(l);
	start = clock();
	selectionSort(l);
	stop = clock() - start;
	printf("Sort Algorithm: Selection Sort | Input Size: %d | Time Taken: %f seconds", l.size(), (float)stop / CLOCKS_PER_SEC);
	cout << endl;

	//Insertion Sort
	initializeList(l);
	start = clock();
	insertionSort(l);
	stop = clock() - start;
	printf("Sort Algorithm: Insertion Sort | Input Size: %d | Time Taken: %f seconds", l.size(), (float)stop / CLOCKS_PER_SEC);
	cout << endl;

	//Quicksort
	initializeList(l);
	start = clock();
	quicksort(l, 0, l.size() - 1);
	stop = clock() - start;
	printf("Sort Algorithm: Quicksort | Input Size: %d | Time Taken: %f seconds", l.size(), (float)stop / CLOCKS_PER_SEC);
	cout << endl;

	//Radix Sort
	initializeList(l);
	start = clock();
	int initialGapValue = pow(2, floor(log2(l.size())));
	shellSort(l, initialGapValue);
	stop = clock() - start;
	printf("Sort Algorithm: Radix Sort | Input Size: %d | Time Taken: %f seconds", l.size(), (float)stop / CLOCKS_PER_SEC);
	cout << endl;

	//Shell Sort
	initializeList(l);
	start = clock();
	radixSort(l);
	stop = clock() - start;
	printf("Sort Algorithm: Shell Sort | Input Size: %d | Time Taken: %f seconds", l.size(), (float)stop / CLOCKS_PER_SEC);
	cout << endl;

	//Merge Sort
	initializeList(l);
	start = clock();
	mergeSort(l, 0, l.size() - 1);
	stop = clock() - start;
	printf("Sort Algorithm: Merge Sort | Input Size: %d | Time Taken: %f seconds", l.size(), (float)stop / CLOCKS_PER_SEC);
	cout << endl;

	cout << endl;
}

//Creates 9 vectors and tests the functionality and time efficiency of each sorting algorithm
int main()
{
	vector<int> v1(20); //Used to test sort algorithm functionality
	
	//Each vector below tests the time efficiency of each sort type with ascending input sizes.
	vector<int> v2(1000);
	vector<int> v3(10000);
	vector<int> v4(50000);
	vector<int> v5(100000);
	vector<int> v6(150000);
	vector<int> v7(200000);
	vector<int> v8(250000);
	vector<int> v9(300000);
	
	//Outputs the unsorted and sorted vector for each sort algorithm
	cout << "TESTING FUNCTIONALITY OF SORTS:" << endl;
	testSortFunctionsFunctionality(v1);
	cout << "___________________________________________________________________________________________________________________" << endl << endl;
	
	//Outputs the time efficiency of each sorting algorithm with ascending input sizes
	cout << "TESTING TIME EFFICIENCY OF SORTS:" << endl;
	testSortFunctionsEfficiency(v2);
	testSortFunctionsEfficiency(v3);
	testSortFunctionsEfficiency(v4);
	testSortFunctionsEfficiency(v5);
	testSortFunctionsEfficiency(v6);
	testSortFunctionsEfficiency(v7);
	testSortFunctionsEfficiency(v8);
	testSortFunctionsEfficiency(v9);
	
	return 0;
}