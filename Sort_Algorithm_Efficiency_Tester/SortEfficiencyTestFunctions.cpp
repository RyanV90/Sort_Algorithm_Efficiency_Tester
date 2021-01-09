#include "SortEfficiencyTestFunctions.h"

SortEfficiencyTestFunctions::SortEfficiencyTestFunctions(vector<int>& vect, int requestedSizeOfVector)
{
	intializeIntegerVector(vect, requestedSizeOfVector);	
}

/* intializeIntegerVector()
*
* Takes an integer vector and adds requested number of random integers to the vector
*/

void SortEfficiencyTestFunctions::intializeIntegerVector(vector<int>& vect, int requestedSizeOfVector) {

	srand(time(0)); // Generates new seed for rand()

	// Adds random integer to the vector
	while (vect.size() < requestedSizeOfVector)
	{
		vect.push_back(rand() % 100);
	}
}

/* printVector()
*
* Prints all indexes of vector
*/

void SortEfficiencyTestFunctions::printVector(vector<int>& vect) const {

	// Prints each value in the vector
	for (int number : vect)
	{
		cout << number << " ";
	}
	cout << endl;
}
