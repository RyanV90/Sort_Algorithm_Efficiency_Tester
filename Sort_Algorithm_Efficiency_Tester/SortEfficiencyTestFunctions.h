#include <vector>
#include <ctime>
#include <sstream>
#include <iostream>

using namespace std;

class SortEfficiencyTestFunctions
{
public:
	SortEfficiencyTestFunctions(vector<int>& vect, int requestedSizeOfVector);
	void printVector(vector<int>& vect) const;

private:
	void intializeIntegerVector(vector<int>& vect, int requestedSizeOfVector);
};

