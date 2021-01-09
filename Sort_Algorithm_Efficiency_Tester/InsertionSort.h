#include <iostream>
#include <vector>

using namespace std;

class InsertionSort {

public:

	/* InsertionSort()
	* 
	* Sorts a vector of type T by the insertion sort algorithm
	*/
	
	InsertionSort(vector<int>& vector) {

		// Loops through each index of the vector
		for (int i = 1; i < vector.size(); i++)
		{
			int j = i;
			// Swaps values j and j-1 if j is less than j-1
			while (j > 0 && (vector[j] < vector[j - 1]))
			{
				int temp = vector[j];
				vector[j] = vector[j - 1];
				vector[j - 1] = temp;
				j--; // move index j back 1 index
			}
		}
	}
};